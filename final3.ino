const int LED3 = 6; 
const int LED1 = 2;    
const int LED2 = 7; 
const int LED0 = 9;

const int BUTTON3 = 4;
const int BUTTON1 = 5;//the input pin where the 
const int BUTTON2 = 3;//the input pin where the 

int val3 = 0;         
int old_val3 = 0;     
int state3 = 0;    


int val1 = 0;         //val will be used to store the state
                     //of the input pin
int old_val1 = 0;     //this variable stores the previous
                     //value of "val"
int state1 = 0;       //0 = LED off while 1 = LED on

int val2 = 0;         //val will be used to store the state
                     //of the input pin
int old_val2 = 0;     //this variable stores the previous
                     //value of "val"
int state2 = 0;       //0 = LED off while 1 = LED on


// Sensor Data

float sensorPin0 = A0;
float sensorValue0 = 0.0;

float sensorPin1 = A1;
float sensorValue1 = 1;

float sensorPin2 = A2;
float sensorValue2 = 0.0;

float sensorPin3 = A3;
float sensorValue3 = 0.0;

float sensorPin4 = A4;
float sensorValue4 = 0.0;

float sensorPin5 = A5;
float sensorValue5 = 0.0;

//shutter count
int shuttercount=0 ;
//shutter count


void setup() {
  // put your setup code here, to run once:
pinMode(LED3, OUTPUT); // sets the digital pin as output

pinMode(BUTTON3,INPUT);  //and the Button is an input


  // put your setup code here, to run once:
pinMode(LED1, OUTPUT); // sets the digital pin as output
pinMode(LED2, OUTPUT); // sets the digital pin as output
pinMode(BUTTON1,INPUT);  //and the Button is an input
pinMode(BUTTON2,INPUT);  //and the Button is an input


 // the signal pin (new addition)
pinMode(LED0, OUTPUT); // sets the digital pin as output
 
// Sensor Data
pinMode(sensorPin0, INPUT);

pinMode(sensorPin1, INPUT);

pinMode(sensorPin2, INPUT);

pinMode(sensorPin3, INPUT);

pinMode(sensorPin4, INPUT);

pinMode(sensorPin5, INPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

val3 = digitalRead(BUTTON3);//read input value and store it

if (val3 == HIGH){
  delay(10);
  digitalWrite(LED3, HIGH);  // turns the LED on

  // this is a new addition
  digitalWrite(LED0, HIGH);  // turns the LED on
  
//shutter count
shuttercount = shuttercount+1 ;
Serial.print("Shutter Count = ");
Serial.print(shuttercount);
Serial.print("  //////////////////////////////////");
Serial.println("   ");
//shutter count

// get the data0////////////////////////////
sensorValue0 = analogRead(sensorPin0);
float voltageA0 = sensorValue0*(5.0/1023.0);
Serial.print("voltageA0(V)");
Serial.println("   ");
Serial.println(voltageA0 , 6);
Serial.println("   ");
// get the data1
sensorValue1 = analogRead(sensorPin1);
float voltageA1 = sensorValue1*(5.0/1023.0);
Serial.print("voltageA1(V)");
Serial.println("   ");
Serial.println(voltageA1 , 6);
Serial.println("   ");
// get the data2
sensorValue2 = analogRead(sensorPin2);
float voltageA2 = sensorValue2*(5.0/1023.0);
Serial.print("voltageA2(V)");
Serial.println("   ");
Serial.println(voltageA2 , 6);
Serial.println("   ");
// get the data3
sensorValue3 = analogRead(sensorPin3);
float voltageA3 = sensorValue3*(5.0/1023.0);
Serial.print("voltageA3(V)");
Serial.println("   ");
Serial.println(voltageA3 , 6);
Serial.println("   ");
// get the data4
sensorValue4 = analogRead(sensorPin4);
float voltageA4 = sensorValue4*(5.0/1023.0);
Serial.print("voltageA4(V)");
Serial.println("   ");
Serial.println(voltageA4 , 6);
Serial.println("   ");
// get the data5
sensorValue5 = analogRead(sensorPin5);
float voltageA5 = sensorValue5*(5.0/1023.0);
Serial.print("voltageA5(V)");
Serial.println("   ");
Serial.println(voltageA5 , 6);
Serial.println("   ");
//Sensor Data//////////////////////////



  delay(400);
  digitalWrite(LED3, LOW);  // turns the LED off
  digitalWrite(LED0, LOW);  // turns the LED off

  delay(10);
}

  // put your main code here, to run repeatedly:

val1 = digitalRead(BUTTON1);//read input value and store it
val2 = digitalRead(BUTTON2);//read input value and store it

if ((val1 == HIGH)&&(old_val1==LOW)){
  delay(10);
}
if ((val1 == HIGH)&&(old_val1==LOW)){
  state1 = 1 - state1;
  delay(10);
}

if ((val2 == HIGH)&&(old_val2==LOW)){
  delay(10);
}
if ((val2 == HIGH)&&(old_val2==LOW)){
  state2 = 1 - state2;
  delay(10);
}

old_val1 = val1;          //val is now old, let's store it
old_val2 = val2;          //val is now old, let's store it

if (state1 == 1){
digitalWrite(LED1, HIGH); // turns the LED on

}else{          
digitalWrite(LED1, LOW);  // turns the LED off
}

if (state2 == 1){
digitalWrite(LED2, HIGH); // turns the LED on

}else{          
digitalWrite(LED2, LOW);  // turns the LED off
}


}
