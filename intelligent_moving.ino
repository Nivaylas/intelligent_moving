#define QTI1 
#define QTI2 
#define QTI3 
#define QTI4 
#define QTI5 
#define QTI6 

const int TARGET = {1, 2, 3, 4, 5};
int shuffled = {2, 4, 5, 1, 3};

void setup(){
    pinMode(QTI1, INPUT);
    pinMode(QTI2, INPUT);
    pinMode(QTI3, INPUT);
    pinMode(QTI4, INPUT);
    pinMode(QTI5, INPUT);
    pinMode(QTI6, INPUT);
    pinMode(9, OUTPUT);
    pinMode(5, OUTPUT);
    Serial.begin(9600);
}

void qti(){
    qtiState = digitalRead(QTI1) * 32 +
               digitalRead(QTI2) * 16 +
               digitalRead(QTI3) * 8 +
               digitalRead(QTI4) * 4 +
               digitalRead(QTI5) * 2 +
               digitalRead(QTI6);
    //Serial.println((int)qtiState)
}

void startToCenter(){
    moveForward(60);
    while (qtiState!=63)
    {
        /* code */
    }
    
}

void loop(){
    startToCenter();


}