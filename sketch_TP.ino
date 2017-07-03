#include <Stepper.h>



//TMP36 Pin Variables
int pinTemperatura = 1; 

 //read analoog value//the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
//float sensorFuego;
//int buttonpin = 3; // define the flame sensor interface
//int val ;// define numeric variables val
//int analoog = A0; // define the flame sensor interface

//Led Ventana abierta
int R = 2;

#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9



 #define STEPS 200 
Stepper stepper(STEPS, IN4,IN3,IN2,IN1);
 int previous = 0;

void setup()
{
  Serial.begin(9600);   
  stepper.setSpeed(60);

//  pinMode(R, OUTPUT);
//  digitalWrite(R, LOW);
 // myservo.attach(9); 
}
 
void loop()              
{

   int val = analogRead(0);
   Serial.println(val);
   int calculo = val - previous;

  Serial.println(calculo);
  stepper.step(calculo);
  previous = val;
//  stepper.step(2000); 
//  delay(1000); 
//  stepper.step(-200); 
//  delay(1000); 
//  

//   int val = analogRead(0);
//   Serial.println(val);
//   int calculo = val - previous;
//
//  Serial.println(calculo);
//  stepper.step(calculo);
//  previous = val;
//  delay(10); 
//   

    
//   digitalWrite(R, HIGH); // on (for 5 Second)
//   delay(5000); 
//   digitalWrite(R, LOW);
//   delay(5000);



  //int reading = analogRead(pinTemperatura);  
// sensorFuego = analogRead(analoog);
// val = digitalRead(buttonpin);
//
//if (val == HIGH) 
//  {
//    digitalWrite(buzzer, HIGH);
//    Serial.println(val);
//  }
//  else
//  {
//     digitalWrite(buzzer, LOW);
//     Serial.println(val);
//  }
// 
//     Serial.println("Fin de lectura");
//  delay(1000);          

            
}





          /*C*/
float convertToTemperature(int reading){
   float voltage = reading * 5.0;
   voltage /= 1024.0; 
    float temperatureC = (voltage - 0.5) * 100 ;
     Serial.print(temperatureC); Serial.println(" degrees C");
}


