void Milktemp() {
    MilkSen.requestTemperatures(); 
    
     milktemp = MilkSen.getTempCByIndex(0);
  
    if(milktemp != DEVICE_DISCONNECTED_C)
    {
      Serial.println("Temp Milk: ");
      Serial.print(milktemp);
    }
}

void Coffeetemp() {
    CoffeeSen.requestTemperatures(); 
    
    coffeetemp = CoffeeSen.getTempCByIndex(0);
  
    if(coffeetemp != DEVICE_DISCONNECTED_C)
    {
      Serial.println("Temp coffee: ");
      Serial.print(coffeetemp);
    }
}
