
#define TIMER_US 10000
int tb = 700;
float Kp = 70;
float Kd = 25 ;
float Ki = 0.001;
int SetTocDo  ;
int demD = 0;
int demN = 0;
int trangthai = 0;
int trangthai2 = 0;
double counterL = 0;
double counterP = 0;
double counterX = 0;
double counterT = 0;


#define DemVachN4 A11
#define DemVachN5 A12

int demVachN[2];
#define DemVachD4 A3
#define DemVachD5 A4

int DemVachD[2];
//----------------------------------------Cam Bien Lui ---------------------------------//

#define camBienLui1 A8
#define camBienLui2 A9
#define camBienLui3 A10
#define camBienLui4 A11
#define camBienLui5 A12
#define camBienLui6 A13
#define camBienLui7 A14
#define camBienLui8 A15
#define CB1 53
int SSLui[8];
int GTlui[8];
int  iLui;
float El, Errorl = 0, previous_Errorl = 0;
float PID_value_Lui = 0;
int Sl, Tl;
float Pl = 0, Il = 0, Dl = 0, previous_Il = 0;
//----------------------------------------Cam Bien Phai ---------------------------------//
#define camBienPhai1 A0
#define camBienPhai2 A1
#define camBienPhai3 A2
#define camBienPhai4 A3
#define camBienPhai5 A4
#define camBienPhai6 A5
#define camBienPhai7 A6
#define camBienPhai8 A7
#define CB4 47
int Phai[8];
int GTphai[8];
int  ip;
float Ep, Errorp = 0, previous_Errorp = 0;
float  PID_value_Phai = 0;
int Tp, Sp;
float Pp = 0, Ip = 0, Dp = 0, previous_Ip = 0;
//----------------------------------------Cam Bien Tien ---------------------------------//
#define camBienTien1 A8
#define camBienTien2 A9
#define camBienTien3 A10
#define camBienTien4 A11
#define camBienTien5 A12
#define camBienTien6 A13
#define camBienTien7 A14
#define camBienTien8 A15
#define CB2 51
int Tien[8];
int GTtien[8];
int  it;
float Et, Errort = 0, previous_Errort = 0;
float PID_value_Tien;
int St, Tt;
float Pt = 0, It = 0, Dt = 0, previous_It = 0;
//----------------------------------------Cam Bien Trai ---------------------------------//
#define camBienTrai1 A0
#define camBienTrai2 A1
#define camBienTrai3 A2
#define camBienTrai4 A3
#define camBienTrai5 A4
#define camBienTrai6 A5
#define camBienTrai7 A6
#define camBienTrai8 A7
#define CB3 49
int Trai[8];
int GTtrai[8];
int  itrai;
float Etrai, Errortrai = 0, previous_Errortrai = 0;
float PID_value_Trai;
int Ttrai, Strai;
float Ptrai = 0, Itrai = 0, Dtrai = 0, previous_Itrai = 0;
//----------------------------DongCo---------------------//
#define ENA1 4
#define motorInput11 5
#define motorInput12 6
#define motorInput13 2
#define motorInput14 17
#define ENB1 3
#define ENA2 12
#define motorInput21 13
#define motorInput22 22
#define motorInput23 10
#define motorInput24 9 // chan cu 23
#define ENB2 11
//-----------------------CTHT---------------------------//
int nutnhan = 35;
int nutnhan2 = 37;

//----------------------SERVO---------------------//
#include<Servo.h>
Servo myservoTrai;
Servo myservoPhai;
Servo myservoDuoi;
Servo myservoCat;
int pos = 0;
int pos1 = 0; 
int period = 10;
int period1 = 500;
int period2 = 1000;
unsigned long time1 = 0;

//----------------------SERVO---------------------//
int tt;
#define  TTtien 1
#define  TTlui  2
#define TTtrai 3
#define TTphai 4
unsigned long Time1, Time2;
//----------------------demline--------------------//

int dem = 0;
int thabong = 0;
int p = 1;
