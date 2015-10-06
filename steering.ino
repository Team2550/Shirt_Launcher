const int steerSignal = P6_1;
const int potentiometer = P6_2;
const int steeringMotor = P8_2;

const int centerVal;

long steerLength = 0;
int potentVal;
int targetVal;


void steering_setup() {
  pinMode(steerSignal, INPUT);
  //pinMode(potentSignal, INPUT);
  pinMode(steeringMotor, OUTPUT);
}

void steering_loop() {
  steering = pulseIn(launchSignal, HIGH);
  potentVal = analogRead(potentiometer);
  
}
