//www.elegoo.com
//2016.12.8

// Define Pins​
// Define Pins
#define BLUE 6
#define GREEN 5
#define RED 3
int drink1LED = 2;
int redLED = 12;
int buttonMoney = 7;
int buttonDrink1 = 8;
int blueLED = 10;
int yellowLED = 9;


void setup()
{
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
pinMode(drink1LED, OUTPUT);
digitalWrite(RED, LOW);
digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, HIGH);
pinMode(buttonMoney, INPUT_PULLUP);
pinMode(buttonDrink1, INPUT_PULLUP) ;
}

// define variables
int redValue =  LOW;
int greenValue = HIGH;
int blueValue = HIGH;

// main loop
void loop()
{
  if(redValue == LOW && greenValue == HIGH && blueValue == HIGH)
  {
    if ((digitalRead(buttonMoney) == LOW))
   {
     digitalWrite(RED, HIGH);
     digitalWrite(GREEN, HIGH);
     digitalWrite(BLUE, LOW);
     delay(500);
     redValue =  HIGH;
     greenValue = HIGH;
     blueValue = LOW;

   }

  }

  if(redValue == HIGH && greenValue == HIGH && blueValue == LOW)
  {
    if ((digitalRead(buttonMoney) == LOW))
   {
     digitalWrite(RED, HIGH);
     digitalWrite(GREEN, LOW);
     digitalWrite(BLUE, HIGH);
     delay(500);
     redValue =  HIGH;
     greenValue = LOW;
     blueValue = HIGH;
   }
  }

  if(redValue == HIGH && greenValue == LOW && blueValue == HIGH)
  {
    if ((digitalRead(buttonMoney) == LOW))
   {
     digitalWrite(redLED, HIGH);
     delay(500);
     digitalWrite(redLED, LOW);
   }
  }

//Cyan and yellow fail to buy
  if((redValue == LOW && greenValue == HIGH && blueValue == HIGH) ||
  (redValue == HIGH && greenValue == HIGH && blueValue == LOW))
  {
    if ((digitalRead(buttonDrink1) == LOW))
   {
     digitalWrite(redLED, HIGH);
     delay(500);
     digitalWrite(redLED, LOW);
   }
  }

  if(redValue == HIGH && greenValue == LOW && blueValue == HIGH)
  {
    if ((digitalRead(buttonDrink1) == LOW))
   {
     digitalWrite(RED, LOW);
     digitalWrite(GREEN, HIGH);
     digitalWrite(BLUE, HIGH);
     delay(500);
     redValue =  LOW;
     greenValue = HIGH;
     blueValue = HIGH;

     digitalWrite(yellowLED, HIGH);
     delay(500);
     digitalWrite(yellowLED, LOW);
     delay(500);
     digitalWrite(blueLED, HIGH);
     delay(500);
     digitalWrite(blueLED, LOW);
   }
  }
}

