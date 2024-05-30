#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <AccelStepper.h>
#include <SPI.h>
#include <RFID.h>

#define ROW_NUM     4 // four rows
#define COLUMN_NUM  4 // four columns
#define SDA_DIO 9
#define RESET_DIO 8
#define TRIGGER_PIN_1  24  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_1     25 // Arduino pin tied to echo pin on the ultrasonic sensor.
//#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).
#define TRIGGER_PIN_2  40  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_2     41 // Arduino pin tied to echo pin on the ultrasonic sensor.

String cardid = "";
/* Create an instance of the RFID library */
RFID RC522(SDA_DIO, RESET_DIO); 

//variables
char key;
char pass[4];
int passval=0;
int tval=0;
int coffeetemp;
int milktemp;
//flags
int c=0;
int s=0;
int con=0;//0
int conn=0;
int u=0;
int menu=1;//1
int cup=1;
int esp=1;
int user=1;
int cursor=0;
int done=0; //0
int siz=0;//0

//------------ Stepper Motors -----------//
unsigned int M_DEST = -800;
unsigned int SPD = 100;
unsigned int ACCEL = 500;
//stepper of revolver
const int dirPin1 = 31;
const int stepPin1 = 32;
//stepper of cap ejector
const int dirPin2 = 23;
const int stepPin2 = 33;
//stepper of cupl
const int dirPin3 = 34;
const int stepPin3 = 35;
//stepper of cups
const int dirPin4 =36 ;
const int stepPin4 = 37;
//stepper of belt
const int dirPin5 = 38;
const int stepPin5 = 39;
//const int enPin = 30;
AccelStepper stepper1(1, stepPin1, dirPin1);         //stepper for belt
AccelStepper stepper2(1, stepPin2, dirPin2);        //stepper for lowering large cup
AccelStepper stepper3(1, stepPin3, dirPin3);        //stepper for geer
AccelStepper stepper4(1, stepPin4, dirPin4);        //stepper for flavors
AccelStepper stepper5(1, stepPin5, dirPin5);        //stepper for lowering small cup


//------------Esp DC Motor and sensor -----------//
const int in1 = 26;
const int in2 = 27;
const int H1 = 46;
const int H2 = 47;
const int H3 = 49;//revolver
const int H4 = 48;//ejector
const int limit1 = 42;  //large cup
const int limit2 = 43;  //small cup
const int limit3 = 30;  //belt
//---- Temperature Sensor ----//
const int TEMERATURE_SENSOR_PIN_COFFEE = 12;        //T2
const int TEMERATURE_SENSOR_PIN_MILK = 13;          //T1
OneWire oneWireCoffeeSen(TEMERATURE_SENSOR_PIN_COFFEE);
OneWire oneWireMilkSen(TEMERATURE_SENSOR_PIN_MILK);
DallasTemperature CoffeeSen(&oneWireCoffeeSen);
DallasTemperature MilkSen(&oneWireMilkSen);


//------- Ultrasonic Sensors -------//
unsigned long duration_1; // Variable for the duration of the ultrasonic pulse
unsigned long duration_2; // Variable for the duration of the ultrasonic pulse
float distance_1; // Variable for the distance measurement
float distance_2; // Variable for the distance measurement

//--------Relays-------//
#define relayN1  29     //   T1
#define relayN2  28     //   T2
#define relayN3  22//22     // 1st pump (coffee)
#define relayN4  44//46     // 2nd pump (milk)
#define relayN5  45 //45    // 1st button of espresso
//const int relayN6 = 44;     // 2nd button of espresso


char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'.','0','#', 'D'}
};

byte pin_rows[ROW_NUM]      = {10, 7, 6, 11}; //  connect to the row pins
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; // connect to the column pins
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
LiquidCrystal_I2C lcd(0x27, 20, 4);


void setup() {
  // put your setup code here, to run once:

  lcd.init();
  lcd.backlight(); 
  SPI.begin();
  RC522.init();
  //CoffeeSen.begin();
 // MilkSen.begin();

  Serial.begin(9600);
//------------ Dc -----------//
  // Set motor connections as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(H1, INPUT);
  pinMode(H2, INPUT);
  pinMode(H3, INPUT);
  pinMode(H4, INPUT);
  // Stop motors
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);

  

  //---- initialize ultrasonic sensor pins ----//
  pinMode(TRIGGER_PIN_1, OUTPUT); // Sets the TRIGGER_PIN as an Output
  pinMode(ECHO_PIN_1, INPUT); // Sets the ECHO_PIN as an Input
  pinMode(TRIGGER_PIN_2, OUTPUT); // Sets the TRIGGER_PIN as an Output
  pinMode(ECHO_PIN_2, INPUT); // Sets the ECHO_PIN as an Input
  //stepper
   //---- initialize the relay pins as outputs ----//
  pinMode(stepPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(stepPin4, OUTPUT);
  pinMode(stepPin5, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  pinMode(dirPin5, OUTPUT);
//  pinMode(enPin,OUTPUT);

  //stepper1.setEnablePin(enPin);
  stepper1.setPinsInverted(false, false, true);
    //stepper2.setEnablePin(enPin);
  stepper2.setPinsInverted(false, false, true);
    //stepper3.setEnablePin(enPin);
  stepper3.setPinsInverted(false, false, true);
    //stepper4.setEnablePin(enPin);
  stepper4.setPinsInverted(false, false, true);
    //stepper5.setEnablePin(enPin);
  stepper5.setPinsInverted(false, false, true);

 //---- initialize the relay pins as outputs ----//
  pinMode(relayN1, OUTPUT);
  pinMode(relayN2, OUTPUT);
  pinMode(relayN3, OUTPUT);
  pinMode(relayN4, OUTPUT);
  pinMode(relayN5, OUTPUT);
 //---- start with relays off ----//
  digitalWrite(relayN1, HIGH); 
  digitalWrite(relayN2, HIGH);
  digitalWrite(relayN3, HIGH);
  digitalWrite(relayN4, HIGH);
  digitalWrite(relayN5, HIGH); 

  stopmotors();
  digitalWrite(relayN5, LOW);
  delay(1500);
  digitalWrite(relayN5, HIGH);
  homeScup();
  homeLcup();
  stopmotors();
  //updateUser();
  //takeorder();
}


void loop() {

// Coffeetemp();
// Milktemp();
 c=0;
 s=0;
 con=0;//0
 conn=0;
 u=0;
 menu=1;//1
 cup=1;
 esp=1;
 user=1;
 cursor=0;
 done=0; //0
 siz=0;//0
//stopmotors();
updateUser();
takeorder();
sequence();
delay(1000);

}
