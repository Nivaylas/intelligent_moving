float distance;  //定义超声波接收信号变量 distance.
char qtis,qti1=12,qti2=11,qti3=6,qti4=10;//从左到右依次为qti1~qti4
char switchA=3;
char switchB=1;
char switchC=6;
char switchD=2; 
char switchE=4;
char lineBlack = 2;



char line=0;

void fastForward(unsigned char a)//前进函数
{
    unsigned char i;
    for(i=0;i<a;i++)       
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1400);//1300
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1600);//1650
        digitalWrite(5,LOW);
        delay(20);
    } 
}
void back(unsigned char a)//后退函数
{  
    unsigned char i;
    for(i = 0;i < a;i++)       
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1600);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1410);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn(unsigned int right,unsigned int left)//微转动，用于qti循线    
{
    unsigned char i;
    for(i = 0;i < 2;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(right);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(left);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_right_45(void)//右转45°
{
    unsigned char i;
    for(i = 0;i < 27;i++)       
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1550);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1550);
        digitalWrite(5,LOW);
        delay(20);
    } 
}
void turn_right_D4_45(void)//右转45°
{
    unsigned char i;
    for(i = 0;i < 20;i++)       
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1550);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1550);
        digitalWrite(5,LOW);
        delay(20);
    } 
}
void turn_right_90(void) //右转90°
{
    unsigned char i;
    for(i = 0;i < 55;i++)//改变传动的角度值
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1550);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1550);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_right_135()
{
    unsigned char i;
    for(i = 0;i < 60;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1550);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1550);
        digitalWrite(5,LOW);
        delay(20);
    }
}

void turn_right_C2_135()
{
    unsigned char i;
    for(i = 0;i < 60;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1550);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1550);
        digitalWrite(5,LOW);
        delay(20);
    }
}

void turn_right_B4_135()
{
    unsigned char i;
    for(i = 0;i < 60;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1550);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1550);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_right_D3_135()
{
    unsigned char i;
    for(i = 0;i < 60;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1550);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1550);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_right_C4_135()
{
    unsigned char i;
    for(i = 0;i < 60;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1550);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1550);
        digitalWrite(5,LOW);
        delay(20);
    }
}

void turn_right_E4_135()
{
    unsigned char i;
    for(i = 0;i < 60;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1550);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1550);
        digitalWrite(5,LOW);
        delay(20);
    }
}

void turn_left_45(void)  //左转45°
{
    unsigned char i;
    for(i=0;i<27;i++)      
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1450);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1450);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_left_B2_45(void)  //左转45°
{
    unsigned char i;
    for(i=0;i<22;i++)      
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_left_B5_45(void)  //左转45°
{
    unsigned char i;
    for(i=0;i<22;i++)      
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_left_90(void)  //左转90°
{
    unsigned char i;
    for(i = 0;i < 55;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1450);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1450);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_left_A1_90(void)  //左转90°
{
    unsigned char i;
    for(i = 0;i < 45;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_left_135()
{
    unsigned char i;
    for(i = 0;i < 67;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_left_D5_135()
{
    unsigned char i;
    for(i = 0;i < 67;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_left_B2_135()
{
    unsigned char i;
    for(i = 0;i < 67;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_left_B3_135()
{
    unsigned char i;
    for(i = 0;i < 67;i++)
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_back(void)//掉头
{  
    unsigned char i;
    for(i = 0;i <70;i++)      
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_back_B3(void)//掉头
{  
    unsigned char i;
    for(i = 0;i <90;i++)      
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_back_C3(void)//掉头
{  
    unsigned char i;
    for(i = 0;i <90;i++)      
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}
void turn_back_D3(void)//掉头
{  
    unsigned char i;
    for(i = 0;i <90;i++)      
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}

void turn_back_E3(void)//掉头
{  
    unsigned char i;
    for(i = 0;i <90;i++)      
    {
        digitalWrite(9,HIGH);
        delayMicroseconds(1430);
        digitalWrite(9,LOW);
        digitalWrite(5,HIGH);
        delayMicroseconds(1430);
        digitalWrite(5,LOW);
        delay(20);
    }
}

void stop1(void)//停止函数
{
    digitalWrite(9,HIGH);
    delayMicroseconds(1500);
    digitalWrite(9,LOW);
    digitalWrite(5,HIGH);
    delayMicroseconds(1500);
    digitalWrite(5,LOW);
    delay(20);
}
void ceqti(unsigned char a)
{
     unsigned char i;
      for(i = 0;i < a;i++)
    {
        qti();
    }
}
float getSharp(unsigned char i)//得出距离
{
    float sharpValue = 0;
    sharpValue = (float)analogRead(i);
    sharpValue = (float)(sharpValue * 5) / 1024.0;
    sharpValue = (26.928 * pow(sharpValue, -1.217));
    if(sharpValue > 80.0)//如果距离大于80mm，则返回0。
    return 80;
    else if(sharpValue < 8)
    {
      return 1;
    }
    else
    {
      return sharpValue;
     }
    
}
int flag = 0;
void qti()//qti循线函数
{
    qtis=digitalRead(qti1)*8+digitalRead(qti2)*4
      +digitalRead(qti3)*2+digitalRead(qti4);//查询qti传感器状态
//           Serial.println((int)qtis);
    switch(qtis)//选择qti传感器状态
    {
        case 1:turn(1650,1600);break;
        case 2:
        case 3:turn(1510,1550); flag = 1;break;//小幅向右转
        
        case 8:turn(1400,1450);break;
        case 4:   
        case 12:turn(1450,1490);flag = 2;break;//小幅向左转
        
        case 0:
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
        case 11: 
        case 13:  
        case 14:
        case 15:fastForward(1); flag = 0;break;//前进2小步  
    }  
}
void yzjiance(void)//右转检测函数，保证中间QTI至少有一个在直线上
{
  int d;
  d=jiance();
  while(d)
  {
    d=jiance();
    turn(1550,1550);
  }
}
void zzjiance(void)//左转检测函数，保证中间QTI至少有一个在直线上
{
  int d;
  d=jiance();
  while(d)
  {
    d=jiance();
    turn(1450,1450); 
  }
}
int jiance(void)//检测中间两个QTI是否有在直线上
{
   qtis=digitalRead(qti2)*4 +digitalRead(qti3)*2;//查询qti传感器状态
   if(qtis==2||qtis==4||qtis==6)
    return 0;
   else
    return 1;
}
void setup() 
{
    pinMode(qti1,INPUT);//设置11号口为输入口
    pinMode(qti2,INPUT);//设置12号口为输入口
    pinMode(qti3,INPUT);//设置3号口为输入口
    pinMode(qti4,INPUT);//设置10号口为输入口
    pinMode(9,OUTPUT);//设置9号口为右电机输出引脚
    pinMode(5,OUTPUT);//设置5号口为左电机输出引脚
    Serial.begin(9600);
}

void loop() 
{ 
/*
调试步骤：
1：调零
2：校正角度
*/  
/*
  while(1)
  {
  fastForward(1);
//    stop1();
//       turn_right_90();
//     turn_right_45();
//     turn_left_90();
//     turn_left_45();
//     turn_back();
//    qtis=digitalRead(qti1)*8+digitalRead(qti2)*4
//      +digitalRead(qti3)*2+digitalRead(qti4);//查询qti传感器状态
//     Serial.println((int)qtis);
//       delay(1000); 
    } */
  fastForward(60);//前进跳过起点黑线
  while(qtis!=15)  //检测是否到中心点
  {qti();}
  fastForward(10);//前进一点，补偿
  carry_E();delay(1000);
  carry_C();delay(1000);
  carry_A();delay(1000);
  carry_B();delay(1000);
  carry_line();delay(1000);
  goStart();
  while(1);

/*  carry_A();

  carry_E();
  
  carry_B();

  carry_C();
  delay(500); 
  carry_line(); 
  while(1);
  carry_D();
*/

}

void goStart()
{
  if(!line)
  {
      turn_back();
  }
  zzjiance();
  fastForward(20);  //盲走前进一小段
  while(qtis!=15)  //检测是否到白点
  {qti();}
  fastForward(60);  //盲走前进一小段
}
 void carry_A() 
 {
    unsigned char i;
    turn_left_90();
    zzjiance();
//    fastForward(8);//前进一点，补偿
    while(qtis!=0)  //检测是否到白点
    {qti();}
    switch(switchA)
    {
      case 1:               //A点放置色块位黄色
             fastForward(7);//盲走一小段距离，QTI越过白圈
             for(i=0;i<68;i++)//循线，将物块推至得分点       
              {qti();}
              back(20);        //后退一段，将车身前面的叉子抽出，避免碰到色块
              turn_back();     //原地掉头
              zzjiance();      //左转检测函数，保证中间QTI至少有一个在直线上
			  
               while(qtis!=0)  //检测是否到白点
              {qti();}
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15); //盲走前进一小段
              turn_left_90();//左转90度
              zzjiance();     //左转检测函数，保证中间QTI至少有一个在直线上
          break;
      case 2:                //A点放置色块位白色，且B点没有色块
              turn_back();   //原地掉头
              zzjiance();    //左转检测函数，保证中间QTI至少有一个在直线上
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15); //补偿
			        turn_right_90(); //向右旋转 90°
              yzjiance();      //右转检测函数，保证中间QTI至少有一个在直线上
			        for(i=0;i<40;i++)//向前循线移动一段距离      
              {qti();}
              turn_back();      //原地掉头对准直线
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15); //补偿
			        turn_left_45();
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              for(i=0;i<68;i++) //循线，将物块推至得分点       
              {qti();}
              back(20);         //后退一段，将车身前面的叉子抽出，避免碰到色块  
              turn_back();      //原地掉头
              zzjiance();       //左转检测函数，保证中间QTI至少有一个在直线上
              while(qtis!=0)  //检测是否到白点
              {qti();}
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
			        turn_right_45(); //向右旋转 45°
              zzjiance();      
			        for(i=0;i<20;i++) //向前循线移动一段距离      
              {qti();}
              turn_back();      //原地掉头对准直线
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15); //盲走前进一小段
              zzjiance();      
              break;
      case 3:                  //A点放置色块位红色，且C点没有色块
              turn_back();      
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_left_90();
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              for(i=0;i<68;i++)       
              {qti();}
              back(20);
              turn_back();
              zzjiance();
              while(qtis!=0)   //检测是否到白点
              {qti();}
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_back();
              zzjiance();
         break;  
      case 4:                  //A点放置色块位黑色，且D点没有色块
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_left_45();
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              for(i=0;i<68;i++)       
              {qti();}
              back(20);
              turn_back();
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_left_45();
              yzjiance();
			        for(i=0;i<20;i++) //向前循线移动一段距离      
              {qti();}
              turn_back();      //原地掉头对准直线
              while(qtis!=15)  //检测是否到中心点
              {qti();}
         break;
      case 5:                  //A点放置色块位紫色，且E点没有色块
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              while(qtis!=0)  //检测是否到白点
              {qti();}
              for(i=0;i<68;i++)       
              {qti();}
              back(20);
              turn_back();
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_right_90();
              yzjiance();
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

 void carry_B()
 {
    unsigned char i;
    turn_left_45();
     zzjiance();
    while(qtis!=0)  //检测是否到白点
    {qti();}
    switch(switchB)
    {
      case 1:             //B点放置色块为黄色，且黄色路线上没有色块放置
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              /*需要修改*/
              turn_right_45();
              for(i=0;i<68;i++)       
              {qti();}
              turn_back();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_left_90();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(10);
              for(i=0;i<68;i++)       
              {qti();}
              back(20);
              turn_back();
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(15);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_left_90();
              zzjiance();
         break;  
      case 2:                  //B点放置色块为白色
             fastForward(15);
             for(i=0;i<68;i++)       
              {qti();}
              fastForward(12);
              back(20);
              turn_back();
              zzjiance();
               while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(15);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_right_45();
              yzjiance();
              fastForward(10);
              /*接下的作用是将车身对准C点直线，直接右转角度太大，容易出错*/
              for(i=0;i<30;i++) //向前循线移动一段距离      
              {qti();}
              turn_back();     //原地掉头对准直线
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10); //盲走前进一小段
          break;
      case 3:                //B点放置色块为红色，且红色路线上没有色块放置
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              
              turn_right_45();  //右转45度
              yzjiance();
              fastForward(10);  //
              /*接下的作用是将车身对准C点直线，直接右转角度太大，容易出错*/
              for(i=0;i<30;i++) //向前循线移动一段距离      
              {qti();}
              turn_back();      //原地掉头对准直线
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10); //盲走前进一小段
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++)  //巡线前进一段距离，将色块推至得分区域     
              {qti();}
              back(20);
              turn_back();       //后退掉头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              
              turn_back();
              zzjiance();
         break;  
      case 4:                 //B点放置色块为黑色，且黑色路线上没有色块放置
              turn_back();    //调头
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_left_90();  //左转90度，对准D点直线
              zzjiance();
              fastForward(10);
              while(qtis!=0)  //检测是否到白点，D点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++)    //巡线至得分点   
              {qti();}
              back(20);            //后退
              turn_back();         //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接右转角度太大，容易出错*/
              fastForward(10);
              turn_left_45();
              zzjiance();
              fastForward(10);
              for(i=0;i<30;i++) //向前循线移动一段距离      
              {qti();}
              turn_back();      //原地掉头对准直线
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10); //盲走前进一小段
         break;
      case 5:                  //B点放置色块为紫色，且紫色路线上没有色块放置
              turn_back();     //调头
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_left_B5_45();//对准E点直线
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++) //推物块到得分点      
              {qti();}
              back(20);         //调头
              turn_back();
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_right_90();
              yzjiance();
         break;
      case 6:                 //对应颜色物块路线上有物块放置，将B点色块搬运至起始直线上
              turn_back();    //调头
              zzjiance();
              while(qtis!=15)  //检测是否到中心点十字路口
              {qti();}
              fastForward(10);
              turn_right_45();
              yzjiance();
              for(i=0;i<80;i++) //将色块运至起始直线上      
              {qti();}
              line++;           //搬运到直线点的变量计数+1
              back(20);
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);//对准C点直线
         break;      
    }
 }

  void carry_C()
 {
    unsigned char i;
    while(qtis!=0)  //检测是否到白点
    {qti();}
    switch(switchC)
    {
      case 1:            //C点放置色块为黄色，且黄色路线上没有色块放置
              turn_back();//调头
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_right_90(); //右转90对准直线
              yzjiance();
              fastForward(7);
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++)       
              {qti();}
              back(20);
              turn_back();   //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_left_90();
              zzjiance();
              fastForward(10);
              //对准C点直线
         break;  
      case 2:             //C点放置色块为白色，且白色路线上没有色块放置
              turn_back();//调头
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(10);
              for(i=0;i<30;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_left_45();  //对准B点直线           
              yzjiance();
              fastForward(10);
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++)  //巡线到得分点     
              {qti();}
              back(20);
              turn_back();      //后退掉头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(10);
              turn_right_45();
              fastForward(10);
              for(i=0;i<30;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              //对准C点直线
          break;  
      case 3:                //C点放置色块为红色
              fastForward(7);  //盲走前一小段，越过C点白圈
             for(i=0;i<68;i++)       
              {qti();}
              fastForward(10);
              back(20);
              turn_back();
              zzjiance();
               while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              while(qtis!=10)  //检测是否到中心点
              {qti();}
              fastForward(10); 
              turn_back();
              zzjiance();
              fastForward(5);
          break;
      case 4:               //C点放置色块为黑色，且黑色路线上没有色块放置
              turn_back();  //调头
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(10);
              for(i=0;i<30;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_right_45(); //对准D点直线
              yzjiance();
              fastForward(10);
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++) //运至得分点    
              {qti();}
              back(20);
              turn_back();      //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(15);
              turn_left_45(); //对准C点直线
              zzjiance();                            
              for(i=0;i<30;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              //对准C点
         break;
      case 5:              //C点放置色块为紫色，且紫色路线上没有色块放置
              turn_back();  //调头
              zzjiance();
              while(qtis!=15)//检测是否到中心点
              {qti();}
              fastForward(15);
              turn_left_90();
              zzjiance();
              fastForward(8);
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++) //运至得分点    
              {qti();}
              back(20);         //后退
              turn_back();      //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);  //越过白色圆圈
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_right_90();//对准C点直线
              yzjiance();
         break;
      case 6:             //对应颜色物块路线上有物块放置，将C点色块搬运至起始直线上
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              for(i=0;i<100;i++)       
              {qti();}
              line++;    //搬运到直线点的变量计数+1
              back(20);
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
         break;      
    }
 }

   void carry_D()
 {
    unsigned char i;
    turn_right_45();//右转45度，转到D点直线
    yzjiance();
    while(qtis!=0)  //检测是否到白点
    {qti();}
    switch(switchD)
    {
      case 1:             //D点放置色块为黄色，且黄色路线上没有色块放置
              turn_back();//调头
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_right_45(); //对准A点直线
              yzjiance();
              fastForward(10);
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++) //巡线至得分点      
              {qti();}
              back(20);         //后退
              turn_back();      //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_left_90();  //左转90对准C点直线
              zzjiance();
              fastForward(15);
         break;  
      case 2:                 //D点放置色块为白色，且白色路线上没有色块放置
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_right_90(); //右转90对准B点直线
              yzjiance();
              fastForward(10);
               while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(15);
              for(i=0;i<68;i++)//搬运至色块得分点      
              {qti();}
              back(20);       //后退
              turn_back();   //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(15);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(15);
              turn_right_45();
              for(i=0;i<30;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              //对准C点直线
          break;  
      case 3:             //D点放置色块为红色，且红色路线上没有色块放置
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(15);
              turn_left_45();
              for(i=0;i<30;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(15);
              for(i=0;i<68;i++)//搬运至色块得分点      
              {qti();}
              back(20);       //后退
              turn_back();   //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(15);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(20);
              turn_back_D3();//调头对准C点直线
              zzjiance();
              fastForward(10);
          break;
      case 4:                 //D点放置色块为黑色，且黑色路线上没有色块放置
              fastForward(10);
              for(i=0;i<68;i++)//搬运至色块得分点      
              {qti();}
              back(20);       //后退
              turn_back();   //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(15);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(15);
              turn_left_45();
              for(i=0;i<30;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              delay(500);
         break;
      case 5:             //D点放置色块为紫色，且紫色路线上没有色块放置
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(15);
              turn_left_45();
              for(i=0;i<30;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_right_90();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++)//搬运至色块得分点      
              {qti();}
              back(20);       //后退
              turn_back();   //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_right_90();//右转90对准C点直线
              yzjiance();
         break;
      case 6:             //对应颜色物块路线上有物块放置，将D点色块搬运至起始直线上
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_left_45();
              zzjiance();
              for(i=0;i<100;i++)       
              {qti();}
              line++;    //搬运到直线点的变量计数+1
              back(20);
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
         break;      
    }
 }

 void carry_E()
 {
    unsigned char i;
    turn_right_90();
    yzjiance();
    fastForward(8);//前进一点，补偿
    while(qtis!=0)  //检测是否到白点
    {qti();}
    switch(switchE)
    {
      case 1:             //E点放置色块为黄色，且黄色路线上没有色块放置
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++)//搬运至色块得分点      
              {qti();}
              back(20);       //后退
              turn_back();   //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(10);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_left_90();//对准C点直线
              zzjiance();
         break;  
      case 2:             //E点放置色块为白色，且白色路线上没有色块放置
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_right_45(); //对准B点直线
              yzjiance();
              fastForward(8);
               while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++)//搬运至色块得分点      
              {qti();}
              back(20);       //后退
              turn_back();   //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(15);
              turn_right_45();
              for(i=0;i<30;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              //对准C点直线
          break;  
      case 3:             //E点放置色块为红色，且红色路线上没有色块放置
              turn_back(); //调头
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_right_90(); //右转90对准C点直线
              yzjiance();
              fastForward(10);
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++)//搬运至色块得分点      
              {qti();}
              back(20);       //后退
              turn_back();   //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(20);
              turn_back(); //调头对准C点直线
              zzjiance();
              fastForward(10);
          break;
      case 4:              //E点放置色块为黑色，且黑色路线上没有色块放置
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(10);
              turn_left_90();
              for(i=0;i<80;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_right_45();//右转45度，转到D点直线
              yzjiance();
              fastForward(8);//前进一点，补偿
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(7);
              for(i=0;i<68;i++)//搬运至色块得分点      
              {qti();}
              back(20);       //后退
              turn_back();   //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(10);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              /*接下的作用是将车身对准C点直线，直接转角度太大，容易出错*/
              fastForward(15);
              turn_left_45();
              for(i=0;i<80;i++)       
              {qti();}
              turn_back();     //调头
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
         break;
      case 5:                  //E点放置色块为紫色
              fastForward(7);
              for(i=0;i<68;i++)//搬运至色块得分点      
              {qti();}
              back(20);       //后退
              turn_back();   //调头
              zzjiance();
              while(qtis!=0)  //检测是否到白点
              {qti();}
              fastForward(15);
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
              turn_right_90();//右转90对准C点直线
              yzjiance();
              fastForward(10);
         break;
      case 6:             //对应颜色物块路线上有物块放置，将E点色块搬运至起始直线上
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(15);
              turn_left_90();
              zzjiance();
              for(i=0;i<100;i++)       
              {qti();}
              line++;    //搬运到直线点的变量计数+1
              back(20);
              turn_back();
              zzjiance();
              while(qtis!=15)  //检测是否到中心点
              {qti();}
              fastForward(10);
         break; 
    }
 }

void carry_line()
{
   int i=0;
   turn_back();
   zzjiance();
   fastForward(10);
   for(i=0;i<90;i++)       
   {qti();}
   switch(line)
    {
     case 1:
            switch(lineBlack)
            {
              case 1: 
                        //放置色块为黄色，且黄色路线上没有色块放置
                      turn_back();
                      zzjiance();
                      while(qtis!=15)  //检测是否到中心点
                      {qti();}
                      fastForward(10);             
                      turn_left_90();
                      zzjiance();
                      while(qtis!=0)  //检测是否到白点
                      {qti();}
                      fastForward(7);
                      for(i=0;i<68;i++)//搬运至色块得分点      
                      {qti();}
                      back(20);       //后退
                      turn_back();   //调头
                      zzjiance();
                      while(qtis!=0)  //检测是否到白点
                      {qti();}
                      fastForward(7);
                      while(qtis!=15)  //检测是否到中心点
                      {qti();}
                      fastForward(10);
                      turn_right_90();//对准C点直线
                      zzjiance();
                      break;
              case 2:           //放置色块为白色，且白色路线上没有色块放置
                    turn_back();
                    zzjiance();
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);             
                    turn_left_45();
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    for(i=0;i<68;i++)//搬运至色块得分点      
                    {qti();}
                    back(20);       //后退
                    turn_back();   //调头
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);
                    turn_right_45();//对准C点直线
                    zzjiance();
                     break;       
              case 3:          //放置色块为红色，且红色路线上没有色块放置
                    turn_back();
                    zzjiance();
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);             
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    for(i=0;i<68;i++)//搬运至色块得分点      
                    {qti();}
                    back(20);       //后退
                    turn_back();   //调头
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);          
                     break;              
              case 4:           //放置色块为黑色，且黑色路线上没有色块放置
                    turn_back();
                    zzjiance();
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);             
                    turn_right_45();
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    for(i=0;i<68;i++)//搬运至色块得分点      
                    {qti();}
                    back(20);       //后退
                    turn_back();   //调头
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);
                    turn_left_45();//对准C点直线
                    zzjiance();
                     break;
              case 5:     //放置色块为白色，且白色路线上没有色块放置
                    turn_back();
                    zzjiance();
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);             
                    turn_left_45();
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    for(i=0;i<68;i++)//搬运至色块得分点      
                    {qti();}
                    back(20);       //后退
                    turn_back();   //调头
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);
                    turn_right_45();//对准C点直线
                    zzjiance();                     
                     break;                                                 
              }
              break;
     case 2:
            switch(lineBlack)
            {
              case 1: 
                        //放置色块为黄色，且黄色路线上没有色块放置
                      turn_back();
                      zzjiance();
                      while(qtis!=15)  //检测是否到中心点
                      {qti();}
                      fastForward(10);             
                      turn_left_90();
                      zzjiance();
                      while(qtis!=0)  //检测是否到白点
                      {qti();}
                      fastForward(7);
                      for(i=0;i<68;i++)//搬运至色块得分点      
                      {qti();}
                      back(20);       //后退
                      turn_back();   //调头
                      zzjiance();
                      while(qtis!=0)  //检测是否到白点
                      {qti();}
                      fastForward(7);
                      while(qtis!=15)  //检测是否到中心点
                      {qti();}
                      fastForward(10);
                      turn_right_90();//对准C点直线
                      zzjiance();
                      break;
              case 2:           //放置色块为白色，且白色路线上没有色块放置
                    turn_back();
                    zzjiance();
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);             
                    turn_left_45();
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    for(i=0;i<68;i++)//搬运至色块得分点      
                    {qti();}
                    back(20);       //后退
                    turn_back();   //调头
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);
                    turn_right_45();//对准C点直线
                    zzjiance();
                     break;       
              case 3:          //放置色块为红色，且红色路线上没有色块放置
                    turn_back();
                    zzjiance();
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);             
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    for(i=0;i<68;i++)//搬运至色块得分点      
                    {qti();}
                    back(20);       //后退
                    turn_back();   //调头
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);          
                     break;              
              case 4:           //放置色块为黑色，且黑色路线上没有色块放置
                    turn_back();
                    zzjiance();
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);             
                    turn_right_45();
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    for(i=0;i<68;i++)//搬运至色块得分点      
                    {qti();}
                    back(20);       //后退
                    turn_back();   //调头
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);
                    turn_left_45();//对准C点直线
                    zzjiance();
                     break;
              case 5:     //放置色块为白色，且白色路线上没有色块放置
                    turn_back();
                    zzjiance();
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);             
                    turn_left_45();
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    for(i=0;i<68;i++)//搬运至色块得分点      
                    {qti();}
                    back(20);       //后退
                    turn_back();   //调头
                    zzjiance();
                    while(qtis!=0)  //检测是否到白点
                    {qti();}
                    fastForward(7);
                    while(qtis!=15)  //检测是否到中心点
                    {qti();}
                    fastForward(10);
                    turn_right_45();//对准C点直线
                    zzjiance();                     
                     break;                                                 
              }
              break;                     
    }
}
