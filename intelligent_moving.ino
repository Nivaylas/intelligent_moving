#define QTI1 12
#define QTI2 11
#define QTI3 6
#define QTI4 10
#define LMOTOR 9
#define RMOTOR 5

const int TARGET = {1, 2, 3, 4, 5};
int shuffled = {2, 4, 5, 1, 3};

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

//右转45°
void turn_right_45(){
    Turn(1550, 1550, 27);
}

//右转90°
void turn_right_90(){
    Turn(1550, 1550, 55);
}

//左转90°
void turn_left_90(){
    Turn(1450, 1450, 55);
}

//左转135°
void turn_left_135(){
    Turn(1430, 1430, 67);
}

//掉头
void turn_back(void){
    Turn(1430, 1430, 70);
}

//QTI 默认前进，参数为 -1 时倒退
void QTI(int Reverse = 1){
    QTIState = digitalRead(QTI1) * 8 +
               digitalRead(QTI2) * 4 +
               digitalRead(QTI3) * 2 +
               digitalRead(QTI4);//查询qti传感器状态
    //Serial.println((int)QTIState)
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

void move(int goal){
    switch (goal)
    {
    case 1:
        move_A();
    break;
    case 2:
        move_B();
    break;
    case 3:
        move_C();
    break;
    case 4:
        move_D();
    break;
    case 5:
        move_E();
    break;
}


void move_A(){
    turn_left_90();//左转90度
    leftDetect();
    //Forward(8);//前进一点，补偿
    while(QTIState != 0){//检测是否到白点，取到色块
        QTI();
    }
    frontServo(1);//前伺服夹住
    switch(shuffled[1]){
    case 1://A点放置色块为黄色
        Forward(7);//盲走一小段距离，QTI越过白圈
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
        turn_right_90();//右转90度
        rightDetect();//右转检测函数，保证中间QTI至少有一个在直线上
        delay(1000);
        buttOccupied = false;//屁股没色块
        move_B();
        break;
    case 2://A点放置色块为白色
        while(QTIState != 15)//检测是否到中心点
            QTI(-1);
        Forward(15); //补偿
        turn_left_135();//屁股对着挡住路的色块
        leftDetect();
        while(QTIState != 0)//检测是否到白点
            QTI(-1);
        backServo(1);//后伺服夹住
        turn_back();//要放的色块转向前
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
        turn_right_45(); //向右旋转 45°
        rightDetect();
        buttOccupied = true;//屁股有色块
        move(shuffled[2]);
        break;
    case 3://A点放置色块为红色
        while(QTIState != 15)//检测是否到中心点
            QTI(-1);
        Forward(15); //补偿
        turn_left_90();//屁股对着挡住路的色块
        leftDetect();
        while(QTIState != 0)//检测是否到白点
            QTI(-1);
        backServo(1);//后伺服夹住
        turn_back();//要放的色块转向前
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
        while(QTIState != 15)//检测是否到中心点
            QTI(-1);
        Forward(15); //补偿
        turn_left_45();//屁股对着挡住路的色块
        leftDetect();
        while(QTIState != 0)//检测是否到白点
            QTI(-1);
        backServo(1);//后伺服夹住
        turn_back();//要放的色块转向前
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
        turn_left_45(); //向右旋转 45°
        leftDetect();
        buttOccupied = true;//屁股有色块
        move(shuffled[4]);
        break;
    case 5://A点放置色块位紫色
        while(QTIState != 0)//检测是否到白点
            QTI(-1);
        while(QTIState != 15)//检测是否到中心点
            QTI(-1);
        Back(7);//盲退一小段距离，QTI越过白圈
        backServo(1);//后伺服夹住
        turn_back();//要放的色块转向前
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
        turn_left_90();//右转90度
        leftDetect();//右转检测函数，保证中间QTI至少有一个在直线上
        delay(1000);
        buttOccupied = true;//屁股有色块
        move_B();
        break;
    case 6:                 //对应颜色物块路线上有物块放置，将A点色块搬运至起始直线上
            turn_back();
            zzjiance();
            while(qtis!=15)  //检测是否到中心点
            {qti();}
            fastForward(10); 
            turn_right_90();
            yzjiance();
            for(i=0;i<80;i++)       
            {qti();}
            line++;
            back(20);
            turn_back();
            zzjiance();
            while(qtis!=15)  //检测是否到中心点
            {qti();}
            fastForward(10);
        break;      
    }
 }
