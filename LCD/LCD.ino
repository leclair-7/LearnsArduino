/*
 * Tutorial 8: Using the LCD
 * 
 * Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 * library works with all LCD displays that are compatible with the 
 * Hitachi HD44780 driver. There are many of them out there, and you
 * can usually tell them by the 16-pin interface.
 *
 * Adjust the LCDs contrast with the Potentiometer until you
 * can see the characters on the LCD.
 *
 * The circuit:
 * - LCD RS pin to digital pin 12
 * - LCD Enable pin to digital pin 11
 * - LCD D4 pin to digital pin 5
 * - LCD D5 pin to digital pin 4
 * - LCD D6 pin to digital pin 3
 * - LCD D7 pin to digital pin 2
 * - LCD R/W pin to ground
 * - 10K potentiometer divider for LCD pin VO:
 * - 330ohm resistor betweenm LCD pin A and 5v
 * - LCD pin K to ground
 *
 * Library originally added 18 Apr 2008
 * by David A. Mellis
 * library modified 5 Jul 2009
 * by Limor Fried (http://www.ladyada.net)
 * example added 9 Jul 2009
 * by Tom Igoe
 * modified 22 Nov 2010
 * by Tom Igoe
 * modified 14 August 2013
 * by Blaise Jarrett
 *
 * This example code is in the public domain.
 *
 * Derivative work from:
 * http://www.arduino.cc/en/Tutorial/LiquidCrystal
 *
 */

// include the library
#include <LiquidCrystal.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

// all of our LCD pins
int lcdRSPin = 12;
int lcdEPin = 11;
int lcdD4Pin = 5;
int lcdD5Pin = 4;
int lcdD6Pin = 3;
int lcdD7Pin = 2;

int motorInA = 8;
int motorInB = 13;
int motorPWM = 9;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(lcdRSPin, lcdEPin,
                  lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);

void setup()
{
    //pinMode(motorInA, OUTPUT);
    //pinMode(motorInB, OUTPUT);
    //pinMode(motorPWM, OUTPUT);
  
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
    Serial.begin(9600);
  
    // set up the LCD's number of columns and rows: 
    lcd.begin(16, 2);
    // Print a message to the LCD.
    //lcd.print("hello, world!");
}

void readJoystick(){  
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");

  delay(1000);
}

void loop()
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0)
    
    
    readJoystick();
    
    // print the number of seconds since reset
    //lcd.print("Lucas Rocks!!"); // millis() / 1000
    
    
    lcd.setCursor(0, 0);
    lcd.print("X-axis: ");
    lcd.print(analogRead(X_pin));
    
    lcd.setCursor(0, 1);
    lcd.print("Y-axis: ");
    lcd.print(analogRead(Y_pin));
    
    delay(500);
    lcd.noDisplay();
    lcd.display();
    
    //digitalWrite(motorInA, HIGH);
    //digitalWrite(motorInB, LOW);
    //digitalWrite(motorPWM, HIGH);
  
}
