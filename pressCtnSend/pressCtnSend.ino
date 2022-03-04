const byte btnPin = 15;
bool sent = false;
int pressCnt = -1 ;
String outString;
char out[2];

void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(btnPin) && !sent){
    delay(100); //debouncing
    pressCnt++;
    Serial.print(pressCnt);
    sent = true;  
  }
  if(!digitalRead(btnPin)){
    sent = false;
  }
}
