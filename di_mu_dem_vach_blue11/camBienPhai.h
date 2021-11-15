
void doc_CBP()
{
  tt = TTphai;
SetTocDo=75;
 
//  digitalWrite(CB3, LOW);
//  digitalWrite(CB4, HIGH);
  Tp = 0;
  Sp = 0;
  Phai[0]  = analogRead(camBienPhai1);
  Phai[1]  = analogRead(camBienPhai2);
  Phai[2]  = analogRead(camBienPhai3);
  Phai[3]  = analogRead(camBienPhai4);
  Phai[4]  = analogRead(camBienPhai5);
  Phai[5]  = analogRead(camBienPhai6);
  Phai[6]  = analogRead(camBienPhai7);
  Phai[7]  = analogRead(camBienPhai8);

  for (ip = 0; ip <= 7; ip++)
  {
    if (Phai[ip] < tb)
    {
      GTphai[ip] = 0;
    }
    else
    {
      GTphai[ip] = 1;
      Sp = Sp + GTphai[ip];
      Tp += ip;
    }
//    Serial.print(Phai[ip]);
//    Serial.print("\t");
  }
    Ep = float(Tp) / Sp;
//    Serial.print("\t");
//    Serial.print(Ep);
//    Serial.println();
    Errorp = 3.5 - Ep;
    if (Tp == 0)
    {
      Errorp = previous_Errorp;
    }
    Pp = Errorp;
    Ip = Ip + previous_Ip;
    Dp = Errorp - previous_Errorp;
  
    PID_value_Phai = (Kp * Pp) + (Ki * Ip) + (Kd * Dp);
    previous_Ip = Ip;
    previous_Errorp = Errorp;
  }
  
  
  
  void DK_Phai()
  {
    int dong_co_trai_Phai = SetTocDo - PID_value_Phai;
    int dong_co_phai_Phai = SetTocDo + PID_value_Phai;
  
    dong_co_trai_Phai = constrain(dong_co_trai_Phai, 25, 255);
    dong_co_phai_Phai = constrain(dong_co_phai_Phai, 25, 255);
  
    analogWrite(ENA2, dong_co_trai_Phai);
    analogWrite(ENB2, dong_co_phai_Phai);
  
    phai();
//    Serial.println(dong_co_trai_Phai);
//    Serial.print("\t");
//    Serial.print(dong_co_phai_Phai);
//    Serial.print("\t");
}
