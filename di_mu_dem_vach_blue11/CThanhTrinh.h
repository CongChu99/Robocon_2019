

void CTHT()
{
  //  thabong = 1;
  trangthai = digitalRead(nutnhan);
  if (trangthai != 0)
  {

    myservoTrai.write(140);
    myservoPhai.write(40);
  }
  // put your main code here, to run repeatedly:
  else
  {
    thabong += 1;
    Serial.println("tha rieng");
    dung();
    time1 = millis();
    for (pos1 = 40; pos1 >= 0; pos1 -= 10)
    {
      time1 = millis();
      myservoPhai.write(pos1);
      while (millis() < time1 + period);
    }
    for (pos = 140; pos >= 93; pos -= 10)
    {
      time1 = millis();
      myservoTrai.write(pos);
      while (millis() < time1 + period);
    }
    while (millis() < time1 + period1);
    time1 = millis();
    while (millis() < time1 + period2);
    for (pos1 = 0; pos1 <= 40; pos1 += 10)
    {
      time1 = millis();
      myservoPhai.write(pos1);
      while (millis() < time1 + period);
    }
    for (pos = 93; pos <= 140; pos += 10)
    {
      time1 = millis();
      myservoTrai.write(pos);
      while (millis() < time1 + period);
    }
    while (millis() < time1 + period2);
    time1 = millis();
    analogWrite(ENA1, 50);
    analogWrite(ENB1, 50);
    lui();
    while (millis() < time1 + 100)
    {
      dem = 10 ;
    }
    Serial.print("out ra");
    //    time1 = millis();
    //    dung1();
    //    analogWrite(ENA2, 50);
    //    analogWrite(ENB2, 50);
    //    phai();
    //    while (millis() < time1 + 1800);

  }



}
