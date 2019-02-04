/*
  LUCAS CEPIEL
  CS 361 FINAL PROJECT
  
  Bartender Robot 5000
  OR
  BARDuino 5000
 
*/

const int b1 = 9;  // button for vodka shot
const int b2 = 10;   // button for gin shot
const int b3 = 11;   // button for vodka tonic
const int b4 = 12;   // button for gin tonic
const int b5 = 13;   // button for vodka sprite

int buttonState1;   //variables for reading the buttons
int buttonState2;
int buttonState3;
int buttonState4;
int buttonState5;

byte lastState1=LOW;
byte lastState2=LOW;
byte lastState3=LOW;
byte lastState4=LOW;
byte lastState5=LOW;


void setup()

{
  Serial.begin(9600);  //Begin serial communcation

  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  pinMode(b5, INPUT);

  delay(1000); // let relays settle down before running the first time.
}



void loop()   //this part of the code loops and loops forever
{

  buttonState1 = digitalRead(b1); // read for vodka shot
  buttonState2 = digitalRead(b2); // read for gin shot
  buttonState3 = digitalRead(b3); // read for vodka tonic
  buttonState4 = digitalRead(b4); // read for gin tonic
  buttonState5 = digitalRead(b5); // read for vodka sprite


  //now check each button state for if one is read, then send appropriate
  //signal to make the appropriate drink


  if(buttonState1 && buttonState1 != lastState1) //does nothing if button is held down
  {      
    Serial.write(1); //if button is pressed, sends signal via serial.

    //Serial.println("Button 1 pressed");
    
  } 
  lastState1 = buttonState1;
  
  if(buttonState2 && buttonState2 != lastState2) //does nothing if button is held down
  {      
    Serial.write(2); //if button is pressed, sends signal via serial.
    
    //Serial.println("Button 2 pressed");
    
  } 
  lastState2 = buttonState2;
  
  if(buttonState3 && buttonState3 != lastState3) //does nothing if button is held down
  {      
    Serial.write(3); //if button is pressed, sends signal via serial.

    //Serial.println("Button 3 pressed");
    
  } 
  lastState3 = buttonState3;
  
  if(buttonState4 && buttonState4 != lastState4) //does nothing if button is held down
  {      
    Serial.write(4); //if button is pressed, sends signal via serial.

    //Serial.println("Button 4 pressed");
    
  } 
  lastState4 = buttonState4;
  
  if(buttonState5 && buttonState5 != lastState5) //does nothing if button is held down
  {      
    Serial.write(5); //if button is pressed, sends signal via serial.
    
    //Serial.println("Button 5 pressed");
    
  } 
  lastState5 = buttonState5;
  
  buttonState1 = LOW;
  buttonState2 = LOW;
  buttonState4 = LOW;
  buttonState5 = LOW;
  buttonState5 = LOW;
  
  delay(1000);
  
}
