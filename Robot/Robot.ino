
const int lf = 13;
const int lb = 12;
const int rf = 11;
const int rb = 10;

const int fTrig = 22; 
const int fEcho = 23;
const int lTrig = 24;
const int lEcho = 25;

void setup() {
  // put your setup code here, to run once:
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);

  pinMode(fTrig, OUTPUT);
  pinMode(fEcho, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  if (Serial.available() > 0) {
    int incommingByte = Serial.read();
    Serial.println(incommingByte);
    if (incommingByte == 102) {
      forward(5000);
    } else {
      analogWrite(lf, 0);
    }
  }
 
  forward(1000);
  delay(1000);
  backward(1000);
  delay(1000);
  */
  if (frontDistance() > 50){
    forward(1000);
  }
  delay(1000);
}

void forward(int duration) {
  analogWrite(rf, 255);
  analogWrite(lf, 255);
  delay(duration);
  analogWrite(rf, 0);
  analogWrite(lf, 0);
}

void backward(int duration) { 
  analogWrite(lb, 255);
  analogWrite(rb, 255);
  delay(1000);
  analogWrite(lb, 0);
  analogWrite(rb, 0);
}

int frontDistance() {
  digitalWrite(fTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(fTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(fTrig, LOW);
  
  int duration = pulseIn(fEcho, HIGH);
  
  int distance = duration * 0.034 / 2;

  //Serial.println(distance);
  return distance;
}

void leftDistance() {
  
}




