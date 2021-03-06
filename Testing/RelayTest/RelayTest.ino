/* function declaration */

void setupRelay();
void turnHeaterOn();
void turnHeaterOff();
void turnCompressorOn();
void turnCompressorOff();

#define heaterPin A2
#define compressorPin A1

//relay variables
boolean heaterState = false;
boolean compressorState = false;


String serialInput;

void setup() {
  Serial.begin(9600); //init serial communication
  Serial.println("Starting relay test");
  setupRelay();
}

void loop() {
  while (Serial.available()) {
    serialInput = Serial.readString(); // read the incoming data as string
    Serial.println("");
    serialInput.toLowerCase();
    serialInput.trim();
    if (serialInput.equals("heater on")) {
      turnHeaterOn();
    } else if (serialInput.equals("heater off")) {
      turnHeaterOff();
    } else if (serialInput.equals("compressor on")) {
      turnCompressorOn();
    } else if (serialInput.equals("compressor off")) {
      turnCompressorOff();
    } else {
      Serial.println("Not a recognized command");
      Serial.println("Use the following commands");
      Serial.println("heater on");
      Serial.println("heater off");
      Serial.println("compressor on");
      Serial.println("compressor off");
    }
      Serial.println(serialInput);
    Serial.println("");
  }
}

void setupRelay() {
  pinMode(heaterPin, OUTPUT);
  pinMode(compressorPin, OUTPUT);
  digitalWrite(heaterPin, HIGH); //high is off
  digitalWrite(compressorPin, HIGH); //high is off
}

void turnHeaterOn() {
  digitalWrite(heaterPin, LOW); //high is off
  heaterState = true;
}
void turnHeaterOff() {
  digitalWrite(heaterPin, HIGH); //high is off
  heaterState = false;
}
void turnCompressorOn() {
  digitalWrite(compressorPin, LOW); //high is off
  compressorState = true;
}
void turnCompressorOff() {
  digitalWrite(compressorPin, HIGH); //high is off
  compressorState = false;
}

