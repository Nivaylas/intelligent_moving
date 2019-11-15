#define QTI1 12
#define QTI2 11
#define QTI3 6
#define QTI4 10
#define LMOTOR 9
#define RMOTOR 5

const int TARGET[5] = {0, 1, 2, 3, 4, 5};
int shuffled[5] = {0, 2, 4, 5, 1, 3};

int QTIState;

void Turn(int left, int right, int a){
    for(int i = 1; i <= a; i++){
        digitalWrite(LMOTOR, HIGH);
        delayMicroseconds(left);
        digitalWrite(LMOTOR, LOW);
        digitalWrite(RMOTOR, HIGH);
        delayMicroseconds(right);
        digitalWrite(RMOTOR, LOW);
        delay(20);
    }
}

//前进函数
void Forward(int a){
    Turn(1400, 1600, a);
}

//后退函数
void Back(int a){
    Turn(1600, 1400, a);
}

void turn_degree(int deg){
    switch (deg){
        //right
        case -90:
            Turn(1550, 1550, 55);//右转90°
        break;
        case -45: 
            Turn(1550, 1550, 27);//右转45°
        break;
        //left
        case 90:
            Turn(1450, 1450, 55);//左转90°
        break;
        case 135: 
            Turn(1430, 1430, 67);//左转135°
        break;
        case 180:
            Turn(1430, 1430, 70);//掉头
        break;
    } 
}

//QTI 默认前进，参数为 -1 时倒退
void QTI(int Reverse = 1){
    QTIState = digitalRead(QTI1) * 8 +
               digitalRead(QTI2) * 4 +
               digitalRead(QTI3) * 2 +
               digitalRead(QTI4);//查询qti传感器状态
    Serial.println((int)QTIState)
    if(Reverse == 1)
        switch(QTIState){//选择qti传感器状态
        case 1:
            Turn(1650, 1600);//向右转
            break;
        case 3:
            Turn(1510, 1550);//小幅向右转
            break;
        case 8:
            Turn(1400,1450);//向左转
            break;
        case 12:
            Turn(1450,1490);//小幅向左转
            break;
        case 15:
            Forward(1);//前进2小步
            break;
        }
    else
        switch(QTIState){//选择qti传感器状态
        case 1:
            Turn(1400,1450);//向右转
            break;
        case 3:
            Turn(1450,1490);//小幅向右转
            break;
        case 8:
            Turn(1650, 1600);//向左转
            break;
        case 12:
            Turn(1510, 1550);//小幅向左转
            break;
        case 15:
            Back(1);//后2小步
            break;
        }


    
    
    
}

//检测中间两个QTI是否有在直线上
bool Detect(){
    QTIState = digitalRead(qti2) * 4 +
               digitalRead(qti3) * 2;//查询qti传感器状态
    if(QTIState == 2 || QTIState == 4 || QTIState == 6)
        return false;
    else
        return true;
}

//左转检测函数，保证中间QTI至少有一个在直线上
void leftDetect(){
    int swch;
    swch = Detect();
    while(swch){
        swch = Detect();
        Turn(1450,1450); 
    }
}

void rightDetect(void)//左转检测函数，保证中间QTI至少有一个在直线上
{
    int swch;
    swch = Detect();
    while(swch){
        swch = Detect();
        Turn(1550, 1550); 
    }
}

void startToCenter(){
    Forward(60);
    while (QTIState != 15)
        QTI();
    Forward(10);//前进一点，补偿
}

void setup(){
    pinMode(QTI1, INPUT);
    pinMode(QTI2, INPUT);
    pinMode(QTI3, INPUT);
    pinMode(QTI4, INPUT);
    pinMode(LMOTOR, OUTPUT);
    pinMode(RMOTOR, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    /*
    调试步骤：
    1：调零
    2：校正角度
    */
    startToCenter();
    move(1);
    /*delay(1000);
    move_B();
    delay(1000);
    move_C();
    delay(1000);
    move_D();
    delay(1000);
    move_E();
    delay(1000);
    */
}

int turn_list = {0,
90, 45, 0, -45, -90}

/*
1-yellow
2-white
3-red
4-black
5-blue
*/

void move(int goal){
    turn_left(first_turn[goal]);//转向目标
    if(goal <= 2)
        leftDetect();
    if(goal >= 4)
        rightDetect();
    //Forward(8);//前进一点，补偿
    while(QTIState != 0){//检测是否到白点，取到色块
        QTI();
    }
    if(shuffled[goal] != goal){//除了该点放置色块为该路径终点要放置的块之外需倒回中心点
        frontServo(1);//前伺服夹住
        while(QTIState != 15)//检测是否到中心点
            QTI(-1);
        Forward(15); //补偿
    }
    else{
        Forward(7);//盲走一小段距离，QTI越过白圈
        for(int i = 1; i <= 68; i++)//循线，将物块推至得分点       
            QTI();
        Back(20);//后退一段，将车身前面的叉子抽出，避免碰到色块
        //返回
        while(QTIState != 0)//检测是否到白点
            QTI(-1);
        while(QTIState != 15)//检测是否到中心点
            QTI(-1);
    }
    switch(shuffled[goal]){
        case 1://该点放置色块为黄色
            if(goal == 1)
                break;
            
            Forward(15);//盲走前进一小段，车身居中
            turn_right(90);//右转90度
            rightDetect();//右转检测函数，保证中间QTI至少有一个在直线上
            delay(1000);
            buttOccupied = false;//屁股没色块
            move_B();
            break;
        case 2://A点放置色块为白色
            if(goal == 2)
                break;
            turn_left(135);//屁股对着挡住路的色块
            leftDetect();
            while(QTIState != 0)//检测是否到白点
                QTI(-1);
            backServo(1);//后伺服夹住
            turn_left(180);//掉头，要放的色块转向前
            for(int i = 1; i <= 68; i++)//循线，将物块推至得分点       
                QTI();
            frontServo(0);//前伺服松开
            back(20);//后退一段，将车身前面的叉子抽出，避免碰到色块  
            //返回
            while(QTIState != 0)//检测是否到白点
                QTI(-1);
            while(QTIState != 15)//检测是否到中心点
                QTI(-1);
            Forward(15);//盲走前进一小段，车身居中
            turn_right(45); //向右旋转 45°
            rightDetect();
            buttOccupied = true;//屁股有色块
            move(shuffled[2]);
            break;
        case 3://A点放置色块为红色
            if(goal == 3)
                break;
            turn_left(90);//屁股对着挡住路的色块
            leftDetect();
            while(QTIState != 0)//检测是否到白点
                QTI(-1);
            backServo(1);//后伺服夹住
            turn_left(180);//要放的色块转向前
            for(int i = 1; i <= 68; i++)//循线，将物块推至得分点       
                QTI();
            frontServo(0);//前伺服松开
            back(20);//后退一段，将车身前面的叉子抽出，避免碰到色块  
            //返回
            while(QTIState != 0)//检测是否到白点
                QTI(-1);
            while(QTIState != 15)//检测是否到中心点
                QTI(-1);
            Forward(15);//盲走前进一小段，车身居中
            buttOccupied = true;//屁股有色块
            move(shuffled[3]);
            break;
        case 4://A点放置色块为黑色
            if(goal == 4)
                break;
            
            buttOccupied = true;//屁股有色块
            move(shuffled[4]);
            break;
        case 5://A点放置色块位紫色
            if(goal == 5)
                break;
            Back(7);//盲退一小段距离，QTI越过白圈
            backServo(1);//后伺服夹住
            turn_left(180);//要放的色块转向前
            for(int i = 1; i <= 68; i++)//循线，将物块推至得分点       
                QTI();
            frontServo(0);//前伺服松开
            Back(20);//后退一段，将车身前面的叉子抽出，避免碰到色块
            //返回
            while(QTIState != 0)//检测是否到白点
                QTI(-1);
            while(QTIState != 15)//检测是否到中心点
                QTI(-1);
            Forward(15);//盲走前进一小段，车身居中
            turn_left(90);//右转90度
            leftDetect();//右转检测函数，保证中间QTI至少有一个在直线上
            delay(1000);
            buttOccupied = true;//屁股有色块
            move(shuffled[5]);
            break;
    }
 }


void move_new(int goal){
    turn_left();//屁股对着挡住路的色块
    leftDetect();
    while(QTIState != 0)//检测是否到白点
        QTI(-1);
    backServo(1);//后伺服夹住
    turn_left(180);//要放的色块转向前
    for(int i = 1; i <= 68; i++)//循线，将物块推至得分点       
        QTI();
    frontServo(0);//前伺服松开
    back(20);//后退一段，将车身前面的叉子抽出，避免碰到色块  
    //返回
    while(QTIState != 0)//检测是否到白点
        QTI(-1);
    while(QTIState != 15)//检测是否到中心点
        QTI(-1);
    Forward(15);//盲走前进一小段，车身居中
    turn_left(45); //向右旋转 45°
    leftDetect();
}
