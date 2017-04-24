
int forward = 13;
int backward = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(forward, 255);
  delay(5000);
  analogWrite(forward, 0);
  analogWrite(backward, 255);
  delay(5000);
  analogWrite(backward, 0);
}
