
void updateEsp() {
  switch (esp) {
    case 0:
      esp = 1;
      break;
    case 1:
      lcd.clear();
  lcd.setCursor(0, 0);lcd.print("choose concentration");
  lcd.setCursor(0, 1);lcd.print("->>20% Espresso");
  lcd.setCursor(3, 2);lcd.print("40% Espresso");
  lcd.setCursor(3, 3);lcd.print("60% Espresso");
      break;
    case 2:
    lcd.clear();
  lcd.setCursor(0, 0);lcd.print("choose concentration");
  lcd.setCursor(3, 1);lcd.print("20% Espresso");
  lcd.setCursor(0, 2);lcd.print("->>40% Espresso");
  lcd.setCursor(3, 3);lcd.print("60% Espresso");
      break;
    case 3:
      lcd.clear();
  lcd.setCursor(0, 0);lcd.print("choose concentration");
  lcd.setCursor(3, 1);lcd.print("20% Espresso");
  lcd.setCursor(3, 2);lcd.print("40% Espresso");
  lcd.setCursor(0, 3);lcd.print("->>60% Espresso");
      break;
          case 4:
    lcd.clear();
  lcd.setCursor(0, 0);lcd.print("->>80% Espresso");
  lcd.setCursor(3, 1);lcd.print("100% Espresso");
      break;
    case 5:
      lcd.clear();
  lcd.setCursor(3, 0);lcd.print("80% Espresso");
  lcd.setCursor(0, 1);lcd.print("->>100% Espresso");
      break;
    case 6:
      esp = 5;
      break;
  }
}

void executesp() {
  switch (esp) {
    case 1:
      actionesp1();
      break;
    case 2:
      actionesp2();
      break;
    case 3:
      actionesp3();
      break;
    case 4:
      actionesp4();
      break;
    case 5:
      actionesp5();
      break;
  }
}

void actionesp1() {
  lcd.clear();
  lcd.print("selected>>20%");
  delay(1500);
  conn=1; 
  con=1;
  done=1;
}
void actionesp2() {
  lcd.clear();
  lcd.print("selected>>40%");
  delay(1500);
  conn=1;
  con=2;
  done=1;
}
void actionesp3() {
  lcd.clear();
  lcd.print("selected>>60%");
  delay(1500);
  conn=1;
  con=3;
  done=1;
}
void actionesp4() {
  lcd.clear();
  lcd.print("selected>>80%");
  delay(1500);
  conn=1;
  con=4;
  done=1;
}
void actionesp5() {
  lcd.clear();
  lcd.print("selected>>100%");
  delay(1500);
  conn=1;
  con=5;
  done=1;
}

void cap1(){
   stepper1.enableOutputs();
  stepper1.setMaxSpeed(SPD);
  stepper1.setAcceleration(ACCEL); 
  stepper1.move(-183);Serial.println(SPD); 
      while ( stepper1.distanceToGo() < 0) { 
      stepper1.run();
      }stepper1.disableOutputs();
}
void cap2(){
   stepper1.enableOutputs();
  stepper1.setMaxSpeed(SPD);
  stepper1.setAcceleration(ACCEL); 
  stepper1.move(-369);Serial.println(SPD);
      while ( stepper1.distanceToGo() < 0) { 
      stepper1.run();
      }stepper1.disableOutputs();
}
void cap3(){
   stepper1.enableOutputs();
  stepper1.setMaxSpeed(SPD);
  stepper1.setAcceleration(ACCEL); 
  stepper1.move(-551);
      while ( stepper1.distanceToGo() < 0) { 
      stepper1.run();
      }stepper1.disableOutputs();
}
void cap4(){
   stepper1.enableOutputs();
  stepper1.setMaxSpeed(SPD);
  stepper1.setAcceleration(ACCEL); 
  stepper1.move(-735);
      while ( stepper1.distanceToGo() < 0) { 
      stepper1.run();
      }stepper1.disableOutputs();
}

void espmake(){
  if(digitalRead(H2)==HIGH && digitalRead(H1)==LOW){
     while(digitalRead(H2)){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
}
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
}
