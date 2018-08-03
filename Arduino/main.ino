/*  Develop by Jimmy Hu, 2018
 *  Arduino Digital Pin4連接至繼電器，輸出High時SSR OFF，輸出Low時SSR ON。
 *  Version 2 : 藍芽傳'Lock_open'門鎖開，藍芽傳'Lock_close'門鎖關。
 */


//***函式庫引用區***
#include  <SoftwareSerial.h>                                                            //  引用<SoftwareSerial.h>函式庫
//***定義變數區***
#define Lock_Control_Pin 4                                                              //  定義電鎖控制接腳為第4接腳
#define Bluetooth_KEY 5                                                                 //  定義藍芽傳輸模組KEY接腳連接至arduino第5接腳
#define Bluetooth_RxD 8                                                                 //  定義藍芽傳輸模組RxD接腳連接至arduino第8接腳
#define Bluetooth_TxD 7                                                                 //  定義藍芽傳輸模組TxD接腳連接至arduino第7接腳
#define History_quota 20                                                                //  Define History_quota - a quota of storage of history data

SoftwareSerial BTSerial(Bluetooth_RxD, Bluetooth_TxD);                                  //  建立軟體定義串列埠BTSerial，用以控制藍芽模組

//***副程式宣告區***
void Lock_open(void);                                                                   //  宣告Lock_open開鎖副程式
void Lock_close(void);                                                                  //  宣告Lock_close關鎖副程式


char Received_data[History_quota];

// the setup function runs once when you press reset or power the board
// setup程式於按下reset按鈕或通電時執行一次
void setup()                                                                            //  setup程式
{                                                                                       //  進入setup程式
  pinMode(Lock_Control_Pin, OUTPUT);                                                    //  設定電鎖控制接腳為輸出
  digitalWrite(Lock_Control_Pin, HIGH);                                                 //  設定電鎖控制接腳為高態(SSR OFF)
  pinMode(Bluetooth_KEY, OUTPUT);                                                       //  設定arduino連接藍芽傳輸模組KEY之接腳為輸出
  digitalWrite(Bluetooth_KEY, LOW);                                                     //  設定藍芽傳輸模組KEY接腳為LOW
  Serial.begin(38400);                                                                  //  開啟 Serial Port透過USB(uart)方式與電腦通信，鮑率為 38400bps (Bits Per Second)
  BTSerial.begin(9600);                                                                 //  開啟軟體定義串列埠BTSerial，鮑率為 9600bps (Bits Per Second)

  //***Initialize Received_data array***
memset(Received_data, ' ', sizeof(Received_data));
}
// the loop function runs over and over again forever
// loop程式將不斷重複執行
void loop()                                                                             //  loop程式
{                                                                                       //  進入loop程式
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())                                                             //  若BTSerial串列埠正常開啟
  {                                                                                     //  進入if敘述
  }
}                                                                                       //  結束loop程式
