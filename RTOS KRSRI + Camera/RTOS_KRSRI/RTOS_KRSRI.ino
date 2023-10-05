//RTOS Nasional
#include <Dynamixel2Arduino.h>
#include <STM32FreeRTOS.h>
//#include <HardwareTimer.h>
HardwareSerial Serial2(USART2);
HardwareSerial Serial6(USART6); // USART antara STM32 dan Maix Bit
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 32    // OLED display height, in pixels
#define OLED_RESET    0     // Reset pin # (or -1 if sharing Arduino reset pin)
#include <Wire.h>
TwoWire Wire2(PB3, PB10);
#include "Adafruit_VL53L1X.h"
#include <Servo.h>
Servo capit;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire2, OLED_RESET);
//===================================IR Setup================================================
Adafruit_VL53L1X vl53_0;
Adafruit_VL53L1X vl53_2;
Adafruit_VL53L1X vl53_4;
Adafruit_VL53L1X vl53_6;

#define vl53Address1  0x30    //address dari IR 1
#define vl53Address2  0x31    //address dari IR 2
#define vl53Address3  0x32    //address dari IR 1 //belakang
#define vl53Address4  0x33    //address dari IR 2 //depan

#define XSHUT1        PB1      //pin XSHUT IR 2  //belakang //PB1
#define XSHUT2        PA7      //pin XSHUT IR 1  //kanan
#define XSHUT3        PA5      //pin XSHUT IR 1  //depan
//#define XSHUT4        PA6      //pin XSHUT IR 2  //kiri

//LAMA
//#define XSHUT1        PB1      //pin XSHUT IR 2  //belakang
//#define XSHUT2        PA7      //pin XSHUT IR 1  //kanan
//#define XSHUT4        PA6      //pin XSHUT IR 2  //kiri
//#define XSHUT5        PA5      //pin XSHUT IR 2  //depan
#define Button        PB12     //pin Button

int IRRangeVal_0;                             //variabel menampung hasil ir jarak 1
int IRRangeVal_2;                             //variabel menampung hasil ir jarak 2
int IRRangeVal_4;                             //variabel menampung hasil ir jarak 3
int IRRangeVal_6;                             //variabel menampung hasil ir jarak 4

int IRRangeFuzzy_0;                           //variabel menampung hasil ir jarak setelah fuzzy 1
int IRRangeFuzzy_2;                           //variabel menampung hasil ir jarak setelah fuzzy 2
int IRRangeFuzzy_4;                           //variabel menampung hasil ir jarak setelah fuzzy 3
int IRRangeFuzzy_6;                           //variabel menampung hasil ir jarak setelah fuzzy 4
//===================================IR Setup================================================
SemaphoreHandle_t semHandle;
QueueHandle_t queueHandle;
//===================================Servo Dynamixel Setup================================================
#define DXL_SERIAL Serial
#define DEBUG_SERIAL Serial2
const uint8_t DXL_DIR_PIN = PA4;
const float DXL_PROTOCOL_VERSION = 1.0;
Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);
//===================================Servo Dynamixel Setup================================================
//===================================Kompas Setup================================================
#define ANGLE_8 1
#define CMPS12_ADDRESS 0x60
unsigned char highBytes, lowBytes;
signed char pitch, roll;
unsigned int angle16;
int kalibrasi_kompas;
int arah;
int heading;
float kp = 1.75 ; //kp
float ki = 0; //ki
float kd = 0.75; //kd
float P_control;
float I_control;
float D_control;
float pid_output;
float previous_error;
float error;
float sudutBelok, longStep;
int sp_kompas;
int tempt;
float sdtcoxa, sdtcoxa1, sdtcoxa2, sdtcoxa3, sdtcoxa4, sdtrotate, sdtfemur, sdttibia, theta2, theta3, angle1, angle2, P, c, alas, alpha, beta;
int sudut1, sudut2, sudut3, sudut4, sudutx;
int compassOffset;
int SpJarak;
float pv, JarakNow, OffsetJarak, SudutRotate;
float filter_weight = 0.9;
float filteredIR_4, filteredIR_0;
//=====PING======//
double duration, cm;
unsigned char jarak[2];
//unsigned char pin[] = {PA7};
//======Trayektori=======//
float Xoffset = 50.2;
float Yoffset = 50;
float xFR , yFR , zFR , xFL , yFL , zFL, xBL , yBL , zBL, xBR , yBR , zBR;
float standFL[3][1] = {{(-55 + -(Xoffset))}, {(55 + Yoffset)}, { -75}};
float standFR[3][1] = {{(55 + Xoffset)}, {(55 + Yoffset)}, { -75}};
float standBR[3][1] = {{(55 + Xoffset)}, {(-55 + -(Yoffset))}, { -75}};
float standBL[3][1] = {{(-55 + -(Xoffset))}, {(-55 + -(Yoffset))}, { -75}};
//=====Acuan Kalibrasi Kompas Awal====//
//selatan = 185
//utara = 0
//===================================//
//===================================Kompas Setup================================================//
//Arena Nasional Merah
//int compassFront[] = {336, 65, 158, 249};     Value untuk kompass saat hadap depan (diurut dari utara, timur, selatan, barat)
//Arena Nasional Biru
int compassFront[] = {311, 40, 132, 219};     //Value untuk kompass saat hadap depan (diurut dari utara, timur, selatan, barat)
//Arena Latihan
//int compassFront[] = {5, 96, 183, 274};     //Value untuk kompass saat hadap depan (diurut dari utara, timur, selatan, barat)

int calKompas = 0;
int compassStart = 90;
bool arahgerak;
//===================================Kompas Setup================================================//
//===================================Maixbit Setup===============================================//
int pict_x = 200, pict_area, area, pict_y;//Tambah variabel area klo mau pke area //200
int pict_x_cal = 165; // Threshold nilai tengah korban di kamera
int pict_area_cal = 7500; // Threshold area blob (jarak korban) di kamera
int pict_y_cal = 0; //Ganti nilai 0 dengan nilai y ketika pas capit dengan korban
bool tengah = 0;
//===================================Maixbit Setup===============================================//
float cx = 37.5;
float fm = 58;
float tb = 80;
int legoffset[] = {45, 135, 225, 315};
int height = -75;
int height2 = -75;
float z;
int td1 = 15; //delay rotate
float td2 = 3;
int ts = 20;
int td = 5; //delay kananstart
int tp = 19; //delay pecah asli 20
int tbk = 16; //delay kanan kiri batu
int tb1 = 18.5; //delay batu + turunan
int tk = 21; //delay deteksi korban 1
int tr = 27; //delay rotate batu
int tk2 = 15; //delay deteksi korban 2 //19
int tr2 = 19; //delay rotate deteksi korban 2 //20
int tk3 = 11; //delay deteksi korban 3
int trb = 18;
int tc = 21;
int tk1 = 12; //12
int tpr = 9;
int dtangga = 22.5; //23
int dtime = 15;
int dt = 12;
int drot = 30;
int tr3 = 18; //delay rotate pecah K3
int movecounter = 0;               //untuk menghitung fase gerakan robot
int choice = 9;
int xIn, yIn, zIn, delayIn;
int choice1, choice2;
int i = 0;
int j = 0;  //variabel pemanggilan array

bool InverseMode = true;
int send_queue = 0;
bool queue = false;
bool queue_true = true;
int choice_sem;
bool data;
bool tangga = true;
bool pecah = true;
bool IRpecah;
bool stand = true;
bool turun = true;
int ButtonState = 1;

//membuat fungsi untuk task
void sensor (void *pvParameters);
void kaki (void *pvParameters);

void setup() {
  //  noInterrupts();
  Serial.setTx(PA9);
  Serial.setRx(PA10);
  Serial2.setTx(PA2);
  Serial2.setRx(PA3);
  Serial6.setTx(PA11);
  Serial6.setRx(PA12);
  DEBUG_SERIAL.begin(115200);
  Serial6.begin(115200);
  //=======Setup Button=====//
  pinMode(Button, INPUT);
  //=======Setup Button=====//

  //=======Setup IR=========//
  //  pinMode(XSHUT1, OUTPUT);
  //  pinMode(XSHUT2, OUTPUT);
  //  pinMode(XSHUT4, OUTPUT);
  //  pinMode(XSHUT5, OUTPUT);
  //
  //  digitalWrite(XSHUT1, LOW);
  //  digitalWrite(XSHUT2, LOW);
  //  digitalWrite(XSHUT4, LOW);
  //  digitalWrite(XSHUT5, LOW);
  //
  //  digitalWrite(XSHUT5, HIGH);
  //  vl53_0.begin(vl53Address1, &Wire2);
  //  digitalWrite(XSHUT2, HIGH);
  //  vl53_2.begin(vl53Address2, &Wire2);
  //  digitalWrite(XSHUT1, HIGH);
  //  vl53_4.begin(vl53Address3, &Wire2);
  //  digitalWrite(XSHUT4, HIGH);
  //  vl53_6.begin(vl53Address4, &Wire2);
  //
  //  vl53_0.startRanging();
  //  vl53_0.setTimingBudget(50);
  //  vl53_2.startRanging();
  //  vl53_2.setTimingBudget(50);
  //  vl53_4.startRanging();
  //  vl53_4.setTimingBudget(50);
  //  vl53_6.startRanging();
  //  vl53_6.setTimingBudget(50);

  //setup IR
  pinMode(XSHUT1, OUTPUT);
  pinMode(XSHUT2, OUTPUT);
  pinMode(XSHUT3, OUTPUT);
  //  pinMode(XSHUT4, OUTPUT);

  digitalWrite(XSHUT1, LOW);
  digitalWrite(XSHUT2, LOW);
  digitalWrite(XSHUT3, LOW);
  //  digitalWrite(XSHUT4, LOW);

  digitalWrite(XSHUT1, HIGH);
  vl53_4.begin(vl53Address3, &Wire2);

  digitalWrite(XSHUT2, HIGH);
  vl53_2.begin(vl53Address2, &Wire2);

  digitalWrite(XSHUT3, HIGH);
  vl53_0.begin(vl53Address1, &Wire2);

  //  digitalWrite(XSHUT4, HIGH);
  //  vl53_6.begin(vl53Address4, &Wire2);
  //  Serial2.println("IR KIRI");

  vl53_0.startRanging();
  vl53_0.setTimingBudget(50);
  vl53_2.startRanging();
  vl53_2.setTimingBudget(50);
  vl53_4.startRanging();
  vl53_4.setTimingBudget(50);
  //  vl53_6.startRanging();
  //  vl53_6.setTimingBudget(50);
  Wire2.begin();
  //=======================//
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);      //ganti 0x3C dengan alamat IIC LCD kalian
  display.clearDisplay();                         // mengosongkan tampilan / menghapus logo adafruit
  //=======================//
  dxl.begin(1000000);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  pinMode(PB9, OUTPUT);
  capit.attach(PB14);
  //Making Semaphore Handle
  semHandle = xSemaphoreCreateBinary();
  queueHandle = xQueueCreate(30, // Queue length
                             sizeof(int) // Queue item size
                            );
  //  interrupts();
  delay(3000);
  dxl.setGoalPosition(14, 65, UNIT_DEGREE); //awal 63
  dxl.setGoalPosition(15, 180, UNIT_DEGREE);
  capit.write(165);
  standby2();
  resetPID();
  delay(2000);
  xTaskCreate(sensor,
              "program_sensor",
              512,
              NULL,
              1,
              NULL);

  xTaskCreate(kaki,
              "program_kaki",
              512,
              NULL,
              2,
              NULL);
  vTaskStartScheduler();
}


void loop() {

}

void standby() {
  FR(55, 55, 0, 0);
  BL(-55, -55, 0, 0);
  FL(-55, 55, 0, 0);
  BR(55, -55, 0, 0);
}
