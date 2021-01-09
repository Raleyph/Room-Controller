void setup() {
  Keyboard.begin();
  strip.setBrightness(60);

  lcd.begin();
  lcd.setBacklight();
  lcd.createChar(0, UKRAINE);

  // экран приветствия
  startScreen();
}

void loop() {
  int smokeSensor = analogRead(SMOKE);
  
  if (Digital.Read(GUARD_PIN)) {
    closeWindow();
  }

  if (millis() - Timer1 >= SCAN_GAS_PERIOD) {
    Timer1 = millis();
    
    if (smokeSensor > sensor) {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("ATTENTION! GAS!");
  
      digitalWrite(ALARM_PIN, HIGH);
    }
  }

  switch (mode) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      rainbow();
  }

  breathing();
  strip.show();
  delay(30);      // 30 FPS
}

void closeWindow() {
  Keyboard.press(KEY_PRESS);
  Keyboard.press(MODIFER);
  delay(100);
  Keyboard.releaseAll();
  delay(100);
}

void startScreen() {
  lcd.setCursor(0, 4);
  lcd.print("RoomController");
  lcd.setCursor(1, 5);
  lcd.print("v. 0.1 Alpha");
  lcd.setCursor(2, 0);
  lcd.print("Makabos Technologies");
  lcd.setCursor(3, 9);
  lcd.print("2021");
}
