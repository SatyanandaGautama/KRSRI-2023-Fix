#include <Dynamixel2Arduino.h>
HardwareSerial Serial2(USART2);
#include <Servo.h>
#define DXL_SERIAL   Serial
#define DEBUG_SERIAL Serial2
const uint8_t DXL_DIR_PIN = PA4;
#define CW_ANGLE_LIMIT_ADDR         6
#define CCW_ANGLE_LIMIT_ADDR        8
#define ANGLE_LIMIT_ADDR_LEN        2
#define OPERATING_MODE_ADDR_LEN     2
#define TORQUE_ENABLE_ADDR          24
#define TORQUE_ENABLE_ADDR_LEN      1
#define LED_ADDR                    25
#define LED_ADDR_LEN                1
#define GOAL_POSITION_ADDR          30
#define GOAL_POSITION_ADDR_LEN      2
#define PRESENT_POSITION_ADDR       36
#define PRESENT_POSITION_ADDR_LEN   2
#define TIMEOUT 10    //default communication timeout 10ms

Servo capit, pegangan;
const float DXL_PROTOCOL_VERSION = 1.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);
int move_counter = 0;
float cx = 37.5;
int fm = 58;
int tb = 80;
bool arahgerak;
bool pidchoice;
int legoffset[] = {45, 135, 225, 315};
int height = -75;
int height2 = -75;
float z;
float sdtcoxa, sdtcoxa1, sdtcoxa2, sdtcoxa3, sdtcoxa4, sdtrotate, sdtfemur, sdttibia, theta2, theta3, angle1, angle2, P, c, alas, alpha, beta;
int td1 = 15; //30 //kiridikit(1)
int td2 = 15;
int ts = 15;
int td = 20;
int tp = 35;
int tk = 27;
int tk2 = 30;
int tpr = 15;
int tprUp = 12;
int rotdelay = 70;
int movecounter = 0;
int tb1 = 20;
int tr = 21;
int sudut1, sudut2, sudut3, sudut4, sudutx;
int tbk = 15;
float xFR , yFR , zFR , xFL , yFL , zFL, xBL , yBL , zBL, xBR , yBR , zBR;
void setup() {
  Serial2.begin(115200);   //Set debugging port baudrate to 115200bps
  Serial.setTx(PA9);
  Serial.setRx(PA10);
  dxl.begin(57600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  delay(1000);
  //  capit.attach(PB14);
  //  pinMode(PB9, OUTPUT);
  //  capit.write(150); //55
  //  turuncapit();
  //  delay(5000);
  //  ambilK1Fx();
  //  delay(2000);
  //  ambilK1();
  //  ambilK1Fix();
  //  standby1();
  //  turuncapit();
  //  delay(4000);
  //  ambilK1();
  //  delay(2000);
  //  nyapit();
  //  delay(2000);
  //  balik();
  //  delay(2000);
  //  standby();
  //  delay(2000);
}

void standby() {
  FR(55, 55, 0, 0);
  BL(-55, -55, 0, 0);
  FL(-55, 55, 0, 0);
  BR(55, -55, 0, 0);
}

void loop() {
  dxl.setGoalVelocity(1, 0, UNIT_RAW);
  dxl.setGoalPosition(1, 60, UNIT_DEGREE);
  dxl.setGoalVelocity(2, 1000, UNIT_RAW);
  dxl.setGoalPosition(2, 60, UNIT_DEGREE);
  delay(500);
  dxl.setGoalVelocity(1, 0, UNIT_RAW);
  dxl.setGoalPosition(1, 150, UNIT_DEGREE);
  dxl.setGoalVelocity(2, 1000, UNIT_RAW);
  dxl.setGoalPosition(2, 150, UNIT_DEGREE);
  delay(500);
}


void Yaw_15() {
  xFL = 24;//13
  yFL = 79;//85
  xFR = 79;//85
  yFR = 24;//13
  xBR = 24;//13
  yBR = 79;//85
  xBL = 79;//85
  yBL = 24;//13
  FRAuto(xFR, yFR, -75);
  BLAuto(-(xBL), -(yBL), -75);
  FLAuto(-(xFL), yFL, -75);
  BRAuto(xBR, -(yBR), -75);
}

void Pitch10() {
  xFL = 36;//96
  yFL = 79;//13
  zFL = 61;//50
  xFR = 64;//1
  yFR = 24;//85
  zFR = 96;//85
  xBR = 10;//70
  yBR = 79;//13
  zBR = 87;//97
  xBL = 90;//25
  yBL = 24;//85
  zBL = 51;//63
  FRAuto(xFR, yFR, -(zFR));
  BLAuto(-(xBL), -(yBL), -(zBL));
  FLAuto(-(xFL), yFL, -(zFL));
  BRAuto(xBR, -(yBR), -(zBR));
}

void Yaw15() {
  xFL = 79;//13
  yFL = 24;//85
  xFR = 24;//85
  yFR = 79;//13
  xBR = 79;//13
  yBR = 24;//85
  xBL = 24;//85
  yBL = 79;//13
  FRAuto(xFR, yFR, -75);
  BLAuto(-(xBL), -(yBL), -75);
  FLAuto(-(xFL), yFL, -75);
  BRAuto(xBR, -(yBR), -75);
}

void Pitch_10() {
  xFL = 64;//96
  yFL = 24;//13
  zFL = 96;//50
  xFR = 36;//1
  yFR = 79;//85
  zFR = 61;//85
  xBR = 90;//70
  yBR = 24;//13
  zBR = 51;//97
  xBL = 10;//25
  yBL = 79;//85
  zBL = 87;//63
  FRAuto(xFR, yFR, -(zFR));
  BLAuto(-(xBL), -(yBL), -(zBL));
  FLAuto(-(xFL), yFL, -(zFL));
  BRAuto(xBR, -(yBR), -(zBR));
}

void stretching() {
  standby();
  delay(500);
  Yaw15();
  delay(500);
  Pitch_10(); //jadi(-)
  delay(500);
  Yaw15();
  delay(500);
  standby();
  delay(500);
  Yaw_15();
  delay(500);
  Pitch10();//jadi(+)
  delay(500);
  Yaw_15();
  delay(500);
}
void standbyTransisi2() { //tanpa standby
  float FRcx = 193;// to 195
  float FRfm = 164;//to 181
  float FRtb = 230.5;//to 227.5
  float BLcx = 201;//to 203
  float BLfm = 118;//to 91
  float BLtb = 198;//to 189
  float FLcx = 85;// to 85
  float FLfm = 164;//to 184
  float FLtb = 250.5;//to 250.5
  float BRcx = 123;//to 123
  float BRfm = 120;//to 98
  float BRtb = 170;//to 167
  for (int i = 0; i <= 49; i++) {
    kanan_atas(FRcx, FRfm, FRtb);
    kiri_atas(FLcx, FLfm, FLtb);
    kiri_bawah(BLcx, BLfm, BLtb);
    kanan_bawah(BRcx, BRfm, BRtb);
    FRcx -= 0.04;
    FRfm += 0.34;
    FRtb -= 0.06;
    BLcx += 0.04;
    BLfm -= 0.54;
    BLtb -= 0.18;
    FLfm += 0.4;
    BRfm -= 0.44;
    BRtb -= 0.06;
    delay(8);
  }
}



void standbyTransisi2Fxz() { //tanpa standby
  float FRcx = 193;// to 192
  float FRfm = 164;//to 181
  float FRtb = 230.5;//to 227.5
  float BLcx = 201;//to 203
  float BLfm = 118;//to 91
  float BLtb = 198;//to 189
  float FLcx = 85;// to 85
  float FLfm = 164;//to 184
  float FLtb = 250.5;//to 250.5
  float BRcx = 123;//to 123
  float BRfm = 120;//to 98
  float BRtb = 170;//to 167
  for (int i = 0; i <= 49; i++) {
    kanan_atas(FRcx, FRfm, FRtb);
    kiri_atas(FLcx, FLfm, FLtb);
    kiri_bawah(BLcx, BLfm, BLtb);
    kanan_bawah(BRcx, BRfm, BRtb);
    FRcx -= 0.02;
    FRfm += 0.34;
    FRtb -= 0.06;
    BLcx += 0.04;
    BLfm -= 0.54;
    BLtb -= 0.18;
    FLfm += 0.4;
    BRfm -= 0.44;
    BRtb -= 0.06;
    delay(8);
  }
}

void standbyTransisi2fix() { //dgn standby
  float FRcx = 206;// to 209
  float FRfm = 160;//to 180

  float FLcx = 86;// to 76
  float FLfm = 164;//to 184

  float BRcx = 122;//to 122
  float BRfm = 119;//to 97
  float BRtb = 170;//to 168

  float BLcx = 173;//to 173
  float BLfm = 119;//to 97
  float BLtb = 183;//to 181
  for (int i = 0; i <= 49; i++) {
    kanan_atas(FRcx, FRfm, 246.5);
    kiri_atas(FLcx, FLfm, 249.5);
    kiri_bawah(BLcx, BLfm, BLtb);
    kanan_bawah(BRcx, BRfm, BRtb);
    FRcx += 0.06;
    FRfm += 0.4;
    FLfm += 0.4;
    BLfm -= 0.44;
    BLtb -= 0.04;
    BRfm -= 0.44;
    BRtb -= 0.04;
    delay(10);
  }
}

void standbyTransisi1() {
  float FRcx = 193;// to 192
  float FRfm = 159;//to 161
  float FRtb = 230.5;//to 227.5
  float BLcx = 211;//to 203
  float BLfm = 149;//to 112
  float BLtb = 245;//to 191
  float FLcx = 85;// to 85
  float FLfm = 159;//to 164
  float FLtb = 250.5;//to 250.5
  float BRcx = 113;//to 123
  float BRfm = 150;//to 120
  float BRtb = 223;//to 169
  for (int i = 0; i <= 49; i++) {
    kanan_atas(FRcx, FRfm, FRtb);
    kiri_atas(FLcx, FLfm, FLtb);
    kiri_bawah(BLcx, BLfm, BLtb);
    kanan_bawah(BRcx, BRfm, BRtb);
    FRcx -= 0.02;
    FRfm += 0.04;
    FRtb -= 0.06;
    BLcx -= 0.16;
    BLfm -= 0.74;
    BLtb -= 1.08;
    FLfm += 0.1;
    BRcx += 0.2;
    BRfm -= 0.6;
    BRtb -= 1.08;
    delay(8);
  }
}




void standbyTransisi2Fx() {
  float FRcx = 193;// to 192
  float FRfm = 164;//to 181
  float FRtb = 230.5;//to 227.5
  float BLcx = 201;//to 203
  float BLfm = 118;//to 91
  float BLtb = 198;//to 189
  float FLcx = 85;// to 85
  float FLfm = 164;//to 184
  float FLtb = 250.5;//to 250.5
  float BRcx = 123;//to 123
  float BRfm = 120;//to 98
  float BRtb = 170;//to 167
  for (int i = 0; i <= 49; i++) {
    kanan_atas(FRcx, FRfm, FRtb);
    kiri_atas(FLcx, FLfm, FLtb);
    kiri_bawah(BLcx, BLfm, BLtb);
    kanan_bawah(BRcx, BRfm, BRtb);
    FRcx -= 0.02;
    FRfm += 0.34;
    FRtb -= 0.06;
    BLcx += 0.04;
    BLfm -= 0.54;
    BLtb -= 0.18;
    FLfm += 0.4;
    BRfm -= 0.44;
    BRtb -= 0.06;
    delay(8);
  }
}

void jalanpecah1(float lbr) { //Gerakan lambat, Sudut Belok = 5
  movecounter++;
  if (movecounter == 1) {
    FR(55, 55, 22, lbr);
    BL(-55, -55, 35, lbr);
    FL(-55, 55, 0, lbr);
    BR(55, -55, 0, lbr);
    delay(tp);

    FR(69.44, 55, 19.56, lbr);
    BL(-40.56, -55, 31.11, lbr);
    FL(-50, 55, 0, lbr);
    BR(59.98, -55, 0, lbr);
    delay(tp);

    FR(80.56, 55, 12.22, lbr);
    BL(-29.44, -55, 19.44, lbr);
    FL(-45.16, 55, 0, lbr);
    BR(64.84, -55, 0, lbr);
    delay(tp);

    FR(85, 55, 0, lbr);
    BL(-25, -55, 0, lbr);
    FL(-40.56, 55, 0, lbr);
    BR(69.44, -55, 0, lbr);
    delay(tp);

    FR(84.47, 55, 0, lbr);
    BL(-25.53, -55, 0, lbr);
    FL(-36.32, 55, 0, lbr);
    BR(73.68, -55, 0, lbr);
    delay(tp);

    FR(82.94, 55, 0, lbr);
    BL(-27.06, -55, 0, lbr);
    FL(-32.57, 55, 0, lbr);
    BR(77.43, -55, 0, lbr);
    delay(tp);

    FR(80.56, 55, 0, lbr);
    BL(-29.44, -55, 0, lbr);
    FL(-29.44, 55, 0, lbr);
    BR(80.56, -55, 0, lbr);
    delay(tp);

    FR(77.43, 55, 0, lbr);
    BL(-32.57, -55, 0, lbr);
    FL(-27.06, 55, 0, lbr);
    BR(82.94, -55, 0, lbr);
    delay(tp);

    FR(73.68, 55, 0, lbr);
    BL(-36.32, -55, 0, lbr);
    FL(-25.53, 55, 0, lbr);
    BR(84.47, -55, 0, lbr);
    delay(tp);

    FR(69.44, 55, 0, lbr);
    BL(-40.56, -55, 0, lbr);
    FL(-25, 55, 0, lbr);
    BR(85, -55, 0, lbr);
    delay(tp);

    FR(64.84, 55, 0,  lbr);
    BL(-45.16, -55, 0, lbr);
    FL(-29.44, 55, 12.22, lbr);
    BR(80.56, -55, 19.44, lbr);
    delay(tp);

    FR(59.98, 55, 0, lbr);
    BL(-50, -55, 0, lbr);
    FL(-40.56, 55, 19.56, lbr);
    BR(69.44, -55, 31.11, lbr);
    delay(tp);
  }
  else if (movecounter == 2) {
    FR(55, 55, 0, lbr);
    BL(-55, -55, 0, lbr);
    FL(-55, 55, 22, lbr);
    BR(55, -55, 35, lbr);
    delay(tp);

    FR(50, 55, 0, lbr);
    BL(-59.98, -55, 0, lbr);
    FL(-69.44, 55, 19.56, lbr);
    BR(40.56, -55, 31.11, lbr);
    delay(tp);

    FR(45.16, 55, 0, lbr);
    BL(-64.84, -55, 0, lbr);
    FL(-80.56, 55, 12.22, lbr);
    BR(29.44, -55, 19.44, lbr);
    delay(tp);

    FR(40.56, 55, 0, lbr);
    BL(-69.44, -55, 0, lbr);
    FL(-85, 55, 0, lbr);
    BR(25, -55, 0, lbr);
    delay(tp);

    FR(36.32, 55, 0, lbr);
    BL(-73.68, -55, 0, lbr);
    FL(-84.47, 55, 0, lbr);
    BR(25.53, -55, 0, lbr);
    delay(tp);

    FR(32.57, 55, 0, lbr);
    BL(-77.43, -55, 0, lbr);
    FL(-82.94, 55, 0, lbr);
    BR(27.06, -55, 0, lbr);
    delay(tp);

    FR(29.44, 55, 0, lbr);
    BL(-80.56, -55, 0, lbr);
    FL(-80.56, 55, 0, lbr);
    BR(29.44, -55, 0, lbr);
    delay(tp);

    FR(27.06, 55, 0, lbr);
    BL(-82.94, -55, 0, lbr);
    FL(-77.43, 55, 0, lbr);
    BR(32.57, -55, 0, lbr);
    delay(tp);

    FR(25.53, 55, 0, lbr);
    BL(-84.47, -55, 0, lbr);
    FL(-73.68, 55, 0, lbr);
    BR(36.32, -55, 0, lbr);
    delay(tp);

    FR(25, 55, 0, lbr);
    BL(-85, -55, 0, lbr);
    FL(-69.44, 55, 0, lbr);
    BR(40.56, -55, 0, lbr);
    delay(tp);

    FR(29.44, 55, 12.22, lbr);
    BL(-80.56, -55, 19.44, lbr);
    FL(-64.48, 55, 0, lbr);
    BR(45.16, -55, 0, lbr);
    delay(tp);

    FR(40.56, 55, 19.56, lbr);
    BL(-69.44, -55, 31.11, lbr);
    FL(-59.98, 55, 0, lbr);
    BR(50, -55, 0, lbr);
    delay(tp);
    movecounter = 0;
  }
}

//Angkat 1 cm, panjang 3 cm
void majucepat() { //Sudut belok = 5;
  FR(85, 55, 0, 0);
  BL(-25, -55, 0, 0);
  FL(-52, 55, 0, 0);
  BR(58, -55, 0, 0);
  delay(td1);

  FR(80.78, 55, 0, 0);
  BL(-29.22, -55, 0, 0);
  FL(-47.78, 55, 0, 0);
  BR(62.22, -55, 0, 0);
  delay(td1);

  FR(71.5, 55, 0, 0);
  BL(-38.5, -55, 0, 0);
  FL(-38.5, 55, 0, 0);
  BR(71.5, -55, 0, 0);
  delay(td1);

  FR(62.22, 55, 0, 0);
  BL(-47.78, -55, 0, 0);
  FL(-29.22, 55, 0, 0);
  BR(80.78, -55, 0, 0);
  delay(td1);

  FR(58, 55, 0, 0);
  BL(-52, -55, 0, 0);
  FL(-25, 55, 0, 0);
  BR(85, -55, 0, 0);
  delay(td1);

  FR(56.5, 55, 0, 0);
  BL(-53.5, -55, 0, 0);
  FL(-40, 55, 7, 0);
  BR(70, -55, 7, 0);
  delay(td1);

  FR(55, 55, 0, 0);
  BL(-55, -55, 0, 0);
  FL(-55, 55, 10, 0);
  BR(55, -55, 10, 0);
  delay(td1);

  FR(53.5, 55, 0, 0);
  BL(-56.5, -55, 0, 0);
  FL(-70, 55, 7, 0);
  BR(40, -55, 7, 0);
  delay(td1);

  FR(52, 55, 0, 0);
  BL(-58, -55, 0, 0);
  FL(-85, 55, 0, 0);
  BR(25, -55, 0, 0);
  delay(td2);

  //////////////////////////////////////////

  FR(47.78, 55, 0, 0);
  BL(-62.22, -55, 0, 0);
  FL(-80.78, 55, 0, 0);
  BR(29.22, -55, 0, 0);
  delay(td1);

  FR(38.5, 55, 0, 0);
  BL(-71.5, -55, 0, 0);
  FL(-71.5, 55, 0, 0);
  BR(38.5, -55, 0, 0);
  delay(td1);

  FR(29.22, 55, 0, 0);
  BL(-80.78, -55, 0, 0);
  FL(-62.22, 55, 0, 0);
  BR(47.78, -55, 0, 0);
  delay(td1);
  /////////////////////////////////////////////////
  FR(25, 55, 0, 0);
  BL(-85, -55, 0, 0);
  FL(-58, 55, 0, 0);
  BR(52, -55, 0, 0);
  delay(td2);

  FR(40, 55, 7, 0);
  BL(-70, -55, 7, 0);
  FL(-56.5, 55, 0, 0);
  BR(53.5, -55, 0, 0);
  delay(td2);

  FR(55, 55, 10, 0);
  BL(-55, -55, 10, 0);
  FL(-55, 55, 0, 0);
  BR(55, -55, 0, 0);
  delay(td2);

  FR(70, 55, 7, 0);
  BL(-40, -55, 7, 0);
  FL(-53.5, 55, 0, 0);
  BR(56.5, -55, 0, 0);
  delay(td2);
}

void geraklambat() { //Gerakan lambat
  //Maju 3cm &  angkat 3cm
  /////delay 30 atau 25
  static int steps = 0;
  switch (steps)
  {
    //FR & BL Seret, FL & BR Swing
    case 0:
      FR(85, 55, 0, 0);
      BL(-25, -55, 0, 0);
      FL(-45, 55, 0, 0);
      BR(65, -55, 0, 0);
      delay(td1);
      break;
    case 1:
      FR(80, 55, 0, 0);
      BL(-30, -55, 0, 0);
      FL(-40, 55, 0, 0);
      BR(70, -55, 0, 0);
      delay(td1);
      break;
    case 2:
      FR(75, 55, 0, 0);
      BL(-35, -55, 0, 0);
      FL(-35, 55, 0, 0);
      BR(75, -55, 0, 0);
      delay(td1);
      break;
    case 3:
      FR(70, 55, 0, 0);
      BL(-40, -55, 0, 0);
      FL(-30, 55, 0, 0);
      BR(80, -55, 0, 0);
      delay(td1);
      break;
    case 4:
      FR(65, 55, 0, 0);
      BL(-45, -55, 0, 0);
      FL(-25, 55, 0, 0);
      BR(85, -55, 0, 0);
      delay(td1);
      break;
    case 5:
      FR(60, 55, 0, 0);
      BL(-50, -55, 0, 0);
      FL(-40, 55, 7, 0);
      BR(70, -55, 7, 0);
      delay(td1);
      break;
    case 6:
      FR(55, 55, 0, 0);
      BL(-55, -55, 0, 0);
      FL(-55, 55, 10, 0);
      BR(55, -55, 10, 0);
      delay(td2);
      break;
    case 7:
      FR(50, 55, 0, 0);
      BL(-60, -55, 0, 0);
      FL(-70, 55, 7, 0);
      BR(40, -55, 7, 0);
      delay(td2);
      break;
    case 8:
      FR(45, 55, 0, 0);
      BL(-65, -55, 0, 0);
      FL(-85, 55, 0, 0);
      BR(25, -55, 0, 0);
      delay(td2);
      break;
    case 9:
      FR(40, 55, 0, 0);
      BL(-70, -55, 0, 0);
      FL(-80, 55, 0, 0);
      BR(30, -55, 0, 0);
      delay(td2);
      break;
    case 10:
      FR(35, 55, 0, 0);
      BL(-75, -55, 0, 0);
      FL(-75, 55, 0, 0);
      BR(35, -55, 0, 0);
      delay(td2);
      break;
    case 11:
      FR(30, 55, 0, 0);
      BL(-80, -55, 0, 0);
      FL(-70, 55, 0, 0);
      BR(40, -55, 0, 0);
      delay(td2);
      break;
    case 12:
      FR(25, 55, 0, 0);
      BL(-85, -55, 0, 0);
      FL(-65, 55, 0, 0);
      BR(45, -55, 0, 0);
      delay(td2);
      break;
    ///////
    case 13:
      FR(40, 55, 7, 0);
      BL(-70, -55, 7, 0);
      FL(-60, 55, 0, 0);
      BR(50, -55, 0, 0);
      delay(td2);
      break;
    case 14:
      FR(55, 55, 10, 0);
      BL(-55, -55, 10, 0);
      FL(-55, 55, 0, 0);
      BR(55, -55, 0, 0);
      delay(td2);
      break;
    case 15:
      FR(70, 55, 7, 0);
      BL(-40, -55, 7, 0);
      FL(-50, 55, 0, 0);
      BR(60, -55, 0, 0);
      delay(td2);
      break;
  }
  steps++;
  if (steps > 15)steps = 0;
}

void jalanpecah1() { //Gerakan lambat, Sudut Belok = 5
  static int steps = 0;
  switch (steps)
  {
    //FR & BL Seret, FL & BR Swing
    case 0:
      FR(85, 55, 0, 0);
      BL(-25, -55, 0, 0);
      FL(-40.56, 55, 0, 0);
      BR(69.44, -55, 0, 0);
      delay(td1);
      break;
    case 1:
      FR(84.47, 55, 0, 0);
      BL(-25.53, -55, 0, 0);
      FL(-36.32, 55, 0, 0);
      BR(73.68, -55, 0, 0);
      delay(td1);
      break;
    case 2:
      FR(82.94, 55, 0, 0);
      BL(-27.06, -55, 0, 0);
      FL(-32.57, 55, 0, 0);
      BR(77.43, -55, 0, 0);
      delay(td1);
      break;
    case 3:
      FR(80.56, 55, 0, 0);
      BL(-29.44, -55, 0, 0);
      FL(-29.44, 55, 0, 0);
      BR(80.56, -55, 0, 0);
      delay(td1);
      break;
    case 4:
      FR(77.43, 55, 0, 0);
      BL(-32.57, -55, 0, 0);
      FL(-27.06, 55, 0, 0);
      BR(82.94, -55, 0, 0);
      delay(td1);
      break;
    case 5:
      FR(73.68, 55, 0, 0);
      BL(-36.32, -55, 0, 0);
      FL(-25.53, 55, 0, 0);
      BR(84.47, -55, 0, 0);
      delay(td1);
      break;
    case 6:
      FR(69.44, 55, 0, 0);
      BL(-40.56, -55, 0, 0);
      FL(-25, 55, 0, 0);
      BR(85, -55, 0, 0);
      delay(td2);
      break;
    case 7:
      FR(64.84, 55, 0, 0);
      BL(-45.16, -55, 0, 0);
      FL(-29.44, 55, 16.67, 0);
      BR(80.56, -55, 16.67, 0);
      delay(td2);
      break;
    case 8:
      FR(59.98, 55, 0, 0);
      BL(-50, -55, 0, 0);
      FL(-40.56, 55, 26.67, 0);
      BR(69.44, -55, 26.67, 0);
      delay(td2);
      break;
    case 9:
      FR(55, 55, 0, 0);
      BL(-55, -55, 0, 0);
      FL(-55, 55, 30, 0);
      BR(55, -55, 30, 0);
      delay(td2);
      break;
    case 10:
      FR(50, 55, 0, 0);
      BL(-59.98, -55, 0, 0);
      FL(-69.44, 55, 26.67, 0);
      BR(40.56, -55, 26.67, 0);
      delay(td2);
      break;
    case 11:
      FR(45.16, 55, 0, 0);
      BL(-64.84, -55, 0, 0);
      FL(-80.56, 55, 16.67, 0);
      BR(29.44, -55, 16.67, 0);
      delay(td2);
      break;
    case 12:
      FR(40.56, 55, 0, 0);
      BL(-69.44, -55, 0, 0);
      FL(-85, 55, 0, 0);
      BR(25, -55, 0, 0);
      delay(td2);
      break;
    ///////
    case 13:
      FR(36.32, 55, 0, 0);
      BL(-73.68, -55, 0, 0);
      FL(-84.47, 55, 0, 0);
      BR(25.53, -55, 0, 0);
      delay(td2);
      break;
    case 14:
      FR(32.57, 55, 0, 0);
      BL(-77.43, -55, 0, 0);
      FL(-82.94, 55, 0, 0);
      BR(27.06, -55, 0, 0);
      delay(td2);
      break;
    case 15:
      FR(29.44, 55, 0, 0);
      BL(-80.56, -55, 0, 0);
      FL(-80.56, 55, 0, 0);
      BR(29.44, -55, 0, 0);
      delay(td2);
      break;
    case 16:
      FR(27.06, 55, 0, 0);
      BL(-82.94, -55, 0, 0);
      FL(-77.43, 55, 0, 0);
      BR(32.57, -55, 0, 0);
      delay(td2);
      break;
    case 17:
      FR(25.53, 55, 0, 0);
      BL(-84.47, -55, 0, 0);
      FL(-73.68, 55, 0, 0);
      BR(36.32, -55, 0, 0);
      delay(td2);
      break;
    case 18:
      FR(25, 55, 0, 0);
      BL(-85, -55, 0, 0);
      FL(-69.44, 55, 0, 0);
      BR(40.56, -55, 0, 0);
      delay(td2);
      break;
    case 19:
      FR(29.44, 55, 16.67, 0);
      BL(-80.56, -55, 16.67, 0);
      FL(-64.48, 55, 0, 0);
      BR(45.16, -55, 0, 0);
      delay(td2);
      break;
    case 20:
      FR(40.56, 55, 26.67, 0);
      BL(-69.44, -55, 26.67, 0);
      FL(-59.98, 55, 0, 0);
      BR(50, -55, 0, 0);
      delay(td2);
      break;
    case 21:
      FR(55, 55, 30, 0);
      BL(-55, -55, 30, 0);
      FL(-55, 55, 0, 0);
      BR(55, -55, 0, 0);
      delay(td2);
      break;
    case 22:
      FR(69.44, 55, 26.67, 0);
      BL(-40.56, -55, 26.67, 0);
      FL(-50, 55, 0, 0);
      BR(59.98, -55, 0, 0);
      delay(td2);
      break;
    case 23:
      FR(80.56, 55, 16.67, 0);
      BL(-29.44, -55, 16.67, 0);
      FL(-45.16, 55, 0, 0);
      BR(64.84, -55, 0, 0);
      delay(td2);
      break;
  }
  steps++;
  if (steps > 23)steps = 0;
}




void jalanbatu1() { //Gerakan lambat naik 3.5 cm
  //Maju 3cm &  angkat 3cm
  /////delay 30 atau 25
  static int steps = 0;
  switch (steps)
  {
    case 0:
      FR(85, 55, 0, 0);
      BL(-25, -55, 0, 0);
      FL(-40.56, 55, 0, 0);
      BR(69.44, -55, 0, 0);
      delay(td2);
      break;
    case 1:
      FR(80.97, 55, 0, 0);
      BL(-29.03, -55, 0, 0);
      FL(-36.53, 55, 0, 0);
      BR(73.47, -55, 0, 0);
      delay(td2);
      break;
    case 2:
      FR(73.47, 55, 0, 0);
      BL(-36.53, -55, 0, 0);
      FL(-29.03, 55, 0, 0);
      BR(80.97, -55, 0, 0);
      delay(td2);
      break;
    case 3:
      FR(69.44, 55, 0, 0);
      BL(-40.56, -55, 0, 0);
      FL(-25, 55, 0, 0);
      BR(85, -55, 0, 0);
      delay(td2);
      break;
    case 4:
      FR(64.84, 55, 0, 0);
      BL(-45.16, -55, 0, 0);
      FL(-29.44, 55, 19.44, 0);
      BR(80.56, -55, 19.44, 0);
      delay(td2);
      break;
    case 5:
      FR(59.98, 55, 0, 0);
      BL(-50, -55, 0, 0);
      FL(-40.56, 55, 31.11, 0);
      BR(69.44, -55, 31.11, 0);
      delay(td2);
      break;
    case 6:
      FR(55, 55, 0, 0);
      BL(-55, -55, 0, 0);
      FL(-55, 55, 35, 0);
      BR(55, -55, 35, 0);
      delay(td2);
      break;
    case 7:
      FR(50, 55, 0, 0);
      BL(-59.98, -55, 0, 0);
      FL(-69.44, 55, 31.11, 0);
      BR(40.56, -55, 31.11, 0);
      delay(td2);
      break;
    case 8:
      FR(45.16, 55, 0, 0);
      BL(-64.84, -55, 0, 0);
      FL(-80.56, 55, 19.44, 0);
      BR(29.44, -55, 19.44, 0);
      delay(td2);
      break;
    case 9:
      FR(40.56, 55, 0, 0);
      BL(-69.44, -55, 0, 0);
      FL(-85, 55, 0, 0);
      BR(25, -55, 0, 0);
      delay(td2);
      break;

    case 10:
      FR(36.53, 55, 0, 0);
      BL(-73.47, -55, 0, 0);
      FL(-80.97, 55, 0, 0);
      BR(29.03, -55, 0, 0);
      delay(td2);
      break;

    case 11:
      FR(29.03, 55, 0, 0);
      BL(-80.97, -55, 0, 0);
      FL(-73.47, 55, 0, 0);
      BR(36.53, -55, 0, 0);
      delay(td2);
      break;

    case 12:
      FR(25, 55, 0, 0);
      BL(-85, -55, 0, 0);
      FL(-69.44, 55, 0, 0);
      BR(40.56, -55, 0, 0);
      delay(td2);
      break;
    case 13:
      FR(29.44, 55, 19.44, 0);
      BL(-80.56, -55, 19.44, 0);
      FL(-64.48, 55, 0, 0);
      BR(45.16, -55, 0, 0);
      delay(td2);
      break;
    case 14:
      FR(40.56, 55, 31.11, 0);
      BL(-69.44, -55, 31.11, 0);
      FL(-59.98, 55, 0, 0);
      BR(50, -55, 0, 0);
      delay(td2);
      break;
    case 15:
      FR(55, 55, 35, 0);
      BL(-55, -55, 35, 0);
      FL(-55, 55, 0, 0);
      BR(55, -55, 0, 0);
      delay(td2);
      break;
    case 16:
      FR(69.44, 55, 31.11, 0);
      BL(-40.56, -55, 31.11, 0);
      FL(-50, 55, 0, 0);
      BR(59.98, -55, 0, 0);
      delay(td2);
      break;
    case 17:
      FR(80.56, 55, 19.44, 0);
      BL(-29.44, -55, 19.44, 0);
      FL(-45.16, 55, 0, 0);
      BR(64.84, -55, 0, 0);
      delay(td2);
      break;
  }
  steps++;
  if (steps > 17)steps = 0;
}



void cobacepat() { //lumayan lebih cepat
  static int steps = 0;
  switch (steps)
  {
    case 0:
      FR(85, 55, 0, 0);
      BL(-25, -55, 0, 0);
      FL(-45, 55, 0, 0);
      BR(65, -55, 0, 0);
      delay(td1);
      break;
    case 1:
      FR(75, 55, 0, 0);
      BL(-35, -55, 0, 0);
      FL(-35, 55, 0, 0);
      BR(75, -55, 0, 0);
      delay(td1);
      break;
    case 2:
      FR(65, 55, 0, 0);
      BL(-45, -55, 0, 0);
      FL(-25, 55, 0, 0);
      BR(85, -55, 0, 0);
      delay(td1);
      break;
    case 3:
      FR(60, 55, 0, 0);
      BL(-50, -55, 0, 0);
      FL(-40, 55, 10.6, 0);
      BR(70, -55, 10.6, 0);
      delay(td1);
      break;
    case 4:
      FR(55, 55, 0, 0);
      BL(-55, -55, 0, 0);
      FL(-55, 55, 15, 0);
      BR(55, -55, 15, 0);
      delay(td2);
      break;
    case 5:
      FR(50, 55, 0, 0);
      BL(-60, -55, 0, 0);
      FL(-70, 55, 10.6, 0);
      BR(40, -55, 10.6, 0);
      delay(td2);
      break;
    case 6:
      FR(45, 55, 0, 0);
      BL(-65, -55, 0, 0);
      FL(-85, 55, 0, 0);
      BR(25, -55, 0, 0);
      delay(td2);
      break;
    case 7:
      FR(35, 55, 0, 0);
      BL(-75, -55, 0, 0);
      FL(-75, 55, 0, 0);
      BR(35, -55, 0, 0);
      delay(td2);
    case 8:
      FR(25, 55, 0, 0);
      BL(-85, -55, 0, 0);
      FL(-65, 55, 0, 0);
      BR(45, -55, 0, 0);
      delay(td2);
      break;
    case 9:
      FR(40, 55, 10.6, 0);
      BL(-70, -55, 10.6, 0);
      FL(-60, 55, 0, 0);
      BR(50, -55, 0, 0);
      delay(td2);
      break;
    case 10:
      FR(55, 55, 15, 0);
      BL(-55, -55, 15, 0);
      FL(-55, 55, 0, 0);
      BR(55, -55, 0, 0);
      delay(td2);
      break;
    case 11:
      FR(70, 55, 10.6, 0);
      BL(-40, -55, 10.6, 0);
      FL(-50, 55, 0, 0);
      BR(60, -55, 0, 0);
      delay(td2);
      break;
  }
  steps++;
  if (steps > 11)steps = 0;
}





void majudikit() {
  static int steps = 0;
  switch (steps)
  {
    case 0:
      FR(65, 55, 0, 0);
      BL(-45, -55, 0, 0);
      FL(-50.19, 55, 0, 0);
      BR(59.81, -55, 0, 0);
      delay(td2);
      break;
    case 1:
      FR(62.41, 55, 0, 0);
      BL(-47.59, -55, 0, 0);
      FL(-47.59, 55, 0, 0);
      BR(62.41, -55, 0, 0);
      delay(td2);
      break;
    case 2:
      FR(59.81, 55, 0, 0);
      BL(-50.19, -55, 0, 0);
      FL(-45, 55, 0, 0);
      BR(65, -55, 0, 0);
      delay(td2);
      break;
    case 3:
      FR(58.28, 55, 0, 0);
      BL(-51.72, -55, 0, 0);
      FL(-46.48, 55, 11.11, 0);
      BR(63.52, -55, 11.11, 0);
      delay(td2);
      break;
    case 4:
      FR(56.66, 55, 0, 0);
      BL(-53.34, -55, 0, 0);
      FL(-50.19, 55, 17.78, 0);
      BR(59.81, -55, 17.78, 0);
      delay(td2);
      break;
    case 5:
      FR(55, 55, 0, 0);
      BL(-55, -55, 0, 0);
      FL(-55, 55, 20, 0);
      BR(55, -55, 20, 0);
      delay(td2);
      break;
    case 6:
      FR(53.34, 55, 0, 0);
      BL(-56.66, -55, 0, 0);
      FL(-59.81, 55, 17.78, 0);
      BR(50.19, -55, 17.78, 0);
      delay(td2);
      break;
    case 7:
      FR(51.72, 55, 0, 0);
      BL(-58.28, -55, 0, 0);
      FL(-63.52, 55, 11.11, 0);
      BR(46.48, -55, 11.11, 0);
      delay(td2);
      break;
    case 8:
      FR(50.19, 55, 0, 0);
      BL(-59.81, -55, 0, 0);
      FL(-65, 55, 0, 0);
      BR(45, -55, 0, 0);
      delay(td2);
      break;
    case 9:
      FR(47.59, 55, 0, 0);
      BL(-62.41, -55, 0, 0);
      FL(-62.41, 55, 0, 0);
      BR(47.59, -55, 0, 0);
      delay(td2);
      break;
    case 10:
      FR(45, 55, 0, 0);
      BL(-65, -55, 0, 0);
      FL(-59.81, 55, 0, 0);
      BR(50.19, -55, 0, 0);
      delay(td2);
      break;
    case 11:
      FR(46.48, 55, 11.11, 0);
      BL(-63.52, -55, 11.11, 0);
      FL(-58.28, 55, 0, 0);
      BR(51.72, -55, 0, 0);
      delay(td2);
      break;
    case 12:
      FR(50.19, 55, 17.78, 0);
      BL(-59.81, -55, 17.78, 0);
      FL(-56.66, 55, 0, 0);
      BR(53.34, -55, 0, 0);
      delay(td2);
      break;
    case 13:
      FR(55, 55, 20, 0);
      BL(-55, -55, 20, 0);
      FL(-55, 55, 0, 0);
      BR(55, -55, 0, 0);
      delay(td2);
      break;
    case 14:
      FR(59.81, 55, 17.78, 0);
      BL(-50.19, -55, 17.78, 0);
      FL(-53.34, 55, 0, 0);
      BR(57.49, -55, 0, 0);
      delay(td2);
      break;
    case 15:
      FR(63.52, 55, 11.11, 0);
      BL(-46.48, -55, 11.11, 0);
      FL(-51.72, 55, 0, 0);
      BR(59.92, -55, 0, 0);
      delay(td2);
      break;
  }
  steps++;
  if (steps > 15)steps = 0;
}


void mundurdikit() {
  static int steps = 0;
  switch (steps)
  {
    case 0:
      FR(45, 55, 0, 0);
      BL(-65, -55, 0, 0);
      FL(-59.81, 55, 0, 0);
      BR(50.19, -55, 0, 0);
      delay(td2);
      break;
    case 1:
      FR(47.59, 55, 0, 0);
      BL(-62.41, -55, 0, 0);
      FL(-62.41, 55, 0, 0);
      BR(47.59, -55, 0, 0);
      delay(td2);
      break;
    case 2:
      FR(50.19, 55, 0, 0);
      BL(-59.81, -55, 0, 0);
      FL(-65, 55, 0, 0);
      BR(45, -55, 0, 0);
      delay(td2);
      break;
    case 3:
      FR(51.72, 55, 0, 0);
      BL(-58.28, -55, 0, 0);
      FL(-63.52, 55, 11.11, 0);
      BR(46.48, -55, 11.11, 0);
      delay(td2);
      break;
    case 4:
      FR(53.34, 55, 0, 0);
      BL(-56.66, -55, 0, 0);
      FL(-59.81, 55, 17.78, 0);
      BR(50.19, -55, 17.78, 0);
      delay(td2);
      break;
    case 5:
      FR(55, 55, 0, 0);
      BL(-55, -55, 0, 0);
      FL(-55, 55, 20, 0);
      BR(55, -55, 20, 0);
      delay(td2);
      break;
    case 6:
      FR(56.66, 55, 0, 0);
      BL(-53.34, -55, 0, 0);
      FL(-50.19, 55, 17.78, 0);
      BR(59.81, -55, 17.78, 0);
      delay(td2);
      break;
    case 7:
      FR(58.28, 55, 0, 0);
      BL(-51.72, -55, 0, 0);
      FL(-46.48, 55, 11.11, 0);
      BR(63.52, -55, 11.11, 0);
      delay(td2);
      break;
    case 8:
      FR(59.81, 55, 0, 0);
      BL(-50.19, -55, 0, 0);
      FL(-45, 55, 0, 0);
      BR(65, -55, 0, 0);
      delay(td2);
      break;
    case 9:
      FR(62.41, 55, 0, 0);
      BL(-47.59, -55, 0, 0);
      FL(-47.59, 55, 0, 0);
      BR(62.41, -55, 0, 0);
      delay(td2);
      break;
    case 10:
      FR(65, 55, 0, 0);
      BL(-45, -55, 0, 0);
      FL(-50.19, 55, 0, 0);
      BR(59.81, -55, 0, 0);
      delay(td2);
      break;
    case 11:
      FR(63.52, 55, 11.11, 0);
      BL(-46.48, -55, 11.11, 0);
      FL(-51.72, 55, 0, 0);
      BR(58.28, -55, 0, 0);
      delay(td2);
      break;
    case 12:
      FR(59.81, 55, 17.78, 0);
      BL(-50.19, -55, 17.78, 0);
      FL(-53.34, 55, 0, 0);
      BR(56.66, -55, 0, 0);
      delay(td2);
      break;
    case 13:
      FR(55, 55, 20, 0);
      BL(-55, -55, 20, 0);
      FL(-55, 55, 0, 0);
      BR(55, -55, 0, 0);
      delay(td2);
      break;
    case 14:
      FR(50.19, 55, 17.78, 0);
      BL(-59.81, -55, 17.78, 0);
      FL(-56.66, 55, 0, 0);
      BR(53.34, -55, 0, 0);
      delay(td2);
      break;
    case 15:
      FR(46.48, 55, 11.11, 0);
      BL(-63.52, -55, 11.11, 0);
      FL(-59.92, 55, 0, 0);
      BR(51.72, -55, 0, 0);
      delay(td2);
      break;
  }
  steps++;
  if (steps > 15)steps = 0;
}




void kanandikit() {
  static int steps = 0;
  switch (steps)
  {
    case 0:
      FR(55, 65, 0, 0);
      BL(-55, -45, 0, 0);
      FL(-55, 59.81, 0, 0);
      BR(55, -50.19, 0, 0);
      delay(td2);
      break;
    case 1:
      FR(55, 63.65, 0, 0);
      BL(-55, -46.35, 0, 0);
      FL(-55, 61.16, 0, 0);
      BR(55, -48.84, 0, 0);
      delay(td2);
      break;
    case 2:
      FR(55, 61.16, 0, 0);
      BL(-55, -48.84, 0, 0);
      FL(-55, 63.65, 0, 0);
      BR(55, -46.35, 0, 0);
      delay(td2);
      break;
    case 3:
      FR(55, 59.81, 0, 0);
      BL(-55, -50.19, 0, 0);
      FL(-55, 65, 0, 0);
      BR(55, -45, 0, 0);
      delay(td2);
      break;
    case 4:
      FR(55, 58.28, 0, 0);
      BL(-55, -51.72, 0, 0);
      FL(-55, 63.52, 11.11, 0);
      BR(55, -46.48, 11.11, 0);
      delay(td2);
      break;
    case 5:
      FR(55, 56.66, 0, 0);
      BL(-55, -53.34, 0, 0);
      FL(-55, 59.81, 17.78, 0);
      BR(55, -50.19, 17.78, 0);
      delay(td2);
      break;
    case 6:
      FR(55, 55, 0, 0);
      BL(-55, -55, 0, 0);
      FL(-55, 55, 20, 0);
      BR(55, -55, 20, 0);
      delay(td2);
      break;
    case 7:
      FR(55, 53.34, 0, 0);
      BL(-55, -56.66, 0, 0);
      FL(-55, 50.19, 17.78, 0);
      BR(55, -59.81, 17.78, 0);
      delay(td2);
      break;
    case 8:
      FR(55, 51.72, 0, 0);
      BL(-55, -58.28, 0, 0);
      FL(-55, 46.48, 11.11, 0);
      BR(55, -63.52, 11.11, 0);
      delay(td2);
      break;
    case 9:
      FR(55, 50.19, 0, 0);
      BL(-55, -59.81, 0, 0);
      FL(-55, 45, 0, 0);
      BR(55, -65, 0, 0);
      delay(td2);
      break;
    case 10:
      FR(55, 48.84, 0, 0);
      BL(-55, -61.16, 0, 0);
      FL(-55, 46.35, 0, 0);
      BR(55, -63.65, 0, 0);
      delay(td2);
      break;
    case 11:
      FR(55, 46.35, 0, 0);
      BL(-55, -63.65, 0, 0);
      FL(-55, 48.84, 0, 0);
      BR(55, -61.16, 0, 0);
      delay(td2);
      break;
    case 12:
      FR(55, 45, 0, 0);
      BL(-55, -65, 0, 0);
      FL(-55, 50.19, 0, 0);
      BR(55, -59.81, 0, 0);
      delay(td2);
      break;

    case 13:
      FR(55, 46.48, 11.11, 0);
      BL(-55, -63.52, 11.11, 0);
      FL(-55, 51.72, 0, 0);
      BR(55, -58.28, 0, 0);
      delay(td2);
      break;
    case 14:
      FR(55, 50.19, 17.78, 0);
      BL(-55, -59.81, 17.78, 0);
      FL(-55, 53.34, 0, 0);
      BR(55, -56.66, 0, 0);
      delay(td2);
      break;
    case 15:
      FR(55, 55, 20, 0);
      BL(-55, -55, 20, 0);
      FL(-55, 55, 0, 0);
      BR(55, -55, 0, 0);
      delay(td2);
      break;
    case 16:
      FR(55, 59.81, 17.78, 0);
      BL(-55, -50.19, 17.78, 0);
      FL(-55, 57.49, 0, 0);
      BR(55, -53.34, 0, 0);
      delay(td2);
      break;
    case 17:
      FR(55, 63.52, 11.11, 0);
      BL(-55, -46.48, 11.11, 0);
      FL(-55, 59.92, 0, 0);
      BR(55, -51.72, 0, 0);
      delay(td2);
      break;

    case 18:
      FR(55, 63.52, 9.8, 0);
      BL(-55, -46.48, 9.8, 0);
      FL(-55, 59.18, 0, 0);
      BR(55, -50.19, 0, 0);
      delay(td2);
      break;

    case 19:
      FR(55, 63.52, 5.3, 0);
      BL(-55, -46.48, 5.3, 0);
      FL(-55, 59.18, 0, 0);
      BR(55, -50.19, 0, 0);
      delay(td2);
      break;
  }
  steps++;
  if (steps > 19)steps = 0;
}


void kiridikit(float lbr) {
  arahgerak = false;

  FR(55, 45, 0, lbr);
  BL(-55, -65, 0, lbr);
  FL(-55, 50.19, 0, lbr);
  BR(55, -59.81, 0, lbr);
  delay(td2);

  FR(55, 46.35, 0, lbr);
  BL(-55, -63.65, 0, lbr);
  FL(-55, 48.84, 0, lbr);
  BR(55, -61.16, 0, lbr);
  delay(td2);

  FR(55, 48.84, 0, lbr);
  BL(-55, -61.16, 0, lbr);
  FL(-55, 46.35, 0, lbr);
  BR(55, -63.65, 0, lbr);
  delay(td2);

  FR(55, 50.19, 0, lbr);
  BL(-55, -59.81, 0, lbr);
  FL(-55, 45, 0, lbr);
  BR(55, -65, 0, lbr);
  delay(td2);

  FR(55, 51.72, 0, lbr);
  BL(-55, -58.28, 0, lbr);
  FL(-55, 46.48, 11.11, lbr);
  BR(55, -63.52, 11.11, lbr);
  delay(td2);

  FR(55, 53.34, 0, lbr);
  BL(-55, -56.66, 0, lbr);
  FL(-55, 50.19, 17.78, lbr);
  BR(55, -59.81, 17.78, lbr);
  delay(td2);

  FR(55, 55, 0, lbr);
  BL(-55, -55, 0, lbr);
  FL(-55, 55, 20, lbr);
  BR(55, -55, 20,  lbr);
  delay(td2);

  FR(55, 56.66, 0, lbr);
  BL(-55, -53.34, 0, lbr);
  FL(-55, 59.81, 17.78, lbr);
  BR(55, -50.19, 17.78, lbr);
  delay(td2);

  FR(55, 58.28, 0, lbr);
  BL(-55, -51.72, 0, lbr);
  FL(-55, 63.52, 11.11, lbr);
  BR(55, -46.48, 11.11, lbr);
  delay(td2);
  //
  FR(55, 59.81, 0, lbr);
  BL(-55, -50.19, 0, lbr);
  FL(-55, 63.9, 9.8, lbr);
  BR(55, -46.10, 9.8, lbr);
  delay(td2);

  FR(55, 59.81, 0, lbr);
  BL(-55, -50.19, 0, lbr);
  FL(-55, 64.62, 5.3, lbr);
  BR(55, -45.38, 5.3, lbr);
  delay(td2);
  //
  FR(55, 59.81, 0, lbr);
  BL(-55, -50.19, 0, lbr);
  FL(-55, 65, 0, lbr);
  BR(55, -45, 0, lbr);
  delay(td2);

  FR(55, 61.16, 0, lbr);
  BL(-55, -48.84, 0, lbr);
  FL(-55, 63.65, 0, lbr);
  BR(55, -46.35, 0, lbr);
  delay(td2);

  FR(55, 63.65, 0, lbr);
  BL(-55, -46.35, 0, lbr);
  FL(-55, 61.16, 0, lbr);
  BR(55, -48.84, 0, lbr);
  delay(td2);

  FR(55, 65, 0, lbr);
  BL(-55, -45, 0, lbr);
  FL(-55, 59.81, 0, lbr);
  BR(55, -50.19, 0, lbr);
  delay(td2);

  FR(55, 63.52, 11.11, lbr);
  BL(-55, -46.48, 11.11, lbr);
  FL(-55, 58.28, 0, lbr);
  BR(55, -51.72, 0, lbr);
  delay(td2);

  FR(55, 59.81, 17.78, lbr);
  BL(-55, -50.19, 17.78, lbr);
  FL(-55, 56.66, 0, lbr);
  BR(55, -53.34, 0, lbr);
  delay(td2);

  FR(55, 55, 20, lbr);
  BL(-55, -55, 20, lbr);
  FL(-55, 55, 0, lbr);
  BR(55, -55, 0, lbr);
  delay(td2);

  FR(55, 50.19, 17.78, lbr);
  BL(-55, -59.81, 17.78, lbr);
  FL(-55, 53.34, 0, lbr);
  BR(55, -57.49, 0, lbr);
  delay(td2);

  FR(55, 46.48, 11.11, lbr);
  BL(-55, -63.52, 11.11, lbr);
  FL(-55, 51.72, 0, lbr);
  BR(55, -59.92, 0, lbr);
  delay(td2);

  FR(55, 46.10, 9.8, lbr);
  BL(-55, -63.9, 9.8, lbr);
  FL(-55, 50.19, 0, lbr);
  BR(55, -59.81, 0, lbr);
  delay(td2);

  FR(55, 45.38, 5.31, lbr);
  BL(-55, -64.62, 5.31, lbr);
  FL(-55, 50.19, 0, lbr);
  BR(55, -59.81, 0, lbr);
  delay(td2);
}


void majulambat1() { //Gerakan lambat, Sudut Belok = 5
  static int steps = 0;
  switch (steps)
  {
    //FR & BL Seret, FL & BR Swing
    case 0:
      FR(85, 55, 0, 0);
      BL(-25, -55, 0, 0);
      FL(-40.56, 55, 0, 0);
      BR(69.44, -55, 0, 0);
      delay(td1);
      break;
    case 1:
      FR(84.47, 55, 0, 0);
      BL(-25.53, -55, 0, 0);
      FL(-36.32, 55, 0, 0);
      BR(73.68, -55, 0, 0);
      delay(td1);
      break;
    case 2:
      FR(82.94, 55, 0, 0);
      BL(-27.06, -55, 0, 0);
      FL(-32.57, 55, 0, 0);
      BR(77.43, -55, 0, 0);
      delay(td1);
      break;
    case 3:
      FR(80.56, 55, 0, 0);
      BL(-29.44, -55, 0, 0);
      FL(-29.44, 55, 0, 0);
      BR(80.56, -55, 0, 0);
      delay(td1);
      break;
    case 4:
      FR(77.43, 55, 0, 0);
      BL(-32.57, -55, 0, 0);
      FL(-27.06, 55, 0, 0);
      BR(82.94, -55, 0, 0);
      delay(td1);
      break;
    case 5:
      FR(73.68, 55, 0, 0);
      BL(-36.32, -55, 0, 0);
      FL(-25.53, 55, 0, 0);
      BR(84.47, -55, 0, 0);
      delay(td1);
      break;
    case 6:
      FR(69.44, 55, 0, 0);
      BL(-40.56, -55, 0, 0);
      FL(-25, 55, 35, 0);
      BR(85, -55, 35, 0);
      delay(td2);
      break;
    case 7:
      FR(64.84, 55, 0, 0);
      BL(-45.16, -55, 0, 0);
      FL(-29.44, 55, 11.11, 0);
      BR(80.56, -55, 11.11, 0);
      delay(td2);
      break;
    case 8:
      FR(59.98, 55, 0, 0);
      BL(-50, -55, 0, 0);
      FL(-40.56, 55, 17.78, 0);
      BR(69.44, -55, 17.78, 0);
      delay(td2);
      break;
    case 9:
      FR(55, 55, 0, 0);
      BL(-55, -55, 0, 0);
      FL(-55, 55, 20, 0);
      BR(55, -55, 20, 0);
      delay(td2);
      break;
    case 10:
      FR(50, 55, 0, 0);
      BL(-59.98, -55, 0, 0);
      FL(-69.44, 55, 17.78, 0);
      BR(40.56, -55, 17.78, 0);
      delay(td2);
      break;

    case 11:
      FR(45.16, 55, 0, 0);
      BL(-64.84, -55, 0, 0);
      FL(-72.04, 55, 11.1, 0);
      BR(37.96, -55, 11.1, 0);
      delay(td2);
      break;
    case 12:
      FR(40.56, 55, 0, 0);
      BL(-69.44, -55, 0, 0);
      FL(-78.76, 55, 9.8, 0);
      BR(31.24, -55, 9.8, 0);
      delay(td2);
      break;
    ///////

    case 13:
      FR(36.32, 55, 0, 0);
      BL(-73.68, -55, 0, 0);
      FL(-83.32, 55, 5.3, 0);
      BR(26.68, -55, 5.3, 0);
      delay(td2);
      break;

    case 14:
      FR(32.57, 55, 0, 0);
      BL(-77.43, -55, 0, 0);
      FL(-85, 55, 0, 0);
      BR(25, -55, 0, 0);
      delay(td2);
      break;

    case 15:
      FR(29.44, 55, 0, 0);
      BL(-80.56, -55, 0, 0);
      FL(-80.56, 55, 0, 0);
      BR(29.44, -55, 0, 0);
      delay(td2);
      break;

    case 16:
      FR(27.06, 55, 0, 0);
      BL(-82.94, -55, 0, 0);
      FL(-77.43, 55, 0, 0);
      BR(32.57, -55, 0, 0);
      delay(td2);
      break;
    case 17:
      FR(25.53, 55, 0, 0);
      BL(-84.47, -55, 0, 0);
      FL(-73.68, 55, 0, 0);
      BR(36.32, -55, 0, 0);
      delay(td2);
      break;

    case 18:
      FR(25, 55, 0, 0);
      BL(-85, -55, 0, 0);
      FL(-69.44, 55, 0, 0);
      BR(40.56, -55, 0, 0);
      delay(td2);
      break;
    case 19:
      FR(29.44, 55, 11.11, 0);
      BL(-80.56, -55, 11.11, 0);
      FL(-64.48, 55, 0, 0);
      BR(45.16, -55, 0, 0);
      delay(td2);
      break;
    case 20:
      FR(40.56, 55, 17.78, 0);
      BL(-69.44, -55, 17.78, 0);
      FL(-59.98, 55, 0, 0);
      BR(50, -55, 0, 0);
      delay(td2);
      break;
    case 21:
      FR(55, 55, 20, 0);
      BL(-55, -55, 20, 0);
      FL(-55, 55, 0, 0);
      BR(55, -55, 0, 0);
      delay(td2);
      break;
    case 22:
      FR(69.44, 55, 17.78, 0);
      BL(-40.56, -55, 17.78, 0);
      FL(-50, 55, 0, 0);
      BR(59.98, -55, 0, 0);
      delay(td2);
      break;
    case 23:
      FR(72.04, 55, 11.11, 0);
      BL(-37.96, -55, 11.11, 0);
      FL(-45.16, 55, 0, 0);
      BR(64.84, -55, 0, 0);
      delay(td2);
      break;
    case 24:
      FR(78.76, 55, 9.8, 0);
      BL(-31.24, -55, 9.8, 0);
      FL(-43.97, 55, 0, 0);
      BR(66.03, -55, 0, 0);
      delay(td2);
      break;
    case 25:
      FR(83.32, 55, 5.31, 0);
      BL(-26.68, -55, 5.31, 0);
      FL(-41.75, 55, 0, 0);
      BR(68.25, -55, 0, 0);
      delay(td2);
      break;
  }
  steps++;
  if (steps > 25)steps = 0;
}



void majulambat2() { //Gerakan lambat, Sudut Belok = 5
  static int steps = 0;
  switch (steps)
  {
    //FR & BL Seret, FL & BR Swing
    case 0:
      FR(85, 55, 0, 0);
      BL(-25, -55, 0, 0);
      FL(-40.56, 55, 0, 0);
      BR(69.44, -55, 0, 0);
      delay(td1);
      break;
    case 1:
      FR(84.47, 55, 0, 0);
      BL(-25.53, -55, 0, 0);
      FL(-36.32, 55, 0, 0);
      BR(73.68, -55, 0, 0);
      delay(td1);
      break;
    case 2:
      FR(82.94, 55, 0, 0);
      BL(-27.06, -55, 0, 0);
      FL(-32.57, 55, 0, 0);
      BR(77.43, -55, 0, 0);
      delay(td1);
      break;
    case 3:
      FR(80.56, 55, 0, 0);
      BL(-29.44, -55, 0, 0);
      FL(-29.44, 55, 0, 0);
      BR(80.56, -55, 0, 0);
      delay(td1);
      break;
    case 4:
      FR(77.43, 55, 0, 0);
      BL(-32.57, -55, 0, 0);
      FL(-27.06, 55, 0, 0);
      BR(82.94, -55, 0, 0);
      delay(td1);
      break;
    case 5:
      FR(73.68, 55, 0, 0);
      BL(-36.32, -55, 0, 0);
      FL(-25.53, 55, 0, 0);
      BR(84.47, -55, 0, 0);
      delay(td1);
      break;
    case 6:
      FR(69.44, 55, 0, 0);
      BL(-40.56, -55, 0, 0);
      FL(-25, 55, 35, 0);
      BR(85, -55, 35, 0);
      delay(td2);
      break;
    case 7:
      FR(64.84, 55, 0, 0);
      BL(-45.16, -55, 0, 0);
      FL(-29.44, 55, 16.67, 0);
      BR(80.56, -55, 16.67, 0);
      delay(td2);
      break;
    case 8:
      FR(59.98, 55, 0, 0);
      BL(-50, -55, 0, 0);
      FL(-40.56, 55, 26.67, 0);
      BR(69.44, -55, 26.67, 0);
      delay(td2);
      break;
    case 9:
      FR(55, 55, 0, 0);
      BL(-55, -55, 0, 0);
      FL(-55, 55, 30, 0);
      BR(55, -55, 30, 0);
      delay(td2);
      break;
    case 10:
      FR(50, 55, 0, 0);
      BL(-59.98, -55, 0, 0);
      FL(-69.44, 55, 26.67, 0);
      BR(40.56, -55, 26.67, 0);
      delay(td2);
      break;

    case 11:
      FR(45.16, 55, 0, 0);
      BL(-64.84, -55, 0, 0);
      FL(-72.04, 55, 25.2, 0);
      BR(37.96, -55, 25.2, 0);
      delay(td2);
      break;
    case 12:
      FR(40.56, 55, 0, 0);
      BL(-69.44, -55, 0, 0);
      FL(-78.76, 55, 19.2, 0);
      BR(31.24, -55, 19.2, 0);
      delay(td2);
      break;
    ///////

    case 13:
      FR(36.32, 55, 0, 0);
      BL(-73.68, -55, 0, 0);
      FL(-83.32, 55, 10.8, 0);
      BR(26.68, -55, 10.8, 0);
      delay(td2);
      break;

    case 14:
      FR(32.57, 55, 0, 0);
      BL(-77.43, -55, 0, 0);
      FL(-85, 55, 0, 0);
      BR(25, -55, 0, 0);
      delay(td2);
      break;

    case 15:
      FR(29.44, 55, 0, 0);
      BL(-80.56, -55, 0, 0);
      FL(-80.56, 55, 0, 0);
      BR(29.44, -55, 0, 0);
      delay(td2);
      break;

    case 16:
      FR(27.06, 55, 0, 0);
      BL(-82.94, -55, 0, 0);
      FL(-77.43, 55, 0, 0);
      BR(32.57, -55, 0, 0);
      delay(td2);
      break;
    case 17:
      FR(25.53, 55, 0, 0);
      BL(-84.47, -55, 0, 0);
      FL(-73.68, 55, 0, 0);
      BR(36.32, -55, 0, 0);
      delay(td2);
      break;

    case 18:
      FR(25, 55, 0, 0);
      BL(-85, -55, 0, 0);
      FL(-69.44, 55, 0, 0);
      BR(40.56, -55, 0, 0);
      delay(td2);
      break;
    case 19:
      FR(29.44, 55, 16.67, 0);
      BL(-80.56, -55, 16.67, 0);
      FL(-64.48, 55, 0, 0);
      BR(45.16, -55, 0, 0);
      delay(td2);
      break;
    case 20:
      FR(40.56, 55, 26.67, 0);
      BL(-69.44, -55, 26.67, 0);
      FL(-59.98, 55, 0, 0);
      BR(50, -55, 0, 0);
      delay(td2);
      break;
    case 21:
      FR(55, 55, 30, 0);
      BL(-55, -55, 30, 0);
      FL(-55, 55, 0, 0);
      BR(55, -55, 0, 0);
      delay(td2);
      break;
    case 22:
      FR(69.44, 55, 26.67, 0);
      BL(-40.56, -55, 26.67, 0);
      FL(-50, 55, 0, 0);
      BR(59.98, -55, 0, 0);
      delay(td2);
      break;
    case 23:
      FR(72.04, 55, 25.2, 0);
      BL(-37.96, -55, 25.2, 0);
      FL(-45.16, 55, 0, 0);
      BR(64.84, -55, 0, 0);
      delay(td2);
      break;
    case 24:
      FR(78.76, 55, 19.2, 0);
      BL(-31.24, -55, 19.2, 0);
      FL(-43.97, 55, 0, 0);
      BR(66.03, -55, 0, 0);
      delay(td2);
      break;
    case 25:
      FR(83.32, 55, 10.8, 0);
      BL(-26.68, -55, 10.8, 0);
      FL(-41.75, 55, 0, 0);
      BR(68.25, -55, 0, 0);
      delay(td2);
      break;
  }
  steps++;
  if (steps > 25)steps = 0;
}


////////////////////////////////////////////lumayan
void cobakiri(float lbr) {
  arahgerak = false;
  FR(55, 45, 0, lbr);
  BL(-55, -65, 0, lbr);
  FL(-55, 48.13, 0, lbr);
  BR(55, -61.88, 0, lbr);
  delay(td2);
  ///////

  FR(55, 45.23, 0, lbr);
  BL(-55, -62.11, 0, lbr);
  FL(-55, 47.24, 0, lbr);
  BR(55, -62.76, 0, lbr);
  delay(td2);

  FR(55, 45.81, 0, lbr);
  BL(-55, -62.69, 0, lbr);
  FL(-55, 46.48, 0, lbr);
  BR(55, -63.52, 0, lbr);
  delay(td2);

  FR(55, 46.56, 0, lbr);
  BL(-55, -63.44, 0, lbr);
  FL(-55, 45.86, 0, lbr);
  BR(55, -64.14, 0, lbr);
  delay(td2);

  FR(55, 47.32, 0, lbr);
  BL(-55, -64.19, 0, lbr);
  FL(-55, 45.39, 0, lbr);
  BR(55, -64.61, 0, lbr);
  delay(td2);

  FR(55, 47.9, 0, lbr);
  BL(-55, -64.77, 0, lbr);
  FL(-55, 45.10, 0, lbr);
  BR(55, -64.9, 0, lbr);
  delay(td2);

  /////
  FR(55, 51.33, 0, lbr);
  BL(-55, -58.67, 0, lbr);
  FL(-55, 45, 0, lbr);
  BR(55, -65, 0, lbr);
  delay(td2);

  FR(55, 52.52, 0, lbr);
  BL(-55, -57.48, 0, lbr);
  FL(-55, 46.48, 11.11, lbr);
  BR(55, -63.52, 11.11, lbr);
  delay(td2);

  FR(55, 53.75, 0, lbr);
  BL(-55, -56.25, 0, lbr);
  FL(-55, 50.19, 17.78, lbr);
  BR(55, -59.81, 17.78, lbr);
  delay(td2);

  FR(55, 55, 0, lbr);
  BL(-55, -55, 0, lbr);
  FL(-55, 55, 20, lbr);
  BR(55, -55, 20, lbr);
  delay(td2);

  FR(55, 56.25, 0, lbr);
  BL(-55, -53.75, 0, lbr);
  FL(-55, 59.81, 17.78, lbr);
  BR(55, -50.19, 17.78, lbr);
  delay(td2);

  /////////////////////////////////////////////58.67 & 51.33
  FR(55, 57.48, 0, lbr);
  BL(-55, -52.52, 0, lbr);
  FL(-55, 63.52, 11.11, lbr);
  BR(55, -46.48, 11.11, lbr);
  delay(td2);

  FR(55, 58.67, 0, lbr);
  BL(-55, -51.33, 0, lbr);
  FL(-55, 64.14, 8.75, lbr);
  BR(55, -45.86, 8.75, lbr);
  delay(td2);

  FR(55, 59.81, 0, lbr);
  BL(-55, -50.19, 0, lbr);
  FL(-55, 64.61, 6.61, lbr);
  BR(55, -45.39, 6.61, lbr);
  delay(td2);

  FR(55, 60.89, 0, lbr);
  BL(-55, -49.11, 0, lbr);
  FL(-55, 64.90, 3.19, lbr);
  BR(55, -45.10, 3.19, lbr);
  delay(td2);

  FR(55, 61.88, 0, lbr);
  BL(-55, -48.13, 0, lbr);
  FL(-55, 65, 0, lbr);
  BR(55, -45, 0, lbr);
  delay(td2);
  /////////////////////////////////////////

  FR(55, 62.11, 0, lbr);
  BL(-55, -47.90, 0, lbr);
  FL(-55, 64.77, 0, lbr);
  BR(55, -45.99, 0, lbr);
  delay(td2);

  FR(55, 62.69, 0, lbr);
  BL(-55, -47.32, 0, lbr);
  FL(-55, 64.19, 0, lbr);
  BR(55, -48.16, 0, lbr);
  delay(td2);

  FR(55, 63.44, 0, lbr);
  BL(-55, -46.56, 0, lbr);
  FL(-55, 63.44, 0, lbr);
  BR(55, -50.34, 0, lbr);
  delay(td2);

  FR(55, 64.19, 0, lbr);
  BL(-55, -45.81, 0, lbr);
  FL(-55, 62.69, 0, lbr);
  BR(55, -45.99, 0, lbr);
  delay(td2);

  FR(55, 64.77, 0, lbr);
  BL(-55, -45.23, 0, lbr);
  FL(-55, 62.11, 0, lbr);
  BR(55, -48.16, 0, lbr);
  delay(td2);

  ////////////////////////////////////////////////
  FR(55, 65, 0, lbr);
  BL(-55, -45, 0, lbr);
  FL(-55, 58.67, 0, lbr);
  BR(55, -51.33, 0, lbr);
  delay(td2);

  FR(55, 63.52, 11.11, lbr);
  BL(-55, -46.48, 11.11, lbr);
  FL(-55, 57.48, 0, lbr);
  BR(55, -52.52, 0, lbr);
  delay(td2);

  FR(55, 59.81, 17.78, lbr);
  BL(-55, -50.19, 17.78, lbr);
  FL(-55, 56.25, 0, lbr);
  BR(55, -53.75, 0, lbr);
  delay(td2);

  FR(55, 55, 20, lbr);
  BL(-55, -55, 20, lbr);
  FL(-55, 55, 0, lbr);
  BR(55, -55, 0, lbr);
  delay(td2);

  FR(55, 50.19, 17.78, lbr);
  BL(-55, -59.81, 17.78, lbr);
  FL(-55, 53.75, 0, lbr);
  BR(55, -56.25, 0, lbr);
  delay(td2);

  FR(55, 46.48, 11.11, lbr);
  BL(-55, -63.52, 11.11, lbr);
  FL(-55, 52.52, 0, lbr);
  BR(55, -57.48, 0, lbr);
  delay(td2);

  FR(55, 45.86, 8.75, lbr);
  BL(-55, -64.14, 8.75, lbr);
  FL(-55, 51.33, 0, lbr);
  BR(55, -58.67, 0, lbr);
  delay(td2);

  FR(55, 45.39, 6.61, lbr);
  BL(-55, -64.61, 6.61, lbr);
  FL(-55, 50.19, 0, lbr);
  BR(55, -59.81, 0, lbr);
  delay(td2);

  FR(55, 45.10, 3.19, lbr);
  BL(-55, -64.90, 3.19, lbr);
  FL(-55, 49.11, 0, lbr);
  BR(55, -60.89, 0, lbr);
  delay(td2);
}
/////////////////////////////////////////////////

void cobajalanpecah(float lbr) { //Gerakan lambat
  FR(85, 55, 0, lbr);
  BL(-25, -55, 0, lbr);
  FL(-40.56, 55, 0, lbr);
  BR(69.44, -55, 0, lbr);
  delay(td1);

  FR(84.47, 55, 0, lbr);
  BL(-25.53, -55, 0, lbr);
  FL(-36.32, 55, 0, lbr);
  BR(73.68, -55, 0, lbr);
  delay(td1);

  FR(82.94, 55, 0, lbr);
  BL(-27.06, -55, 0, lbr);
  FL(-32.57, 55, 0, lbr);
  BR(77.43, -55, 0, lbr);
  delay(td1);

  FR(80.56, 55, 0, lbr);
  BL(-29.44, -55, 0, lbr);
  FL(-29.44, 55, 0, lbr);
  BR(80.56, -55, 0, lbr);
  delay(td1);

  FR(77.43, 55, 0, lbr);
  BL(-32.57, -55, 0, lbr);
  FL(-27.06, 55, 0, lbr);
  BR(82.94, -55, 0, lbr);
  delay(td1);

  FR(73.68, 55, 0, lbr);
  BL(-36.32, -55, 0, lbr);
  FL(-25.53, 55, 0, lbr);
  BR(84.47, -55, 0, lbr);
  delay(td1);

  FR(69.44, 55, 0, lbr);
  BL(-40.56, -55, 0, lbr);
  FL(-25, 55, 0, lbr);
  BR(85, -55, 0, lbr);
  delay(td2);

  FR(64.84, 55, 0, lbr);
  BL(-45.16, -55, 0, lbr);
  FL(-29.44, 55, 19.44, lbr);
  BR(80.56, -55, 19.44, lbr);
  delay(td2);

  FR(59.98, 55, 0, lbr);
  BL(-50, -55, 0, lbr);
  FL(-40.56, 55, 31.11, lbr);
  BR(69.44, -55, 31.11, lbr);
  delay(td2);

  FR(55, 55, 0, lbr);
  BL(-55, -55, 0, lbr);
  FL(-55, 55, 35, lbr);
  BR(55, -55, 35, lbr);
  delay(td2);

  FR(50, 55, 0, lbr);
  BL(-59.98, -55, 0, lbr);
  FL(-69.44, 55, 31.11, lbr);
  BR(40.56, -55, 31.11, lbr);
  delay(td2);

  FR(45.16, 55, 0, lbr);
  BL(-64.84, -55, 0, lbr);
  FL(-80.56, 55, 19.44, lbr);
  BR(29.44, -55, 19.44, lbr);
  delay(td2);

  FR(40.56, 55, 0, lbr);
  BL(-69.44, -55, 0, lbr);
  FL(-85, 55, 0, lbr);
  BR(25, -55, 0, lbr);
  delay(td2);

  FR(36.32, 55, 0, lbr);
  BL(-73.68, -55, 0, lbr);
  FL(-84.47, 55, 0, lbr);
  BR(25.53, -55, 0, lbr);
  delay(td2);

  FR(32.57, 55, 0, lbr);
  BL(-77.43, -55, 0, lbr);
  FL(-82.94, 55, 0, lbr);
  BR(27.06, -55, 0, lbr);
  delay(td2);

  FR(29.44, 55, 0, lbr);
  BL(-80.56, -55, 0, lbr);
  FL(-80.56, 55, 0, lbr);
  BR(29.44, -55, 0, lbr);
  delay(td2);

  FR(27.06, 55, 0, lbr);
  BL(-82.94, -55, 0, lbr);
  FL(-77.43, 55, 0, lbr);
  BR(32.57, -55, 0, lbr);
  delay(td2);

  FR(25.53, 55, 0, lbr);
  BL(-84.47, -55, 0, lbr);
  FL(-73.68, 55, 0, lbr);
  BR(36.32, -55, 0, lbr);
  delay(td2);

  FR(25, 55, 0, lbr);
  BL(-85, -55, 0, lbr);
  FL(-69.44, 55, 0, lbr);
  BR(40.56, -55, 0, lbr);
  delay(td2);

  FR(29.44, 55, 19.44, lbr);
  BL(-80.56, -55, 19.44, lbr);
  FL(-64.48, 55, 0, lbr);
  BR(45.16, -55, 0, lbr);
  delay(td2);

  FR(40.56, 55, 31.11, lbr);
  BL(-69.44, -55, 31.11, lbr);
  FL(-59.98, 55, 0, lbr);
  BR(50, -55, 0, lbr);
  delay(td2);

  FR(55, 55, 35, lbr);
  BL(-55, -55, 35, lbr);
  FL(-55, 55, 0, lbr);
  BR(55, -55, 0, lbr);
  delay(td2);

  FR(69.44, 55, 31.11, lbr);
  BL(-40.56, -55, 31.11, lbr);
  FL(-50, 55, 0, lbr);
  BR(59.98, -55, 0, lbr);
  delay(td2);

  FR(80.56, 55, 19.44, lbr);
  BL(-29.44, -55, 19.44, lbr);
  FL(-45.16, 55, 0, lbr);
  BR(64.84, -55, 0, lbr);
  delay(td2);
}
