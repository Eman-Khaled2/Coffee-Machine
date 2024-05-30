void updateCup() {
  switch (cup) {
    case 0:
      cup = 1;
      break;
    case 1:
      lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Choose cup size...");
  lcd.setCursor(0, 1);lcd.print("->>Large");
  lcd.setCursor(3, 2);lcd.print("Small");
      break;
    case 2:
    lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Choose cup size...");
  lcd.setCursor(3, 1);lcd.print("Large");
  lcd.setCursor(0, 2);lcd.print("->>Small");
      break;
    case 3:
      cup = 2;
      break;
  }
}

void executecup() {
  switch (cup) {
    case 1:
      actioncup1();
      break;
    case 2:
      actioncup2();
      break;
  }
}

void actioncup1() {
  lcd.clear();
  lcd.print("selected>>Large");
  delay(1500);
  s=1;
  siz=1;
  done=1;
  if (menu ==1) {
  ultra1();
  Coffeetemp();
  if(distance_1<=10){
   lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Wait for order");
  lcd.setCursor(0, 2);lcd.print("coff Temp.");
  lcd.setCursor(11, 2);lcd.print(coffeetemp);
  delay(1500);
  while(coffeetemp <= 40){
   Coffeetemp(); 
  digitalWrite(relayN1, LOW);
  lcd.setCursor(11, 2);lcd.print(coffeetemp); 
  delay(1000);
  }
   digitalWrite(relayN1, HIGH); 
  }
  else {
  lcd.clear();
  lcd.setCursor(0, 0);lcd.print("check T1 level");
  lcd.setCursor(0, 2);lcd.print("coff Dist.");
  lcd.setCursor(11, 2);lcd.print(distance_1);
  delay(2000);
  done=0;
  }
  }
    else if (menu ==2) {
  ultra1();
  ultra2();
  Coffeetemp();
  Milktemp();
  if(distance_1<=10){
   lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Wait for order");
  lcd.setCursor(0, 2);lcd.print("coff Temp.");
  lcd.setCursor(11, 2);lcd.print(coffeetemp);
  lcd.setCursor(0, 3);lcd.print("Milk Temp.");
  lcd.setCursor(11, 3);lcd.print(milktemp);
  delay(1500);
  while(coffeetemp <= 40 || milktemp <=40){
  Coffeetemp();
  Milktemp();
   if (coffeetemp <= 40)digitalWrite(relayN1, LOW);else digitalWrite(relayN1, HIGH);
   if (milktemp <=   40)digitalWrite(relayN2, LOW);else digitalWrite(relayN2, HIGH);
    lcd.setCursor(11, 2);lcd.print(coffeetemp);
    lcd.setCursor(11, 3);lcd.print(milktemp);
  delay(1000);
  }
   digitalWrite(relayN1, HIGH); 
   digitalWrite(relayN2, HIGH);
  }
  else {
  lcd.clear();
  lcd.setCursor(0, 0);lcd.print("check Tanks level");
  lcd.setCursor(0, 2);lcd.print("coff Dist.");
  lcd.setCursor(11, 2);lcd.print(distance_1);
  lcd.setCursor(0, 3);lcd.print("Milk Dist.");
  lcd.setCursor(11, 3);lcd.print(distance_1);
  delay(2000);
  done=0;
  }
  }
}
void actioncup2() {
  lcd.clear();
  lcd.print("selected>>Small");
  delay(1500);
  s=1;
  siz=2;
  done=1;
  if (menu ==1) {
  ultra1();
  Coffeetemp();
  if(true){
   lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Wait for order");
    lcd.setCursor(0, 2);lcd.print("coff Temp.");
  lcd.setCursor(11, 2);lcd.print(coffeetemp);
  delay(1500);
  while(coffeetemp <= 40){
   Coffeetemp(); 
  digitalWrite(relayN1, LOW); 
  lcd.setCursor(11, 2);lcd.print(coffeetemp);
  delay(1000);
  }
   digitalWrite(relayN1, HIGH); 
  }
  else {
  lcd.clear();
  lcd.setCursor(0, 0);lcd.print("check T1 level");
      lcd.setCursor(0, 2);lcd.print("coff Dist.");
  lcd.setCursor(11, 2);lcd.print(distance_1);
  delay(2000);
  done=0;
  }
  }
    else if (menu ==2) {
  ultra1();
  ultra2();
  Coffeetemp();
  Milktemp();
  if(distance_1<=10){
   lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Wait for order");
  lcd.setCursor(0, 2);lcd.print("coff Temp.");
  lcd.setCursor(11, 2);lcd.print(coffeetemp);
  lcd.setCursor(0, 3);lcd.print("Milk Temp.");
  lcd.setCursor(11, 3);lcd.print(milktemp);
  delay(1500);
  while(coffeetemp <= 40 || milktemp <=40){
  Coffeetemp();
  Milktemp();
   if (coffeetemp <= 40)digitalWrite(relayN1, LOW);else digitalWrite(relayN1, HIGH);
   if (milktemp <= 40)digitalWrite(relayN2, LOW);else digitalWrite(relayN2, HIGH);
    lcd.setCursor(11, 2);lcd.print(coffeetemp);
    lcd.setCursor(11, 3);lcd.print(milktemp);
  delay(1000);
  }
   digitalWrite(relayN2, HIGH); 
   digitalWrite(relayN1, HIGH);
  }
  else {
       lcd.clear();
  lcd.setCursor(0, 0);lcd.print("check Tanks level");
  lcd.setCursor(0, 2);lcd.print("coff Dist.");
  lcd.setCursor(11, 2);lcd.print(distance_1);
  lcd.setCursor(0, 3);lcd.print("Milk Dist.");
  lcd.setCursor(11, 3);lcd.print(distance_1);
  delay(2000);
  done=0;
  }
  }
}

