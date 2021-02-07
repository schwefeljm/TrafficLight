#define aStop 19
#define aYield 15
#define aGo 14

#define bStop 5
#define bYield 4
#define bGo 3

#define nightSwitch 2

bool nightMode = 0;


// the setup function runs once when you press reset or power the board
void setup() {
//  aStop = 19
//  aYield = 19
//  aGo = 19

  attachInterrupt(digitalPinToInterrupt(nightSwitch), nightSwitchISR, RISING);
  
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(aStop, OUTPUT);
  pinMode(aYield, OUTPUT);
  pinMode(aGo, OUTPUT);

  pinMode(bStop, OUTPUT);
  pinMode(bYield, OUTPUT);
  pinMode(bGo, OUTPUT);



  digitalWrite(aStop, HIGH);
  digitalWrite(bGo, HIGH);
  delay(100);
  digitalWrite(aYield, HIGH);
  digitalWrite(bYield, HIGH);
  delay(100);
  digitalWrite(aGo, HIGH);
  digitalWrite(bStop, HIGH);
  delay(100);
  
  digitalWrite(aStop, LOW);
  digitalWrite(bGo, LOW);
  delay(100);
  digitalWrite(aYield, LOW);
  digitalWrite(bYield, LOW);
  delay(100);
  digitalWrite(aGo, LOW);
  digitalWrite(bStop, LOW);
  delay(100);

  aStopSet();
  bStopSet();
  
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(aStop, HIGH);
  //Serial.print(nightMode);
  Serial.print(millis());
  Serial.print("\n");

if (nightMode) {
  digitalWrite(aYield, HIGH);
  digitalWrite(bStop, LOW);
  delay(500);

  digitalWrite(aYield, LOW);
  digitalWrite(bStop, HIGH);
  delay(500);
}
else {

  aStopSet();
  delay(500);
  bGoSet();
  delay(5000);

  bYieldSet();
  delay(1000);

  bStopSet();
  delay(500);
  aGoSet();
  delay(7500);

  aYieldSet();
  delay(1000);
}
}

void aStopSet() {
  digitalWrite(aStop, HIGH);
  digitalWrite(aYield, LOW);
  digitalWrite(aGo, LOW);
}

void aYieldSet() {
  digitalWrite(aYield, HIGH);
  digitalWrite(aGo, LOW);
  digitalWrite(aStop, LOW);
}

void aGoSet() {
  digitalWrite(aGo, HIGH);
  digitalWrite(aStop, LOW);
  digitalWrite(aYield, LOW);
}


void bStopSet() {
  digitalWrite(bStop, HIGH);
  digitalWrite(bYield, LOW);
  digitalWrite(bGo, LOW);
}

void bYieldSet() {
  digitalWrite(bYield, HIGH);
  digitalWrite(bGo, LOW);
  digitalWrite(bStop, LOW);
}

void bGoSet() {
  digitalWrite(bGo, HIGH);
  digitalWrite(bStop, LOW);
  digitalWrite(bYield, LOW);
}

void nightSwitchISR() {
  noInterrupts();
  //Serial.print("\n");
  //Serial.print(nightMode);
  //Serial.print("\n");
  //Serial.print("Night Mode ISR Pressed\n");
  Serial.print(millis());
  Serial.print("\t\tISR\n");
  //delay(3000);
  nightMode = !nightMode;
  interrupts();
}

void PrintState(char *Seq) {
  Serial.print(Seq);
  Serial.print("\t-\t");
  Serial.print(digitalRead(LED_BUILTIN));
  Serial.print("\t");
  Serial.print(digitalRead(aStop));
  Serial.print("\t");
  Serial.print(digitalRead(aYield));
  Serial.print("\t");
  Serial.print(digitalRead(aGo));
  Serial.print("\n");

}
