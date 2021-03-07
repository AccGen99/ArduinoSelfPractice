int trigPin = 13, echoPin = 11, epochs = 25;
float pingTime, speedOfSound = 0.0, distance;
float iniDist = 0.15;

void setup() {
  // put your setup code here, to run once:
  int i = 0;
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Calibration to determine speed of sound in current medium
  //25 epochs
  Serial.println("Initiating Calibration - ");
  delay(500);
  for (i = 0; i<epochs;i++) {
    Serial.print("Epoch : ");
    Serial.println(i+1);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2000);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    pingTime = pulseIn(echoPin, HIGH) * 0.000001;  //Measures time in microseconds
    speedOfSound += 2.0 * iniDist / pingTime;
    delay(1000);
    }
   speedOfSound /= 25;
   delay(1500);
   if (speedOfSound <= 310.0 || speedOfSound >= 360.0) {
    Serial.println("Calibration Failed!");
    Serial.print("Obtained Value of ");
    Serial.print(speedOfSound);
    Serial.println(" m/s out of bounds");
    Serial.println("   Using standard value of 343 m/s");
    speedOfSound = 343.0;
    }
   else {
    Serial.println("Calibration Successful!");
    Serial.print("Speed of sound in immediate surroundings = ");
    Serial.print(speedOfSound);
    Serial.println(" m/s");
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  // Time taken by wave to reach obstacle and come back
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTime = pulseIn(echoPin, HIGH) * 0.000001;  //Measures time in microseconds

  distance = speedOfSound * pingTime;
  Serial.print("Distance to obstacle - ");
  Serial.print(distance);
  Serial.println(" m");
  delay(1000);
}
