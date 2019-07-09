const int ProxSensor=5;
int LED = 16;
uint8_t ServoMotorpin = D2;

void setup() 
{                
  pinMode(LED, OUTPUT);          // Pin 13 has an LED connected on most Arduino boards:  
  pinMode(ProxSensor,INPUT);    //Pin 2 is connected to the output of proximity sensor
  Serial.begin(9600);
  analogWrite(ServoMotorpin, 512);
  analogWriteFreq(50);  /* Set PWM frequency to 50Hz */
}

void loop() 
{
  long state = digitalRead(ProxSensor);
  if(state == HIGH)      //Check the sensor output
  {
    digitalWrite(LED, HIGH);   // set the LED on
    Serial.println(state);
    delay(1000);
  }
  else
  {
    digitalWrite(LED, LOW);    // set the LED off
    Serial.println(state);
    delay(1000);
  }
  uint16_t dutycycle=  analogRead(A0); /* Read potentiometer to control servo motor */
  if(dutycycle> 1023) dutycycle = 1023;
  dutycycle = 25+((85*dutycycle/1023)); /* make it in range 20 to 110 */
  analogWrite(ServoMotorpin, dutycycle);  /* Write duty cycle to pin */
  delay(100);

}
