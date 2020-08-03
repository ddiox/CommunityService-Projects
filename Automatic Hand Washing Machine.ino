#define trigPin 5
#define echoPin 6
int lowLevel = 5;
int highLevel = 90;
int pump = 13;

void setup() {
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pump, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  if (distance > lowLevel && distance < highLevel){
    digitalWrite(pump,1);
    Serial.println("ON");
    delay(10000);
    digitalWrite(pump,0);
    Serial.println("OFF");
  }
  delay(50);
}
