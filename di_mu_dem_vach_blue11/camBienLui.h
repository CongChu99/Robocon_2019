
void doc_CBL()
{
  float Kp2 = 20;
  float Kd2 = 30 ;
  float Ki2 = 0.001;
  SetTocDo = 85;
  tt = TTlui;
  //  digitalWrite(CB2, LOW);
  //  digitalWrite(CB1, HIGH);
  Tl = 0;
  Sl = 0;
  SSLui[0]  = analogRead(camBienLui1);
  SSLui[1]  = analogRead(camBienLui2);
  SSLui[2]  = analogRead(camBienLui3);
  SSLui[3]  = analogRead(camBienLui4);
  SSLui[4]  = analogRead(camBienLui5);
  SSLui[5]  = analogRead(camBienLui6);
  SSLui[6]  = analogRead(camBienLui7);
  SSLui[7]  = analogRead(camBienLui8);

  for (iLui = 0; iLui <= 7; iLui++)
  {
    //    Serial.print(SSLui[iLui]);
    //    Serial.print("\t");
    if (SSLui[iLui] < tb)
    {
      GTlui[iLui] = 0;
    }
    else
    {
      GTlui[iLui] = 1;
      Sl = Sl + GTlui[iLui];
      Tl += iLui;
    }

  }
  El = float(Tl) / Sl;
  //  Serial.print("\t");
  //  Serial.print(El);
  //  Serial.println();
  Errorl = 3.5 - El;

  if (Tl == 0)
  {
    Errorl = previous_Errorl;
  }
  Pl = Errorl;
  Il = Il + previous_Il;
  Dl = Errorl - previous_Errorl;

  PID_value_Lui = (Kp2 * Pl) + (Ki2 * Il) + (Kd2 * Dl);
  previous_Il = Il;
  previous_Errorl = Errorl;
}

void DK_Lui()
{
  int dong_co_trai_Lui = SetTocDo + PID_value_Lui;
  int dong_co_phai_Lui = SetTocDo - PID_value_Lui;

  dong_co_trai_Lui = constrain(dong_co_trai_Lui, 25, 255);
  dong_co_phai_Lui = constrain(dong_co_phai_Lui, 25, 255);

  //  analogWrite(ENA1, dong_co_trai_Lui);
  //  analogWrite(ENB1, dong_co_phai_Lui);
  analogWrite(ENA1, dong_co_trai_Lui);
  analogWrite(ENB1, dong_co_phai_Lui);

  lui();
  //  Serial.print("\t\t");
  //  Serial.print(dong_co_trai_Lui);
  //  Serial.print("\t");
  //  Serial.print(dong_co_phai_Lui);
}
