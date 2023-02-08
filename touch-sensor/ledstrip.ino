#include <FastLED.h>

//definiëren van de pins en het aantal leds
#define LED_PIN     7
#define NUM_LEDS    300
#define ctsPin 2 


//definiëren van de 
 int ledPin = 13;
 int colours = 0;


CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  
  pinMode(ctsPin, INPUT);


  
}

void loop() {

      { 

      
      int ctsValue = digitalRead(ctsPin); 

      //if statement die de onderstaande code activeert wanneer de sensor aanraking detecteert
      if (ctsValue == HIGH)
        {  
          //switch wordt aangemaakt
          switch(colours){
            //met cases wordt een cyclus gemaakt van kleuren
          case 0:
          delay(1000);
          //om de een seconde wordt elke case uitgevoerd

            for (int led = 0; led < NUM_LEDS; led++)
            {
              //kleuren worden gedefiniërd door rgb codes
               leds[led] = CRGB(255,255,255);
            }
           FastLED.show();
          case 1:
            delay(1000);
             for (int led = 0; led < NUM_LEDS; led++)
              {
                 leds[led] = CRGB(149,0,0);
              }
          FastLED.show();
          case 2:
            delay(1000);
             for (int led = 0; led < NUM_LEDS; led++)
              {
                 leds[led] = CRGB(0,0,149);
              }
          FastLED.show();
          case 3:
             delay(1000);
             for (int led = 0; led < NUM_LEDS; led++)
              {
                 leds[led] = CRGB(255, 98, 4);
              }
          FastLED.show();
       
          }
            


         //in de seriële monitor wordt ook textueel aangegeven
           Serial.println("TOUCHED");

           } 

           
//als de sensor geen aanraking detecteert, dan wordt deze code uitgevoerd
     else

        {    

         digitalWrite(ledPin,LOW);

            //de code is niet veel veranderd, maar de kleuren codes hebben waardes van 0, wat resulteert in geen licht
             for (int led = 0; led < NUM_LEDS; led++)
              {
                 leds[led] = CRGB(0,0,0);
              }
             FastLED.show();
            

          }  

      delay(0.9);  

      }
  
  
}
