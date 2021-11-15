

void CTHT4()
{
  //  thabong = 2;
  trangthai2 = digitalRead(nutnhan2);
  if (trangthai2 != 0)
  {

    myservoCat.write(90);
  }
  // put your main code here, to run repeatedly:
  else
  {
    {
      thabong += 1;
      Serial.println("tha rieng");
      dung();
      time1 = millis();
      for (pos1 = 90; pos1 <= 180; pos1 += 10)
      {
        time1 = millis();
        myservoCat.write(pos1);
        while (millis() < time1 + period);
      }

      while (millis() < time1 + period1);
      time1 = millis();
      while (millis() < time1 + 700)
      {
         dem = 30;
        Serial.println("lui ra");
        analogWrite(ENA2, 75);
        analogWrite(ENB2, 75);
        phai();
        dem = 30;
      }
    }



  }
}
