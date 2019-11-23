const int QTI1 = 12;
const int QTI2 = 11;
const int QTI3 = 6;
const int QTI4 = 4;

const int BACKSERVO = 9;
const int FRONTSERVO = 5;

const int LMOTOR = 10;
const int RMOTOR = 8;
const int TSPDL = 3;
const int TSPDR = 7;

const int shuffled[6] = {0,
 2, 4, 5, 1, 3};

int turn_backward_list[6] = {0, -90, -135, 180, 135, 90};

int QTIState;
void rightDetect();
void leftDetect();


//void test_speed();


void frontServo(bool Stat){
    digitalWrite(FRONTSERVO, HIGH);
    if(Stat)
        delayMicroseconds(1000);//1-夹住
    else
        delayMicroseconds(2000);//0-松开
    digitalWrite(FRONTSERVO, LOW);
    delay(20);
}

void backServo(bool Stat){
    digitalWrite(BACKSERVO, HIGH);
    if(Stat)
        delayMicroseconds(1000);//1-夹住
    else
        delayMicroseconds(2000);//0-松开
    digitalWrite(BACKSERVO, LOW);
    delay(20);
}

void Turn(int left, int right, int a = 2){
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

long countL = 0; //光电门计数
long countR = 0;

void Forward_mm(int a){
    ountMAX = a / 11;
    while((countL >= countMAX) && (countR >= countMAX)){
        char status1 = digitalRead(TSPD1);//光电门记录状态
        char status2 = digitalRead(TSPD2);
        char status_n1 = digitalRead(TSPD1);//光电门即时状态
        char status_n2 = digitalRead(TSPD2);
        if (status1 != status_n1){
            status1 = status_n1;
            countL++;
        }
        if (status2 != status_n2){
            status2 = status_n2;
            countR++;
        }
        if(countL < countMAX){
            digitalWrite(LMOTOR, HIGH);
            delayMicroseconds(1800);
            digitalWrite(LMOTOR, LOW);        
        }
        if(countR < countMAX){
            digitalWrite(RMOTOR, HIGH);
            delayMicroseconds(1800);
            digitalWrite(RMOTOR, LOW);        
        }
    }
    c
    
}

//前进函数
void Forward(int a){
    Turn(1400, 1600, a);
}

//后退函数
void Back(int a){
    Turn(1600, 1400, a);
}

//集成detect的旋转函数
void turn_degree(int deg){
    switch (deg){
        //right
        case -180:
            Turn(1550, 1550, 70);//逆时针掉头
            rightDetect();
        break;
        case -135:
            Turn(1550, 1550, 60);//右转135°
            rightDetect();
        break;
        case -90:
            Turn(1550, 1550, 55);//右转90°
            rightDetect();
        break;
        case -45: 
            Turn(1550, 1550, 27);//右转45°
            rightDetect();
        break;
        //left
        case 45:
            Turn(1450, 1450, 27);//左转45°
            leftDetect();
        break; 
        case 90:
            Turn(1450, 1450, 55);//左转90°
            leftDetect();
        break;
        case 135: 
            Turn(1430, 1430, 67);//左转135°
            leftDetect();
        break;
        case 180:
            Turn(1430, 1430, 70);//逆时针掉头
            leftDetect();
        break;
    } 
}

//QTI 默认前进，参数为 -1 时倒退
void QTI(int Reverse = 1){
    QTIState = digitalRead(QTI1) * 8 +
               digitalRead(QTI2) * 4 +
               digitalRead(QTI3) * 2 +
               digitalRead(QTI4);//查询qti传感器状态
    Serial.println((int)QTIState);
    if(Reverse == 1)
        switch(QTIState){//选择qti传感器状态
        case 1:
            Turn(1650, 1600);//微向右转
            break;
        case 3:
            Turn(1510, 1550);//微小幅向右转
            break;
        case 8:
            Turn(1400,1450);//微向左转
            break;
        case 12:
            Turn(1450,1490);//微小幅向左转
            break;
        case 15:
            Forward(1);//前进2小步
            break;
        }
    else
        switch(QTIState){//选择qti传感器状态
        case 1:
            Turn(1400,1450);//微向右转
            break;
        case 3:
            Turn(1450,1490);//微小幅向右转
            break;
        case 8:
            Turn(1650, 1600);//微向左转
            break;
        case 12:
            Turn(1510, 1550);//微小幅向左转
            break;
        case 15:
            Back(1);//后2小步
            break;
        }
}

//检测中间两个QTI是否有在直线上
bool Detect(){
    QTIState = digitalRead(QTI2) * 4 +
               digitalRead(QTI3) * 2;//查询qti传感器状态
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

//右转检测函数，保证中间QTI至少有一个在直线上
void rightDetect(){
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

void centerToStart(){
    Back(60);
    while (QTIState != 15)
        QTI(-1);
    Forward(10);//前进一点，补偿
}

void setup(){
    pinMode(QTI1, INPUT);
    pinMode(QTI2, INPUT);
    pinMode(QTI3, INPUT);
    pinMode(QTI4, INPUT);
    pinMode(LMOTOR, OUTPUT);
    pinMode(RMOTOR, OUTPUT);
    pinMode(BACKSERVO, OUTPUT);
    pinMode(FRONTSERVO, OUTPUT);
    pinMode(TSPD1, INPUT);
    pinMode(TSPD2, INPUT);
    Serial.begin(9600);
}

void loop(){
    
    /*char status1 = digitalRead(TSPD1);  //光电门记录状态
    char status2 = digitalRead(TSPD2);
    long count1 = 0; //光电门计数
    long count2 = 0;
    char status_n1 = digitalRead(TSPD1);  //光电门即时状态
    char status_n2 = digitalRead(TSPD2);
    if (status1 != status_n1){
        status1 = status_n1;
        count1++;
    }
    if (status2 != status_n2){
        status2 = status_n2;
        count2++;
    }*/
    /*
    调试步骤：
    1：调零
    2：校正角度
    */
    startToCenter();
    MOVE_main();
    centerToStart();
    //move(1);
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

int first_turn[6] = {0, 90, 45, 0, -45, -90};

/*
1-yellow
2-white
3-red
4-black
5-blue
*/

int toMoveList[6], pointer;
int headO, backO;

void move_blocked_HO(int goal){
    turn_degree(turn_backward_list[goal]);//屁股对着挡住路的色块
    while(QTIState != 0)//检测是否到白点
        QTI(-1);
    backServo(1);//后伺服夹住
    turn_degree(180);//要放的色块转向前
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
    turn_degree(-first_turn[goal]);//转向前方
}

//主搬运函数
void MOVE_main(){
    pointer = 1;
    for(int i = 1; i <= 5; i++)
        if(shuffled[i] == i)
            move_direct(i);
        else{
            toMoveList[pointer] = i;
            pointer++;
        }
    //第一次
    move(toMoveList[1]);
    headO = shuffled[toMoveList[1]];
    //第二到n-1次
    for(int i = 2; i < pointer - 1; i++){
        if(i % 2 == 0){
            move_blocked_HO(shuffled[headO]);
            backO = shuffled[shuffled[headO]];
        }
        else{
            move_blocked_BO(shuffled[backO]);
            headO = shuffled[shuffled[backO]];
        }
    }
    if((pointer - 1) % 2 == 0)
        moveHO_direct(shuffled[headO]);
    else
        moveBO_direct(shuffled[backO]);
}

//该点放置色块为该路径终点要放置的块
void move_direct(int goal){
    turn_degree(first_turn[goal]);//转向目标
    //Forward(8);//前进一点，补偿
    while(QTIState != 0){//检测是否到白点，取到色块
        QTI();
    }
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

void moveHO_direct(int goal){
    turn_degree(first_turn[goal]);//转向目标
    //Forward(8);//前进一点，补偿
    while(QTIState != 0){//检测是否到白点
        QTI();
    }
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
    Forward(15);//补偿
}

//屁股有色块，无挡路色块
void moveBO_direct(int goal){
    turn_degree(turn_backward_list[goal]);//屁股对着挡住路的色块
    //Forward(8);//前进一点，补偿
    while(QTIState != 0){//检测是否到白点
        QTI(-1);
    }
    Back(7);//盲退一小段距离，QTI越过白圈
    for(int i = 1; i <= 68; i++)//循线，将物块推至得分点       
        QTI(-1);
    backServo(0);//后伺服松开
    Forward(20);//后退一段，将车身前面的叉子抽出，避免碰到色块
    //返回
    while(QTIState != 0)//检测是否到白点
        QTI(1);
    while(QTIState != 15)//检测是否到中心点
        QTI(1);
    Forward(15);//补偿
}

//case1：屁股无色块
void move(int start_loc){
    turn_degree(first_turn[start_loc]);//转向目标
    //Forward(8);//前进一点，补偿
    while(QTIState != 0){//检测是否到白点，取到色块
        QTI();
    }
    Forward(7);//盲走一小段距离，QTI越过白圈
    frontServo(1);//前伺服夹住
    while(QTIState != 15)//检测是否到中心点
        QTI(-1);
    Forward(15); //补偿
    turn_degree(-first_turn[start_loc]);//转向前方
}



//case2：头部有色块，有挡路色块


//case3：屁股有色块，有挡路色块
void move_blocked_BO(int goal){
    turn_degree(first_turn[goal]);//对着挡住路的色块
    while(QTIState != 0)//检测是否到白点
        QTI();
    frontServo(1);//前伺服夹住
    turn_degree(180);//要放的色块（屁股）转向前
    for(int i = 1; i <= 68; i++)//循线，将物块推至得分点       
        QTI(-1);
    backServo(0);//前伺服松开
    Forward(20);//前进一段，将车身后面的叉子抽出，避免碰到色块

    //返回
    while(QTIState != 0)//检测是否到白点
        QTI();
    while(QTIState != 15)//检测是否到中心点
        QTI();
    Forward(15);//盲走前进一小段，车身居中
    turn_degree(-turn_backward_list[goal]);//转向前方
}


//case5：头部有色块，无挡路色块
//即move_direct();


