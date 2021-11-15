void demL(int &demL)

{

  counterL++;
  if (((analogRead(A3) > tb) || (analogRead(A4) > tb)) && counterL > 105 )
  {
    demL++;
    counterL = 0;

  }

}
void demX(int &demX)

{
 
  counterX++;
  if (((analogRead(A3) > tb) || (analogRead(A4) > tb)) && counterX > 105 )
  {
    demX++;
    counterX = 0;
  }
  
}
void demT(int &demT)

{
  
  counterT++;
  if (((analogRead(A11) > tb) || (analogRead(A12) > tb)) && counterT > 105)
  {
    demT++;
    counterT = 0;
  }
}
void demP(int &demP)

{

  counterP++;
  if (((analogRead(A11) > tb) || (analogRead(A12) > tb)) && counterP > 105)
  {
    demP++;
    counterP = 0;
  }
  

}
