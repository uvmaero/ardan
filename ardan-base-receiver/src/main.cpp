/**
 * @file main.cpp
 * @author dominic gasperini
 * @brief ARDAN base station receiver 
 * @version 0.1
 * @date 2022-11-01
 */


// --- defines --- // 
#define TIMER_INTERRUPT_PRESCALER         80          // this is based off to the clock speed (assuming 80 MHz), gets us to microseconds
#define LORA_PARSE_INTERVAL               100000      // 0.1 seconds in microseconds
#define BASE_STATION_UPDATE_INTERVAL      50000       // 0.05 seconds in microseconds


// --- includes --- // 
#include <Arduino.h>
#include <LoRa.h>


// --- global variables --- //
bool messageReceivedFlag = false;
bool messageTransferedFlag = false;

// Drive Mode Enumeration Type
enum DriveModes
{
  SLOW = 0,
  ECO = 10,
  FAST = 20
};

// Car Data Struct
struct CarData
{
  struct DrivingData
  {
    bool readyToDrive = false;
    bool enableInverter = false;

    bool imdFault = false;
    bool bmsFault = false;

    uint16_t commandedTorque = 0;
    float currentSpeed = 0.0f;
    bool driveDirection = true;             // true = forward | false = reverse
    DriveModes driveMode = ECO;
  } drivingData;
  
  struct BatteryStatus
  {
    uint16_t batteryChargeState = 0;
    int16_t busVoltage = 0;
    int16_t rinehartVoltage = 0;
    float pack1Temp = 0.0f;
    float pack2Temp = 0.0f;
  } batteryStatus;

  struct Sensors
  {
    uint16_t wheelSpeedFR = 0;
    uint16_t wheelSpeedFL = 0;
    uint16_t wheelSpeedBR = 0;
    uint16_t wheelSpeedBL = 0;

    uint16_t wheelHeightFR = 0;
    uint16_t wheelHeightFL = 0;
    uint16_t wheelHeightBR = 0;
    uint16_t wheelHeightBL = 0;

    uint16_t steeringWheelAngle = 0;
  } sensors;

  struct Inputs
  {
    uint16_t pedal0 = 0;
    uint16_t pedal1 = 0;
    uint16_t brake0 = 0;
    uint16_t brake1 = 0;
    uint16_t brakeRegen = 0;
    uint16_t coastRegen = 0;

    float vicoreTemp = 0.0f;
    float pumpTempIn = 0.0f;
    float pimpTempOut = 0.0f;
  } inputs;

  struct Outputs
  {
    bool buzzerActive = false;
    uint8_t buzzerCounter = 0;
    bool brakeLight = false;
  } outputs;
  
};
CarData carData;

// Hardware ISR Timers
hw_timer_t* timer0 = NULL;
hw_timer_t* timer1 = NULL;
hw_timer_t* timer2 = NULL;
hw_timer_t* timer3 = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;


// --- function headers --- //
void GetNewData();


// --- setup --- //
void setup() {
  // --- initalize serial monitor --- // 
  Serial.begin(9600);
  Serial.println("LoRa Receiver");

  // --- initialize LoRa module --- // 
  if (!LoRa.begin(915E6)) {
    Serial.println("INIT LoRa [ FAILED ]");
    while (1);
  }

  // --- initialize timer interrupts --- //
  timer0 = timerBegin(0, TIMER_INTERRUPT_PRESCALER, true);
  timerAttachInterrupt(timer0, &GetNewData, true);
  timerAlarmWrite(timer0, LORA_PARSE_INTERVAL, true);
  timerAlarmEnable(timer0);
}


// --- loop --- // 
void loop() {
  // print status messages
  
  // write to serial bus

}


/**
 * @brief
 * 
 */
void GetNewData() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    while (LoRa.available()) {
      LoRa.readBytes((uint8_t) *carData, sizeof(carData));
    }

  }
}