const int time_on = 500;

const int outputs[] = {P2_5, P2_4, P1_5, P1_4, P1_3, P1_2, P4_3, P4_0, P3_7, P8_2};
const int outputs_len = 6; // Change to limit output number
const int signal = P8_2;
const int minSignalLength = 1500;

#define LED RED_LED

int nextOutput = 0;
int isDown = false;
bool buttonPressed = false;
long sigLen = 0;

void setup() {
  // initialize the pins as outputs:
  
  for (int i = 0; i < outputs_len; i++) {
    pinMode(outputs[i], OUTPUT);
    digitalWrite(outputs[i], LOW);
  }
  // initialize the pushbutton pin as an input:
  pinMode(LED, OUTPUT);      
  pinMode(signal, INPUT);
}

void loop()
{
  sigLen = pulseIn(signal, HIGH);
  buttonPressed = sigLen > minSignalLength;

  if (buttonPressed && !isDown) {
    digitalWrite(LED, HIGH);
    digitalWrite(outputs[nextOutput], HIGH); 
    
    delay(time_on);
    
    digitalWrite(outputs[nextOutput], LOW); 
    
    nextOutput++;
    if (nextOutput >= outputs_len) {
      nextOutput = 0;
    } 
    
    digitalWrite(LED, LOW);
    isDown = true;
  }
  if (!buttonPressed) {
    isDown = false;
  }
}
