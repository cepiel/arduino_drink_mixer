const int Vodka = 4;   // (pump1) 12VDC motor to pin 1
const int Gin = 5;     // (pump2) on pin 2
const int Tonic = 6;   // (pump3) on pin 3
const int Sprite = 7;  // (pump4) on pin 4

int listener;

void setup() {
  Serial.begin(9600);  
  listener=-1;
  
  pinMode(Vodka, OUTPUT);
  pinMode(Gin, OUTPUT);
  pinMode(Tonic, OUTPUT);
  pinMode(Sprite, OUTPUT);

  //dunno if these need to start on HIGH to be DEactivated (as shown in source's code) or LOW ...

  digitalWrite (Vodka, HIGH); //pump 1 off
  digitalWrite (Gin, HIGH); //pump 2 off
  digitalWrite (Tonic, HIGH); //pump 3 off
  digitalWrite (Sprite, HIGH); //pump 4 off

  delay(1000); // let relays settle down before running the first time.

}



void VodkaShot()
{
  //avg shot is 1 1/2 ounces (48 seconds based on the measurement: 1oz per 32 secs)
  Serial.write(1);
  
  digitalWrite (Vodka, LOW);      //pump 1 on
  //delay(48000);                   // waits 48 sec to pump 1 1/2 oz of liquid
  delay(64000);
  digitalWrite (Vodka, HIGH);     //turns off pump 1 
  }

void GinShot()
{
  //avg shot is 1 1/2 ounces (48 seconds based on the measurement: 1oz per 32 secs)
  Serial.write(2);
  
  digitalWrite (Gin, LOW);    
  //delay(48000);                 // waits 48 sec to pump 1 1/2 oz of liquid
  delay(64000);
  digitalWrite (Gin, HIGH);  
}

void VodkaTonic()
{
  //One commonly used recipe is one part vodka and 1.5 part tonic water over ice, with a lime wedge squeezed into it
  Serial.write(3);
  
  digitalWrite (Vodka, LOW);    
  digitalWrite (Tonic, LOW);
  delay(64000);                   // waits 48 sec to pump 1 1/2 oz of liquid
  digitalWrite (Vodka, HIGH);     //turns off vodka
  
  delay(64000);                   //delay for rest of tonic water
  digitalWrite (Tonic, HIGH);     //turn off tonic water

}

void GinTonic()
{
  //One commonly used recipe is one part gin and 1.5 part tonic water over ice, with a lime wedge squeezed into it
  Serial.write(4);
  
  digitalWrite (Gin, LOW);    
  digitalWrite (Tonic, LOW);
  delay(64000);                 // waits 48 sec to pump 1 1/2 oz of liquid
  digitalWrite (Gin, HIGH);     //turns off gin
  
  delay(64000);                 //delay for rest of tonic water
  digitalWrite (Tonic, HIGH);   //turn off tonic water
  

}

void VodkaSprite()
{
  //1.5 oz vodka, and 5 oz sprite, and squeeze a lime wedge into it
  Serial.write(5);
  
  digitalWrite (Vodka, LOW);    
  digitalWrite (Sprite, LOW);
  delay(64000);                   // waits 48 sec to pump 1 1/2 oz of liquid
  digitalWrite (Vodka, HIGH);     //turns off vodka
  
  delay(112000);                  // waits 112 more sec to pump the rest of the 5oz of sprite
  digitalWrite (Sprite, HIGH);
}





void loop() {
  
  listener = Serial.read();  //constantly read and wait for a signal
    
    if(listener==1){      
      VodkaShot();
       listener=-1; //reset listener to 0 to wait to receive another signal
       
    }else if(listener==2){      
      GinShot();
       listener=-1; //reset listener to 0 to wait to receive another signal
       
    } else if(listener==3){      
      VodkaTonic();
       listener=-1; //reset listener to 0 to wait to receive another signal
       
    } else if(listener==4){
       GinTonic();
       listener=-1; //reset listener to 0 to wait to receive another signal
       
    }else if(listener==5){      
      VodkaSprite();
       listener=-1; //reset listener to 0 to wait to receive another signal
       
    }
    else {
      Serial.print("ERROR: ");
      Serial.print(listener);
    }
    
  delay(1000);
  
}
