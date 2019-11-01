#define QTI1 
#define QTI2 
#define QTI3 
#define QTI4 
#define LMOTOR 
#define RMOTOR 

const int TARGET = {1, 2, 3, 4, 5};
int shuffled = {2, 4, 5, 1, 3};

int QTIState;

void motor(int left, int right,int times){
    for(int i = 1; i <= times; i++){
        digitalWrite(LMOTOR, HIGH);
        delayMicroseconds(right);
        digitalWrite(LMOTOR, LOW);
        digitalWrite(RMOTOR, HIGH);
        delayMicroseconds(right);
        digitalWrite(RMOTOR, LOW);
        delay(20);
    }
}

void QTI(){
    QTIState = digitalRead(QTI1) * 8 +
               digitalRead(QTI2) * 4 +
               digitalRead(QTI3) * 2 +
               digitalRead(QTI4);//查询qti传感器状态
    //Serial.println((int)QTIState)
    switch(QTIState){//选择qti传感器状态
        case 1:
            motor(1650, 1600);//向右转
            break;
        case 3:
            motor(1510, 1550);//小幅向右转
            break;
        case 8:
            turn(1400,1450);//向左转
            break;
        case 12:
            turn(1450,1490);//小幅向左转
            break;
        case 15:
            fastForward(1);//
            break;
    }
}

void startToCenter(){
    moveForward(60);
    while (QTIState != 63){
        QTI();
    }
    
}

void setup(){
    pinMode(QTI1, INPUT);
    pinMode(QTI2, INPUT);
    pinMode(QTI3, INPUT);
    pinMode(QTI4, INPUT);
    pinMode(9, OUTPUT);
    pinMode(5, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    startToCenter();


}
