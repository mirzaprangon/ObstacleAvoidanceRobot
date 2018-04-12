#define ledPin 8 //this is the led pin 
#define ledPin2 9 
#define ledPin3 10


class Sonar{
 
  public:
  int triggerPin;
  int echoPin;
  long distance, duration;
 void sonar(int trig, int echo){  //custom initializer
triggerPin = trig;
echoPin = echo;
pinMode(triggerPin, OUTPUT);
pinMode(echoPin, INPUT);
}
};

class Testing{
  public:
  
static bool isObstaclePresent(Sonar s){  //checking an obstacle is within less than or equal five centimeters

digitalWrite(s.triggerPin, LOW);
delayMicroseconds(2);
digitalWrite(s.triggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(s.triggerPin, LOW);
s.duration = pulseIn(s.echoPin, HIGH);
s.duration /= 29; //for converting miliseconds to centimeters
s.duration /= 2; //for getting the actual distance
s.distance = s.duration;
if(s.distance <= 5){ //checking if the distance is less or equal five
   
    Serial.print("this is for sonar: ");
  Serial.println(s.distance);
   return true;
  
  
  }
else{
    
    Serial.print("this is for sonar: ");
  Serial.println(s.distance);
  return false;
  
  }
  
}
};

Sonar sonar1;
Sonar sonar2;
Sonar sonar3;
void setup() {
  // put your setup code here, to run once:

sonar1.sonar(2, 3); // sonar(trig, eho);
sonar2.sonar(4, 5); 
sonar3.sonar(6, 7);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if((Testing::isObstaclePresent(sonar1) == true) ){ //checking the obstacle for sonar1
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,HIGH);
  delay(40);
 // Serial.println(sonar1.distance);
   //Serial.println(sonar2.distance);
   // Serial.println(sonar3.distance);
  //delay(10);
  }
  else   digitalWrite(ledPin,LOW);

  
   if((Testing::isObstaclePresent(sonar2) == true)){
     pinMode(ledPin2,OUTPUT);
     digitalWrite(ledPin2,HIGH);
    delay(40);
  }
 else  digitalWrite(ledPin2,LOW);


if((Testing::isObstaclePresent(sonar3) == true)){
  pinMode(ledPin3,OUTPUT);
  digitalWrite(ledPin3,HIGH);
   delay(40); //delay after every checking
 // Serial.println(sonar1.distance);
   //Serial.println(sonar2.distance);
   // Serial.println(sonar3.distance);
 // delay(10);
  }
  else   digitalWrite(ledPin3,LOW);
}
