//Ashok Kumar Kumawat (14/05/2016)
//Voice Controll Car (Bluetooth + Android)
//credit to : Angelo Casimiro

String voice;
int motor1Pin1 = 8;  // pin 2 on L293D IC   // pin A1 of L298 IC module
int motor1Pin2 = 9;  // pin 7 on L293D IC   // pin A2 of L298 IC module
int enable1Pin = 10;  // pin 1 on L293D IC   // pin EN-A of L298 IC module
int enable2Pin = 11;  // pin 9 on L293D IC   // pin EN-B of L298 IC module
int motor2Pin1 = 12;  // pin 10 on L293D IC  // pin B1 of L298 IC module
int motor2Pin2 = 13;  // pin 15 on L293D IC  // pin B2 of L298 IC module
int state;
int value=0;        //makes sure that the serial only prints once the state
//--------------------------Call A Function-------------------------------//  
void Forward()
  {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(value == 0)
        {
          Serial.println("Go Forward!");
          value=1;
        }
       
    }
    void Left()
   {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(value == 0)
        {
          Serial.println("Turn LEFT");
          value=1;
        }
       
    }
    void Stop()
    {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(value == 0)
        {
          Serial.println("STOP!");
          value=1;
        }
    }
    
    void Right()
    {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(value == 0)
        {
          Serial.println("Turn RIGHT");
          value=1;
        }
        
    }
    
    void Backward() 
    {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(value == 0)
        {
          Serial.println("Reverse!");
          value=1;
        }
        
    }
//-----------------------------------------------------------------------//  
void setup() {
   // sets the pins as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    //------sets enable1Pin and enable2Pin high so that motor can turn on:-----//
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
    //----initialize serial communication at 9600 bits per second:---//
    Serial.begin(9600);
}
//-----------------------------------------------------------------------//  

void loop() 
{
  while (Serial.available()){        //Check if there is an available byte to read
  delay(10);                         //Delay added to make thing stable 
  char c = Serial.read();            //Conduct a serial read
  if (c == '#') {break;}             //Exit the loop when the # is detected after the word
  voice += c;                        //Shorthand for voice = voice + c   
  }  
  if (voice.length() > 0) 
  {
    Serial.println(voice); 
//-----------------------------------------------------------------------//    
  //-----------------Control Multiple Pins---------------------//  
 if(voice == "*go") {Forward();}             //Call Function Forward
  else if(voice == "*stop"){Stop();}          //Call Function Stop
   else if(voice == "*right"){Right();}      //Call Function Right
    else if(voice == "*left"){Left();}       //Call Function Left
     else if(voice == "*back"){Backward();}  //Call Function Backward
     
  
  //----------Turn On One-By-One----------// 
  
//-----------------------------------------------------------------------//  
    voice="";
   }
} //Reset the variable after initiating
