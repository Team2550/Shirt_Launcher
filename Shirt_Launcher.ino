const int time_on = 500;

const int outputs[] = {P2_5, P2_4, P1_5, P1_4, P1_3, P1_2, P4_3, P4_0, P3_7, P8_2};
const int cannon_outputs = 6; // Change to limit output number
const int launchSignal = P8_2;
const int steerSignal = P3_7;
const int potentSignal = P4_0;
const int steering = ;
// Switch signal inputs to analog inputs to make room for other outputs
const int launchSignalLength = 1500;

#define LED RED_LED

int nextOutput = 0;
int isDown = false;
bool buttonPressed = false;
long sigLen = 0;

void setup() {
  // initialize the pins as outputs:
  
  for (int i = 0; i < cannon_outputs; i++) {
    pinMode(outputs[i], OUTPUT);
    digitalWrite(outputs[i], LOW);
  }
  // initialize the pushbutton pin as an input:
  pinMode(LED, OUTPUT);      
  pinMode(launchSignal, INPUT);
}

void loop()
{
  sigLen = pulseIn(launchSignal, HIGH);
  buttonPressed = sigLen > launchSignalLength;

  if (buttonPressed && !isDown) {
    digitalWrite(LED, HIGH);
    digitalWrite(outputs[nextOutput], HIGH); 
    
    delay(time_on);
    
    digitalWrite(outputs[nextOutput], LOW); 
    
    nextOutput++;
    if (nextOutput >= cannon_outputs) {
      nextOutput = 0;
    } 
    
    digitalWrite(LED, LOW);
    isDown = true;
  }
  if (!buttonPressed) {
    isDown = false;
  }
}
