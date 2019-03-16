int moistureSensorPin = A0;
int moistureThreshold = 40; // if the read moisture is lower than this, open the valve
                             // value is between 0-100
int moistureValue = 0; // the value read by the sensor
int valvePin = 13;
int valveOpenTime = 15000; // milliseconds to stay open

void setup() {
  // put your setup code here, to run once:
  pinMode(valvePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // read the moisture sensor value and convert some units
  // the analogRead() function will return a number between 0 and 1023
  // we want to work with 0-100 to make it easy, so we convert
  // moistureValue/100 = x/1023 -> moistureValue = (x/1023)*100
  
  moistureValue = (analogRead(moistureSensorPin)/1023)*100;
  
  if (moistureValue < moistureThreshold){
    digitalWrite(valvePin, HIGH); // open the valve
    delay(valveOpenTime);
    digitalWrite(valvePin, LOW); // close the valve
    delay(60*1000); // wait for one minute
  }
}
