/* @file HelloKeypad.pde
  || @version 1.0
  || @author Alexander Brevig
  || @contact alexanderbrevig@gmail.com
  ||
  || @description
  || | Demonstrates the simplest use of the matrix Keypad library.
  || #
*/
#include <Keypad.h>
int dotre = 500;

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {24, 26, 23, 25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {27, 29, 31}; //connect to the column pinouts of the keypad
char key = 0 ;
int state = 0;
int n = 3;
long Num1, Num2, Number;
char action, temp, temp1, temp2;
boolean result = false;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void QuetBanPhim()
{
  temp = keypad.getKey();
  if (temp == '*')
  {
    Number = Num1 = Num2 = 0; result = false;
  }
  if (temp >= '0' && temp <= '9')
  {
    Number = (Number * 10) + temp - 48; //Pressed twice
  }

}

void DisplayResult()
{
  Serial.println( Number); //Display the result
}

void ChonSan()
{
  while (temp != '#')
  {

    QuetBanPhim();
    Serial.print("Chon San (RED 1 || BLUE 2) " );
    DisplayResult();
  }

  
}
