/* 
  Проект "Контроллер комнаты"
  GitHub:
  Автор: Makabos, Makabos Technologies, 2021
*/

//-------------- НАСТРОЙКИ --------------
#define KEY_PRESS KEY_D       // какая кнопка будет нажата
#define MODIFIER MOD_GUI_LEFT // модификатор (кнопка LWIN)

#define STRIP_PIN 6           // пин ленты
#define NUMLEDS 100           // количество светодиодов

#define LCD_ADRESS 0x27;      // адрес lcd дисплея (0x27 или 0x3f

#define ALARM_PIN 5           // пин баззера
#define GUARD_PIN 4           // пин сигнализации

#define SMOKE A0              // пин датчика газа
#define SCAN_GAS_PERIOD 1500  // период опроса датчика дыма (мс)
//-------- ПОДКЛЮЧЕНИЕ БИБЛИОТЕК --------
#include <Keyboard.h>
#include <microLED.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "IRemote.h"
//------------- ПЕРЕМЕННЫЕ --------------
LiquidCrystal_I2C lcd(LCD_ADRESS, 20, 4);
microLED<NUMLEDS, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip;

byte mode;
uint32_t Timer1;
int sensor = 400;             // пороговое значение АЦП

byte UKRAINE[] = { B00100, B10101, B11111, B11111, B10101, B11011, B00100, B00000 };
