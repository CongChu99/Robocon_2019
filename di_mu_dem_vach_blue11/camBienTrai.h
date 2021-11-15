
void doc_CBTrai()
{
SetTocDo=75;
  tt = TTtrai;
//   digitalWrite(CB4, LOW);
//  digitalWrite(CB3, HIGH);
  Ttrai = 0;
  Strai = 0;
  Trai[0]  = analogRead(camBienTrai1);
  Trai[1]  = analogRead(camBienTrai2);
  Trai[2]  = analogRead(camBienTrai3);
  Trai[3]  = analogRead(camBienTrai4);
  Trai[4]  = analogRead(camBienTrai5);
  Trai[5]  = analogRead(camBienTrai6);
  Trai[6]  = analogRead(camBienTrai7);
  Trai[7]  = analogRead(camBienTrai8);

  for (itrai = 0; itrai <= 7; itrai++)
  {
    if (Trai[itrai] < tb)
    {
      GTtrai[itrai] = 0;
    }
    else
    {
      GTtrai[itrai] = 1;
      Strai = Strai + GTtrai[itrai];
      Ttrai += itrai;
    }
//    Serial.print(GTtrai[itrai]);
  }
  Etrai = float(Ttrai) / Strai;
//  Serial.print("\t");
//  Serial.print(Etrai);
//  Serial.println();
  Errortrai = 3.5 - Etrai;
  if (Ttrai == 0)
  {
    Errortrai = previous_Errortrai;
  }
  Ptrai = Errortrai;
  Itrai = Itrai + previous_Itrai;
  Dtrai = Errortrai - previous_Errortrai;

  PID_value_Trai = (Kp * Ptrai) + (Ki * Itrai) + (Kd * Dtrai);
  previous_Itrai = Itrai;
  previous_Errortrai = Errortrai;
}



void DK_Trai()
{
  int dong_co_trai_Trai = SetTocDo +  PID_value_Trai;
  int dong_co_phai_Trai = SetTocDo - PID_value_Trai;

  dong_co_trai_Trai = constrain(dong_co_trai_Trai, 25, 255);
  dong_co_phai_Trai = constrain(dong_co_phai_Trai, 25, 255);

  analogWrite(ENA2, dong_co_trai_Trai);
  analogWrite(ENB2, dong_co_phai_Trai);

  trai();
//  Serial.print("\t\t");
//  Serial.println(dong_co_trai_Trai);
//  Serial.print("\t");
//  Serial.print(dong_co_phai_Trai);
}
