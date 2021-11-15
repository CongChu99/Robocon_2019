
void doc_CBT()
{
  SetTocDo= 200;
  tt = TTtien;

//  digitalWrite(CB2, HIGH);
//  digitalWrite(CB1, LOW);    // dua ve setup

  Tt = 0;
  St = 0;
  Tien[0]  = analogRead(camBienTien1);
  Tien[1]  = analogRead(camBienTien2);
  Tien[2]  = analogRead(camBienTien3);
  Tien[3]  = analogRead(camBienTien4);
  Tien[4]  = analogRead(camBienTien5);
  Tien[5]  = analogRead(camBienTien6);
  Tien[6]  = analogRead(camBienTien7);
  Tien[7]  = analogRead(camBienTien8);

  for (it = 0; it <= 7; it++)
  {
    if (Tien[it] < tb)
    {
      GTtien[it] = 0;
    }
    else
    {
      GTtien[it] = 1;
      St = St + GTtien[it];
      Tt += it;
    }
    //    Serial.print(GTtien[it]);
    //    Serial.print("\t");

  }
  Et = float(Tt) / St;
  //  Serial.print("\t");
  //  Serial.print(Et);
  //  Serial.println();
  Errort = 3.5 - Et;
  if (Tt == 0)
  {
    Errort = previous_Errort;
  }
  else
  {
    Errort = 3.5 - Et;

  }
  //  Serial.println(Errort);
  //  Serial.print("\t");
  Pt = Errort;
  It = It + previous_It;
  Dt = Errort - previous_Errort;

  PID_value_Tien = (Kp * Pt) + (Ki * It) + (Kd * Dt);
  previous_It = It;
  previous_Errort = Errort;
}

void DK_Tien()
{
  double dong_co_trai_Tien = SetTocDo - PID_value_Tien;
  double dong_co_phai_Tien = SetTocDo + PID_value_Tien;
  dong_co_trai_Tien = constrain(dong_co_trai_Tien, 25, 255);
  dong_co_phai_Tien = constrain(dong_co_phai_Tien, 25, 255);

  analogWrite(ENA1, dong_co_trai_Tien);
  analogWrite(ENB1, dong_co_phai_Tien);

  tien();

  //  Serial.println();
  //  Serial.print(PID_value_Tien);
  //  Serial.print("\t\t");
//  Serial.print("\t");
//  Serial.print(dong_co_trai_Tien);
//
//  Serial.print("\t");
//  Serial.print(dong_co_phai_Tien);

}
