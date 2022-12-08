
#define echoPin 6 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 7 //attach pin D3 Arduino to pin Trig of HC-SR04
#define LED_PIN 10




// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int state = 0;
const int MIC_PIN = A0;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(MIC_PIN, INPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  digitalWrite(LED_BUILTIN ,LOW);  

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  state = analogRead(MIC_PIN);

  if(duration > 0) {
     Serial.print("Microphone: ");
     Serial.println(state);
     digitalWrite(LED_BUILTIN, HIGH);  
     delay(1000);
  }

  if(duration > 0) {
     Serial.print("Distance: ");
     Serial.print((duration *0.034)/2);
     Serial.println(" cm");
     digitalWrite(LED_BUILTIN, HIGH);  
     delay(1000);
  }
}
