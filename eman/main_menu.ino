void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Please make order..");
  lcd.setCursor(0, 1);lcd.print("->>Coffee");
  lcd.setCursor(3, 2);lcd.print("Coffee & Milk");
  lcd.setCursor(3, 3);lcd.print("Espresso");
      break;
    case 2:
    lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Please make order..");
  lcd.setCursor(3, 1);lcd.print("Coffee");
  lcd.setCursor(0, 2);lcd.print("->>Coffee & Milk");
  lcd.setCursor(3, 3);lcd.print("Espresso");
      break;
    case 3:
      lcd.clear();
  lcd.setCursor(0, 0);lcd.print("Please make order..");
  lcd.setCursor(3, 1);lcd.print("Coffee");
  lcd.setCursor(3, 2);lcd.print("Coffee & Milk");
  lcd.setCursor(0, 3);lcd.print("->>Espresso");
      break;
    case 4:
      menu = 3;
      break;
  }
}

void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
  }
}

void action1() {
  lcd.clear();
  lcd.print("selected>>Coffee");
  delay(1500);
  c=1;
}
void action2() {
  lcd.clear();
  lcd.print("selected>>Coffee & Milk");
  delay(1500);
  c=1;
}
void action3() {
  lcd.clear();
  lcd.print("selected>>Espresso");
  delay(1500);
  c=1;
}