
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void startDustbin(){
  delay(1000);
  if(digitalRead(A1) == HIGH){
    metalDispose();
  }
  else{
    nonMetalDispose();
  }
}

void nonMetalDispose(){
  plateDown();
  plateUp();
}

void metalDispose(){
  bucketLeft();
  plateDown();
  plateUp();
  bucketRight();
}

void bucketRight(){
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1250);                      // wait for a second
  digitalWrite(12, LOW);   // turn the LED off by making the voltage LOW
}

void bucketLeft(){
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1250);                      // wait for a second
  digitalWrite(11, LOW);   // turn the LED off by making the voltage LOW
}

void plateDown(){
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);                      // wait for a second
  digitalWrite(10, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);
}

void plateUp(){
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(200);                      // wait for a second
  digitalWrite(9, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(A0) == 0) {
    startDustbin();
  }
}
