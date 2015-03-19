/* 
 Debounce + long button press
 This example code is based on: http://www.arduino.cc/en/Tutorial/Debounce

  created 21 November 2006
    by David A. Mellis
  modified 30 Aug 2011
    by Limor Fried
  modified 28 Dec 2012
    by Mike Walters
  modified 19 Mar 2015
    by Alberto de Vera Sevilla
*/

const int buttonPin = 2;

int buttonState;               // the current reading from the input pin
int lastButtonState = LOW;     // the previous reading from the input pin
long lastDebounceTime = 0;     // the last time the output pin was toggled
long debounceDelay = 60;       // the debounce time; increase if the output flickers
long downPress = 0;            // the "milis()" value when the button is pressed
long upPress = 0;              // the "milis()" value when the button returns to his position
long longPressTime = 1500;     // the time difference between short and long button press (in milliseconds)

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {

      if (reading != buttonState) {
          buttonState = reading;
    
          if (buttonState == HIGH) {
              downPress = millis();
          }else{
              upPress = millis();
              
              if(upPress - downPress > longPressTime ){
                  Serial.println("LONG");
              }else{
                  Serial.println("SHORT");
              }
          }
      }
  }
  
  lastButtonState = reading;
}
