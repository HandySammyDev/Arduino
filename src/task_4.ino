// Define Pins​
// Define Pins
#define BLUE 6
#define GREEN 5
#define RED 3

//LEDs
const int redLED = 12;
const int blueLED = 10;
const int yellowLED = 9;
const int greenLED = 2;
const int whiteLED = 11;

//Buttons
const int buttonMoney = 7;
const int buttonDrink1 = 8;
const int buttonDrink2 = 4;

void setup(){
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(greenLED, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  pinMode(buttonMoney, INPUT_PULLUP);
  pinMode(buttonDrink1, INPUT_PULLUP);
  pinMode(buttonDrink2, INPUT_PULLUP);
}

// define variables
int redValue =  LOW;
int greenValue = HIGH;
int blueValue = HIGH;

// main loop
void loop(){
  if(isCyan()){
    if (moneyButtonPressed()){
      activateYellowLED();
     }
  }

  if(isYellow()){
    if (moneyButtonPressed()){
      activateMagentaLED();
    }
  }

  if(isMagenta()){
    if (moneyButtonPressed()){
      flashRedLED();
    }
  }

  //fail to buy
  if(isCyan() || isYellow()){
    if (drink1_ButtonPressed() || drink2_ButtonPressed()){
      flashRedLED();
    }
  }

  if(isMagenta()){
    if (drink1_ButtonPressed()){

      activateCyanLED();
      flashYellowThenBlueLED();
   }

   if(drink2_ButtonPressed()){

      flashWhiteThenBlueLED();
      activateCyanLED();
    }  
  }
}

void activateCyanLED(){
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  delay(500);
  
  redValue =  LOW;
  greenValue = HIGH;
  blueValue = HIGH;
}

void activateMagentaLED(){
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  delay(500);

  redValue =  HIGH;
  greenValue = LOW;
  blueValue = HIGH;
}

void activateYellowLED(){
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
  delay(500);

  redValue =  HIGH;
  greenValue = HIGH;
  blueValue = LOW;
}

void flashRedLED(){
  digitalWrite(redLED, HIGH);
  delay(500);
  digitalWrite(redLED, LOW);
}

void flashYellowThenBlueLED(){
  digitalWrite(yellowLED, HIGH);
  delay(500);
  digitalWrite(yellowLED, LOW);
  delay(500);
  digitalWrite(blueLED, HIGH);
  delay(500);
  digitalWrite(blueLED, LOW);
}

void flashWhiteThenBlueLED(){
  digitalWrite(whiteLED, HIGH);
  delay(500);
  digitalWrite(whiteLED, LOW);
  delay(500);
  digitalWrite(blueLED, HIGH);
  delay(500);
  digitalWrite(blueLED, LOW);
}

bool isCyan(){
  return redValue == LOW && greenValue == HIGH && blueValue == HIGH;
}

bool isYellow(){
  return redValue == HIGH && greenValue == HIGH && blueValue == LOW;
}

bool isMagenta(){
  return redValue == HIGH && greenValue == LOW && blueValue == HIGH;
}

bool moneyButtonPressed(){
  return digitalRead(buttonMoney) == LOW;
}

bool drink1_ButtonPressed(){
  return digitalRead(buttonDrink1) == LOW;
}

bool drink2_ButtonPressed(){
  return digitalRead(buttonDrink2) == LOW;
}