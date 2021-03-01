// Resistance = 220 Ohm;

int LED_Green = 13, LED_Yellow = 12, LED_Red = 11;
int time_green_on = 300, delta_t = 300;   //ms

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_Green, OUTPUT);
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Yellow, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_Green, HIGH);
  digitalWrite(LED_Yellow, LOW);
  digitalWrite(LED_Red, LOW);
  
  delay(time_green_on);
  
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Yellow, HIGH);
  digitalWrite(LED_Red, LOW);

  delay(time_green_on + delta_t);

  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Yellow, LOW);
  digitalWrite(LED_Red, HIGH);
  
  delay(time_green_on + 2*delta_t);
}
