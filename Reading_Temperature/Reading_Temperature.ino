/*
 * Tutorial 1: Reading Temperature
 * 
 * Read the temperature in celcius over serial.
 *
 *
 * To see this sketch in action open up the serial
 * monitor. Clamp your fingers over the LM35
 * sensor. The temperature will rise and then fall
 * as you remove your fingers.
 *
 * The circuit:
 * - LM35 to 5v, GND, and Vo to analog 0
 *
 */

// the output pin of the LM35 temperature sensor
const int lm35Pin = A0;

void setup()
{
    // set up serial at 9600 baud   
    Serial.begin(9600);
}

void loop()
{ 
    int analogValue;
    float temperature;
    float voltage_v0;
    float temperature_f;
    float ADC;
    
    // read our temperature sensor; analogRead outputs a 10-bit value from the Arduino ADC (analog to digital converter)
    // ADC reads anything from ground to 5V, converts to digital, 10-bit number is proportional 
    ADC = analogRead(lm35Pin);

    // 10bit analog value (next few lines converts it to celcius)
    
    // input of 5V
    float VCC = 5.0;
    
    // this is scaled so voltage_v0 is between 0 and 5 (voltage on A0 pin)
    // voltage_v0 is the voltage on A0
    voltage_v0 = (float(ADC) / 1023.0) * VCC;    
    
    // temp goes up .01V per 1 deg. celcius
    float dC = voltage_v0 / .01;  
    
    // us-farenheit
    temperature_f = dC * (9.0/5.0) + 32.0;

    // print the temperature over serial
    Serial.print("Temp: ");
    Serial.print(temperature_f);
    Serial.println("F");
    
    // wait 1s before reading the temperature again
    delay(1000);
}

