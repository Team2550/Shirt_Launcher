//ENERGIA
const int steerSignal = P6_1;
const int potentiometer = P6_2;
const int steeringMotor = P8_2;

const long joystickMin = 500;
const long joystickMax = 2500;
const int potentMin = 100;
const int potentMax = 923;

const int centerVal = 512;

long steerLength = 0;
long steeringValue;
int potentVal;
int targetVal;


void steering_setup() {
  pinMode(steerSignal, INPUT);
  //pinMode(potentSignal, INPUT);
  //pinMode(steeringMotor, OUTPUT);
}

void steering_loop() {
  steerLength = pulseIn(launchSignal, HIGH);
  potentVal = analogRead(potentiometer);
  
  steeringValue = ((steerLength-joystickMin)/(joystickMax-joystickMin));
  steeringValue *= 255;
  potentVal = map(potentVal, 0, 1023, 0, 255);
  
  if (potentVal > steeringValue) {
     analogWrite(steeringMotor, 0);
  } else if (potentVal < steeringValue) {
     analogWrite(steeringMotor, 255);
  } else {
     analogWrite(steeringMotor, 127);
  }
}
