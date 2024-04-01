#define Solenoid 12
#define ldr 8
int Buzzer = 4;
int GreenLed = 6;
int RedLed = 11;
int val;
int val2;
String duration = "";

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT_PULLUP);
  pinMode(Solenoid, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  digitalWrite(RedLed, HIGH);
}

void OpenDoor() {            
  digitalWrite(Solenoid, HIGH);
  tone(Buzzer, 500);
  digitalWrite(RedLed, LOW);
  digitalWrite(GreenLed, HIGH);
  
  delay(3000);
  digitalWrite(Solenoid, LOW);
  noTone(Buzzer);
  digitalWrite(RedLed, HIGH);
  digitalWrite(GreenLed, LOW);
}

void loop() {
  int val = digitalRead(ldr);
  
  while (val == 0) {
    int val2 = digitalRead(ldr);
    duration += val2;

    if (duration == "0001") {
      OpenDoor();
      duration = ""; // Reset duration
    }
  
    if (val2 == 1) {
      duration = "";
      break;
    }

    delay(200);
  }
}
