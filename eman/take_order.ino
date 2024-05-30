void takeorder(){
  key = keypad.getKey(); 
while(done==0){
   key = keypad.getKey();   
  if (key == 'B'){
       if(u==0){
       user++;
       updateUser();
    }
    else if(c==0 && u==1 && user!=3){
      menu++;
      updateMenu();
    }
    else if(s==0 && c==1 && menu!=3 && user!=3){
       cup++;
       updateCup();
    }
     else if(conn==0 && menu==3 && user!=3){
        esp++;
        updateEsp();
      }  
    delay(200);
  }
  
  if (key == 'A'){
    if(u==0){
       user--;
       updateUser();
    }
    if(c==0 && u==1 && user!=3){
      menu--;
      updateMenu();
      }
     else if(s==0 && c==1 && menu!=3 && user!=3){
      cup--;
      updateCup();      
    } 
     else if(conn==0 && menu==3 && user!=3){
        esp--;
        updateEsp();
      }
      delay(200);
    //while(analogRead(downButton)<500);
  }
  
  if (key == '#'){
    if (u==0){
     executeUser();
      if (user != 3) 
         updateMenu();
      else {
         lcd.clear();
        lcd.setCursor(0, 0);lcd.print("Order through app.");
      }
    }
    else if(c==0 && u==1 && user!=3){
      executeAction();
      if (menu != 3) updateCup();
      else updateEsp();
    }
     else if(s==0 && c==1 && menu!=3 && user!=3){
    executecup();
   // updateSodium();
    }
    else if(conn==0 && c==1 && menu==3 && user!=3){
      executesp();
      //updatepotassium();
    }
  }
} 
}