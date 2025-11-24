// Define Pins​
// Define Pins
#define BLUE 6
#define GREEN 5
#define RED 3

//LEDs
const int redLED = 4;
const int blueLED = 7;
const int yellowLED = 8;
const int greenLED = 2;
const int whiteLED = 9;

//Buttons
const int buttonMoney = 12;
const int buttonDrink1 = 11;
const int buttonDrink2 = 10;

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
  if(isCyanRGB()){
    if (money_ButtonPressed()){
      activateYellowRGB();
     }
  }

  if(isYellowRGB()){
    if (money_ButtonPressed()){
      activateMagentaRGB();
    }
  }

  if(isMagentaRGB()){
    if (money_ButtonPressed()){
      flashGreenLED();
    }
    else if(drink1_ButtonPressed()){
      flashYellowLED();
      flashBlueLED();
      activateCyanRGB();
    }
    else if(drink2_ButtonPressed()){
      flashWhiteLED();
      flashBlueLED();
      activateCyanRGB();
    }
  }

  //fail to buy
  if(isCyanRGB() || isYellowRGB()){
    if (drink1_ButtonPressed() || drink2_ButtonPressed()){
      flashRedLED();
    }
  }
}

void activateCyanRGB(){
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  delay(500);
  
  redValue =  LOW;
  greenValue = HIGH;
  blueValue = HIGH;
}

void activateMagentaRGB(){
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  delay(500);

  redValue =  HIGH;
  greenValue = LOW;
  blueValue = HIGH;
}

void activateYellowRGB(){
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

void flashGreenLED(){
  digitalWrite(greenLED, HIGH);
  delay(500);
  digitalWrite(greenLED, LOW);
  delay(500);
}

void flashYellowLED(){
  digitalWrite(yellowLED, HIGH);
  delay(500);
  digitalWrite(yellowLED, LOW);
  delay(500);
}

void flashBlueLED(){
  digitalWrite(blueLED, HIGH);
  delay(500);
  digitalWrite(blueLED, LOW);
  delay(500);
}

void flashWhiteLED(){
  digitalWrite(whiteLED, HIGH);
  delay(500);
  digitalWrite(whiteLED, LOW);
  delay(500);
}

bool isCyanRGB(){
  return redValue == LOW && greenValue == HIGH && blueValue == HIGH;
}

bool isYellowRGB(){
  return redValue == HIGH && greenValue == HIGH && blueValue == LOW;
}

bool isMagentaRGB(){
  return redValue == HIGH && greenValue == LOW && blueValue == HIGH;
}

bool money_ButtonPressed(){
  return digitalRead(buttonMoney) == LOW;
}

bool drink1_ButtonPressed(){
  return digitalRead(buttonDrink1) == LOW;
}

bool drink2_ButtonPressed(){
  return digitalRead(buttonDrink2) == LOW;
}