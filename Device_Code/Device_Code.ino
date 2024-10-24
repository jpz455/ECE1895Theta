#include <stdio.h>
#include <stdlib.h>

//Create the global variables
int score, time, playing;

//Define the pins
#define SOLDER_PIN 4
#define CODE_PIN 5
#define MULTIMETER_PIN 23

typedef enum {
    SOLDER_IT,
    CODE_IT,
    MULTIMETER_IT
} COMMAND;

void setup() {
  //Connect to the serial monitor
  Serial.begin(9600);

  Serial.println("Startup");

  //Set the global variables
  score = 0;
  time = 0;
  playing = true;

  //Set the pins as inputs
  pinMode(SOLDER_PIN, INPUT);
  pinMode(CODE_PIN, INPUT);
  pinMode(MULTIMETER_PIN, INPUT);

}

void loop() {
  //Loop through the main code if we are in the play condition
  if(playing){
    //We will generate a random command here
    COMMAND curentTask = SOLDER_IT;

    //Check the input while the time is counting down
    while(time > 0){
      //Once we receive a command check if it matches the randomly generated command
      //If it does, break out of the loop and continue. If it doesn't break out of the loop and end the game

      //If the solder pin is high, the solder action has been completed
      if(digitalRead(SOLDER_PIN) == HIGH){
        Serial.println("Soldering is being done");
      }

      //If the code pin is high, the code action has been completed
      if(digitalRead(CODE_PIN) == HIGH){
        Serial.println("Coding is being done");
      }

      //If the anologue pin is not close to 0 (being pulled down), the multimeter action is being complete
      if(analogRead(MULTIMETER_PIN) > 10){
        //Check to make sure the correct resistor is being probed (the analogue input is in the right range)
        Serial.println(analogRead(MULTIMETER_PIN));
      }
    }
    
  }

}
