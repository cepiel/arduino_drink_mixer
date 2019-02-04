#include <LiquidCrystal.h>



// initialize the library by associating any needed LCD interface pin with the arduino pin number it is connected to
 const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int listener;


void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);  
  lcd.print("Robot Bartender");
  lcd.setCursor(0,1);
  lcd.print("Press a button...");

  delay(3000);
  listener = -1;
  //arr = "";
}

void loop() {

  listener = Serial.read();
  //lcd.print(listener);

  if(listener==1){   //vodka shot
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Currently mixing:");
    lcd.setCursor(0,1);
    lcd.print("Shot of Vodka");

    //delay(48000);
    delay(62000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Drink finished!"); delay(2000);
    lcd.clear();
    listener=0;
  }
  else if(listener==2){   //gin shot
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Currently mixing:");
    lcd.setCursor(0,1);
    lcd.print("Shot of Gin");

    //delay(48000);
    delay(62000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Drink finished!"); delay(2000);
    lcd.clear();
    listener=0;
  }
  else if(listener==3){   //vodka tonic
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Currently mixing:");
    lcd.setCursor(0,1);
    lcd.print("Vodka Tonic");

    //delay(72000);
    delay(126000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Drink finished!"); delay(2000);
    lcd.clear();
    listener=0;
  }
  
  else if(listener==4){   //gin tonic
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Currently mixing:");
    lcd.setCursor(0,1);
    lcd.print("Gin & Tonic");

    //delay(72000);
    delay(126000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Drink finished!"); delay(2000);
    lcd.clear();
    listener=0;
  }
  else if(listener==5){  //vodka sprite
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Currently mixing:");
    lcd.setCursor(0,1);
    lcd.print("Vodka Sprite");

    delay(174000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Drink finished!"); delay(2000);
    lcd.clear();
    listener=0;
  }  
  else {
    lcd.clear();
    lcd.setCursor(0,0);  
    lcd.print("Robot Bartender");
    lcd.setCursor(0,1);
    lcd.print("Press a button...");
    delay(100);
    //listener=0;
  }
  
  
  
 
  
}
