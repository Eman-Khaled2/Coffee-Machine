void homecapsule(){     //stepper8
  stepper1.enableOutputs();
  stepper1.setMaxSpeed(SPD);
  stepper1.setAcceleration(ACCEL); 
  stepper1.move(-1000); Serial.println(digitalRead(H3));                        
    while (digitalRead(H3)) { 
      stepper1.run();
      }
  stepper1.disableOutputs();
  }
 void homecapejec(){    //stepper7
  stepper2.enableOutputs();
  stepper2.setMaxSpeed(SPD);
  stepper2.setAcceleration(ACCEL); 
  stepper2.move(130); 
      while (digitalRead(H4)) { 
      stepper2.run();
      }   
  stepper2.disableOutputs();
}
 void ejectcap(){
    stepper2.enableOutputs();
  stepper2.setMaxSpeed(100);
  stepper2.setAcceleration(ACCEL); 
  stepper2.move(-105); 
         while ( stepper2.distanceToGo() < 0) { 
      stepper2.run();
      }
  stepper2.disableOutputs();
}
void homeesp(){
  if(digitalRead(H1)==HIGH && digitalRead(H2)==LOW){
     while(digitalRead(H1)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
}
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
}
void homeLcup(){
    stepper3.enableOutputs();
  stepper3.setMaxSpeed(SPD);
  stepper3.setAcceleration(ACCEL); 
  stepper3.move(200); 
      while (digitalRead(limit1)) { 
      stepper3.run();
      }
  stepper3.disableOutputs();
}
void homeScup(){
  stepper4.enableOutputs();
  stepper4.setMaxSpeed(SPD);
  stepper4.setAcceleration(ACCEL); 
  stepper4.move(200); 
      while (digitalRead(limit2)) { 
      stepper4.run();
      }
  stepper4.disableOutputs();
}
void homebelt(){
  stepper5.enableOutputs();
  stepper5.setMaxSpeed(SPD);
  stepper5.setAcceleration(ACCEL); 
   stepper5.move(-3000); 
      while (digitalRead(limit3)) { 
      stepper5.run();
      }
  stepper5.disableOutputs();
}
 void HtoL(){
  stepper5.enableOutputs();
  stepper5.setMaxSpeed(SPD);
  stepper5.setAcceleration(ACCEL); 
  stepper5.move(800); 
          while ( stepper5.distanceToGo() > 0) { 
       stepper5.run();
       }
  stepper1.disableOutputs();
}
 void takeout(){
  stepper5.enableOutputs();
  stepper5.setMaxSpeed(SPD);
  stepper5.setAcceleration(ACCEL); 
  stepper5.move(-1000); 
          while ( stepper5.distanceToGo() < 0) { 
       stepper5.run();
       }
  stepper1.disableOutputs();
}
void LtoPour(){
   stepper5.enableOutputs();
  stepper5.setMaxSpeed(SPD);
  stepper5.setAcceleration(ACCEL); 
  stepper5.move(650);
          while ( stepper5.distanceToGo() > 0) { 
       stepper5.run();
       }
       stepper5.disableOutputs();
}
void StoPour(){
   stepper5.enableOutputs();
  stepper5.setMaxSpeed(100);
  stepper5.setAcceleration(500); 
  stepper5.move(1400);
          while ( stepper5.distanceToGo() > 0) { 
       stepper5.run();
} stepper5.disableOutputs();
       }
       
void ejectScup(){
  stepper4.enableOutputs();
  stepper4.setMaxSpeed(SPD);
  stepper4.setAcceleration(ACCEL); 
  stepper4.move(200); 
        while ( stepper4.distanceToGo() > 0) { 
       stepper4.run();
       }
  stepper4.disableOutputs();
}
void ejectLcup(){
  stepper3.enableOutputs();
  stepper3.setMaxSpeed(SPD);
  stepper3.setAcceleration(ACCEL); 
  stepper3.move(200); 
        while ( stepper3.distanceToGo() > 0) { 
       stepper3.run();
       }
  stepper3.disableOutputs();
}