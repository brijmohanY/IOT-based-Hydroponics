
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3


long duration;
int distance;
int volume ;
const int area =  7857; // (sq cm) calculated concidering 500 ltr tank having radius around 50cm .
const int height = 75; // height from bottom of tank 

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
}

void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);


distance= duration*0.034/2;
volume = area*(height-distance);

Serial.print("Distance: ");
Serial.println(distance);
Serial.print("Volume: ");
Serial.println(volume);
delay(2000);
}
