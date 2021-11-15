#include <stdio.h>
#include <ST7565_homephone.h>
#include "Chung.h"
#include "banphim.h"
#include "dieukhiendongco.h"
#include "camBienTien.h"
#include "camBienLui.h"
#include "camBienPhai.h"
#include "camBienTrai.h"
#include "CThanhTrinh.h"
#include "CThanhTrinh3.h"
#include "CThanhTrinh4.h"
#include "dem.h"
#include <TimerOne.h>
#include "camBienTien2.h"
#define TIMER_US 2000

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(3000);
  pinMode(CB2, OUTPUT);
  pinMode(CB1, OUTPUT);
  pinMode(CB4, OUTPUT);
  pinMode(CB3, OUTPUT);
  pinMode(motorInput11, OUTPUT);
  pinMode(motorInput12, OUTPUT);
  pinMode(motorInput13, OUTPUT);
  pinMode(motorInput14, OUTPUT);
  pinMode(ENA1, OUTPUT);
  pinMode(ENB1, OUTPUT);
  pinMode(motorInput21, OUTPUT);
  pinMode(motorInput22, OUTPUT);
  pinMode(motorInput23, OUTPUT);
  pinMode(motorInput24, OUTPUT);
  pinMode(ENA2, OUTPUT);
  pinMode(ENB2, OUTPUT);
  //setting serial monitor at a default baund rate of 9600
  delay(50);
  //  Timer1.initialize(TIMER_US);
  //  Timer1.attachInterrupt( timerIsr);
  Time1 = millis();
  Time2 = millis();
  pinMode(nutnhan, INPUT);
  pinMode(nutnhan2, INPUT);
  myservoTrai.attach(50);//1 trai50 2 giua46 3 cat52 4 phai40
  myservoPhai.attach(40);
  myservoDuoi.attach(46);
  myservoCat.attach(48);
}

void loop() {
  if ( (unsigned long) (millis() - Time1) > 0)
  {


    if ((dem == 0) || (dem == 1) || ( dem == 2) || (dem == 6)  || (dem == 7) || (dem == 8) || (dem == 9) || (dem == 22) || (dem == 32))
    {


      {
        if ( dem < 17 )
        {
          digitalWrite(CB1, LOW);
          digitalWrite(CB2, HIGH);
          digitalWrite(CB3, HIGH);
          digitalWrite(CB4, LOW);
        }
        else
        {
          digitalWrite(CB1, LOW);
          digitalWrite(CB2, HIGH);
          digitalWrite(CB3, LOW);
          digitalWrite(CB4, HIGH);
        }
      }
      demL(dem);
    }

    else if ((dem == 20) || (dem == 21) || (dem == 30) || (dem == 31))
    {
      digitalWrite(CB3, LOW);
      digitalWrite(CB4, HIGH);
      digitalWrite(CB1, LOW);
      digitalWrite(CB2, HIGH);
      demP(dem);

    }
    else if ((dem == 10) || (dem == 11) || (dem == 12))
    {
      digitalWrite(CB3, HIGH);
      digitalWrite(CB4, LOW);
      digitalWrite(CB1, HIGH);
      digitalWrite(CB2, LOW);
      //      Serial.println("Di Xuong");
      demX(dem);
    }
    else if ((dem == 3) || (dem == 4) || (dem == 5)  || (dem == 13) || (dem == 14) || (dem == 15) || ( dem == 23) || (dem == 24) || (dem == 25) || (dem == 33) || (dem == 34) || (dem == 35))
    {
      digitalWrite(CB3, HIGH);
      digitalWrite(CB4, LOW);
      digitalWrite(CB1, LOW);
      digitalWrite(CB2, HIGH);
      //      Serial.println("Re Trai");
      demT(dem);
    }
    Time1 = millis();
  }
  if ((unsigned long) (millis() - Time2) > 0)
  {

    if ( dem < 10)
      CTHT();
    else if ((dem > 10) && (dem <   17) || (dem > 30) )
    {
      CTHT3();
    }
    else
    {
      CTHT4();
    }
    Time2 = millis();
  }
  if ((dem == 0) || (dem == 1) || ( dem == 2)  || (dem == 6) || (dem == 7) || (dem == 8) || (dem == 9) || (dem == 22) || (dem == 32))
  {
    if ((dem == 6) || (dem == 7) || (dem == 9) || (dem == 22))
    {
      dung2();
      doc_CBT2();
      DK_Tien2();
    }
    //    else if ((dem == 17) || (dem == 18) || (dem == 19))
    //    {
    //      //      if ((thabong == 1) || (thabong == 2) || (thabong == 3))
    //      //      {
    //      dung2();
    //      analogWrite(ENA1, 80);
    //      analogWrite(ENB1, 80);
    //      tien();
    //      //      }
    //      //      else
    //      //      {
    //      //        dung1();
    //      //        doc_CBTrai();
    //      //        DK_Trai();
    //      //      }
    //    }
    else
    {
      dung2();
      doc_CBT();
      DK_Tien();
    }
  }
  else if ((dem == 3) || (dem == 4) || (dem == 5) || (dem == 13) || (dem == 14) || (dem == 15) || (dem == 16) || (dem == 23) || (dem == 24) || (dem == 25) || (dem == 33) || (dem == 34) || (dem == 35))
  {
    if ((dem == 5) || (dem == 13) || (dem == 15) || (dem == 16) || (dem == 23) || (dem == 24) || (dem == 25) || (dem == 33) || (dem == 34) || (dem == 35))
    {

      //      Serial.println("vao pid");

      dung1();
      doc_CBTrai();
      SetTocDo = 55;
      Kp = 30;
      Ki = 0.001;
      Kd = 5;
      DK_Trai();
    }
    else if ((dem >= 8) && (thabong  == 0))
    {
      dung2();
      analogWrite(ENA1, 215);
      analogWrite(ENB1, 35);
      tien();
    }
    else if (( dem == 3 ) || (dem == 4))
    {
      dung1();
      analogWrite(ENA2, 245);
      analogWrite(ENB2, 255);
      trai();
    }
    else if (dem == 5)
    {
      doc_CBTrai();
      SetTocDo = 50;
      Kp = 35 ;
      Ki = 0.001;
      Kd = 10;
      DK_Trai();

    }
    else
    {

      dung1();
      doc_CBTrai();
      DK_Trai();
    }
  }
  else if ((dem == 11) || (dem == 12))
  {
    dung2();
    doc_CBL();
    DK_Lui();
  }
  else if ((dem == 20) || (dem == 21) || (dem == 30) || (dem == 31))
  {
    dung1();
    analogWrite(ENA2, 75);
    analogWrite(ENB2, 60);
    phai();
  }


  Serial.println(dem);


}
