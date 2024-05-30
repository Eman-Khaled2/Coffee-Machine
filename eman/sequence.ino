void sequence(){
    if(done==1){
      switch (menu) {
    case 1:
  lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Please Wait...");
  lcd.setCursor(0, 2);lcd.print("preparing Coffee");
  if(siz==1){
    homebelt();
    HtoL();
    delay(500);
    ejectLcup();
    delay(2000);
    LtoPour();
    stopmotors();
    delay(200);
    digitalWrite(relayN3,LOW);
    delay(6000);
    digitalWrite(relayN3,HIGH);
    delay(2000);
    takeout();
  }
  else if(siz==2){
    homebelt();
    ejectScup();
    delay(2000);
    StoPour();
    stopmotors();
    delay(200);
    digitalWrite(relayN3,LOW);
    delay(3000);
    digitalWrite(relayN3,HIGH);
    delay(2000);
    takeout();
  }
      break;
    case 2:
    lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Please Wait...");
  lcd.setCursor(0, 2);lcd.print("preparing Cof.& Milk");
  if(siz==1){
    homebelt();
    HtoL();
    ejectLcup();
    delay(2000);
    LtoPour();
    stopmotors();
    delay(200);
    digitalWrite(relayN3,LOW);
    digitalWrite(relayN4,LOW);
    delay(4000);
    digitalWrite(relayN3,HIGH);
    digitalWrite(relayN4,HIGH);
    delay(2000);
    takeout();
  }
  else if(siz==2){
    homebelt();
    ejectScup();
    delay(2000);
    StoPour();
    stopmotors();
    delay(200);
  
    digitalWrite(relayN3,LOW);
    digitalWrite(relayN4,LOW);
    delay(2000);
    digitalWrite(relayN3,HIGH);
    digitalWrite(relayN4,HIGH);
    delay(2000);
    
    takeout();
  }
      break;
    case 3:
      lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Please Wait...");
  lcd.setCursor(0, 2);lcd.print("preparing Espresso");
  if(con==1){
    homebelt();
    delay(500);
    ejectScup();
    delay(2000);
    StoPour();
    homecapejec();
    homecapsule();
    delay(500);
    ejectcap();
    homecapejec();
    delay(1000);
    espmake();
    digitalWrite(relayN5,LOW);
    delay(1500);
    digitalWrite(relayN5,HIGH);
    delay(15000);
    takeout();
    homeesp();
  }
    else if(con==2){
   homebelt();
    delay(500);
    ejectScup();
    delay(2000);
    StoPour();
    homecapejec();
    homecapsule();
    delay(500);
    cap4();
    ejectcap();
    homecapejec();
    delay(1000);
    espmake();
    digitalWrite(relayN5,LOW);
    delay(1500);
    digitalWrite(relayN5,HIGH);
    delay(15000);
    takeout();
    homeesp();
  }
    else if(con==3){
    homebelt();
    delay(500);
    ejectScup();
    delay(2000);
    StoPour();
    homecapejec();
    homecapsule();
    delay(1000);
    cap3();
    delay(500);
    ejectcap();
    homecapejec();
    delay(1000);
    espmake();
    digitalWrite(relayN5,LOW);
    delay(1500);
    digitalWrite(relayN5,HIGH);
    delay(15000);
    takeout();
    homeesp();
  }
    else if(con==4){
    homebelt();
    delay(500);
    ejectScup();
    delay(2000);
    StoPour();
    homecapejec();
    homecapsule();
    delay(500);
    cap2();
    ejectcap();
    homecapejec();
    delay(1000);
    espmake();
    digitalWrite(relayN5,LOW);
    delay(1500);
    digitalWrite(relayN5,HIGH);
    delay(15000);
    takeout();
    homeesp();
  }
    else if(con==5){Serial.print("Please Wait...");
    homebelt();
    delay(500);
    ejectScup();
    delay(2000);
    StoPour();
    homecapejec();
    homecapsule();
    delay(500);
    cap1();
    delay(500);
    ejectcap();
    delay(1000);
    espmake();
    digitalWrite(relayN5,LOW);
    delay(2000);
    digitalWrite(relayN5,HIGH);
    delay(15000);
    takeout();
    homeesp();
  }
      break;
    default:
    homecapejec();
    homecapsule();
    homeesp();
      break;
  }
  }
}