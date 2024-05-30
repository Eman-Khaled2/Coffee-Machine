void updateUser() {
  switch (user) {
    case 0:
      user = 1;
      break;
    case 1:
      lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Select user type...");
  lcd.setCursor(0, 1);lcd.print("->>RF Card");
  lcd.setCursor(3, 2);lcd.print("1 time password");
  lcd.setCursor(3, 3);lcd.print("Application");
      break;
    case 2:
    lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Select user type...");
  lcd.setCursor(3, 1);lcd.print("RF Card");
  lcd.setCursor(0, 2);lcd.print("->>1 time password");
  lcd.setCursor(3, 3);lcd.print("Application");
      break;
    case 3:
      lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Select user type...");
  lcd.setCursor(3, 1);lcd.print("RF Card");
  lcd.setCursor(3, 2);lcd.print("1 time password");
  lcd.setCursor(0, 3);lcd.print("->>Application");
      break;
    case 4:
      user = 3;
      break;
  }
}

void executeUser() {
  switch (user) {
    case 1:
      actionU1();
      break;
    case 2:
      actionU2();
      break;
    case 3:
      actionU3();
      break;
  }
}

void actionU1 () {
  lcd.clear();
  lcd.print("selected>> RF Card");
  delay(1500);

   while (cardid != "5237417365"){
      lcd.clear();
      lcd.print("Place your card");
      delay(1000);

  if (RC522.isCard())
  {
      lcd.clear();
      lcd.print("RF Card detected");
    /* If so then get its serial number */
    RC522.readCardSerial();
    Serial.println("Card detected:");
    for(int i=0;i<5;i++)
    {
    Serial.println(RC522.serNum[i],DEC);
    cardid += RC522.serNum[i];
    //
    //Serial.print(RC522.serNum[i],HEX); //to print card detail in Hexa Decimal format
    }
  }
  }
  lcd.clear();
  lcd.print("RF Card is accepted");
  delay(1500);
  u=1;
  cardid = "";
}
void actionU2() {
  lcd.clear();
  lcd.print("selected>> password");
  delay(1500);

  lcd.clear();
  lcd.print("Insert password");
  lcd.setCursor(0, 2);lcd.print("->>");
  
   key = keypad.getKey();  
  while (key != '#'||cursor==3){
    key = keypad.getKey(); 
  if (key) {
    lcd.setCursor(cursor+4, 2);lcd.print(key);
   pass[cursor] = key;
    passval=pass[cursor]-'0'; 
  if (cursor==3)tval =tval-passval;
  if (cursor<=2)tval =tval+passval;
   cursor++;
    }
  }
  if (tval % 2 == 0){
    u=1; 
  lcd.clear();
  lcd.print(" pass is correct");
  delay(1500);
  }
else {
  
  lcd.clear();
  lcd.print("pass is incorrect");
  delay(1500);
  while(1){
delay(5000);
  }
  

}
}

void actionU3() {
  lcd.clear();
  lcd.print("selected>>Application");
  delay(1500);
  u=1;
}