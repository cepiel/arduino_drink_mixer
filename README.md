# Arduino Drink Mixer - AKA "The Barduino"

This is the code for 3 different Arduinos, which I used in a project to create an automatic drink machine.
It was fully functional and could mix several different preset drinks at the press of a button!

The 3 Arduinos were wired together such that Arduino 1 controlled several buttons that would mix different drinks. 
Arduino 2 controlled an LCD dislpay that showed you the menu and then the status of what the drink-mixer was doing or mixing.
Arduino 3 received messages of what to pour and controlled the pumps varying amounts to mix the drinks. The 3 Arduinos communicated
via serial and all sent messages to one another to work in tandem. So once a button was pressed, Arduino 1 send A2 the drink, so it 
would update the display to say what drink it was pouring, and A2 would send A3 the drink. A3 knew which drink meant which recipe to pour,
and followed the pre-programmed recipes to turn on whichever pumps for whatever duration.

Example: A user placed their cup below the ends of the pumps, gathered in front. If you clicked the button for Vodka Soda, the pump connected 
to vodka would run long enough to pour 2 ounces of vodka, and then the pump connected to club soda would pump long enough to 
pour 6 ounces of soda. This was *tested* working and drinks were drank to make sure the measurements and tastes worked well. 
