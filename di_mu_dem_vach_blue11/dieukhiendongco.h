

void tien()
{

  digitalWrite(motorInput11, HIGH);
  digitalWrite(motorInput12, LOW);
  digitalWrite(motorInput13, HIGH);
  digitalWrite(motorInput14, LOW);
}

void lui()
{
  digitalWrite(motorInput11, LOW);
  digitalWrite(motorInput12, HIGH);
  digitalWrite(motorInput13, LOW);
  digitalWrite(motorInput14, HIGH);
}

void phai()
{

  digitalWrite(motorInput21, LOW);
  digitalWrite(motorInput22, HIGH);
  digitalWrite(motorInput23, LOW);
  digitalWrite(motorInput24, HIGH);
}

void trai ()
{

  digitalWrite(motorInput21, HIGH);
  digitalWrite(motorInput22, LOW);
  digitalWrite(motorInput23, HIGH);
  digitalWrite(motorInput24, LOW);
}

void dung1()
{

  digitalWrite(motorInput11, LOW);
  digitalWrite(motorInput12, LOW);
  digitalWrite(motorInput13, LOW);
  digitalWrite(motorInput14, LOW);

  analogWrite(ENA1, 0);
  analogWrite(ENB1, 0);


}
void dung2()
{

  digitalWrite(motorInput21, LOW);
  digitalWrite(motorInput22, LOW);
  digitalWrite(motorInput23, LOW);
  digitalWrite(motorInput24, LOW);
  analogWrite(ENA2, 0);
  analogWrite(ENB2, 0);
}
void tienCham()
{
  digitalWrite(motorInput21, HIGH);
  digitalWrite(motorInput22, LOW);
  digitalWrite(motorInput23, HIGH);
  digitalWrite(motorInput24, LOW);
  analogWrite(ENA1, 50);
  analogWrite(ENB1, 50);
}
void dung()
{
  digitalWrite(motorInput11, LOW);
  digitalWrite(motorInput12, LOW);
  digitalWrite(motorInput13, LOW);
  digitalWrite(motorInput14, LOW);
  analogWrite(ENA1, 0);
  analogWrite(ENB1, 0);
  digitalWrite(motorInput21, LOW);
  digitalWrite(motorInput22, LOW);
  digitalWrite(motorInput23, LOW);
  digitalWrite(motorInput24, LOW);
  analogWrite(ENA2, 0);
  analogWrite(ENB2, 0);
}
void tienTrai()
{
  digitalWrite(motorInput11, HIGH);
  digitalWrite(motorInput12, LOW);
  digitalWrite(motorInput13, HIGH);
  digitalWrite(motorInput14, LOW);
  digitalWrite(motorInput21, HIGH);
  digitalWrite(motorInput22, LOW);
  digitalWrite(motorInput23, HIGH);
  digitalWrite(motorInput24, LOW);
}
