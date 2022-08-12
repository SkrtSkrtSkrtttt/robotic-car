#include <IRremote.hpp>
// By Naafiul (Group 1) 

#include <IRremote.h>  

int RECV_PIN =2;    

       


IRrecv irrecv(RECV_PIN);    //Setting up the IR receiver

decode_results results;

unsigned long receiverVal;  

void setup(){    

 Serial.begin(9600);    

 


 pinMode(RECV_PIN, OUTPUT);  //Setting up all the pins

irrecv.enableIRIn();  

 pinMode(3, OUTPUT);

 pinMode(5, OUTPUT);

 pinMode(10, OUTPUT);

 pinMode(9, OUTPUT);




 

}    

void loop(){    

   if (irrecv.decode(&results)){    

         receiverVal = results.value;    

         Serial.println(receiverVal, HEX);      

         switch(receiverVal){    

         case 0xFF30CF: //Keypad button "1"    

        //forward

          digitalWrite(3, 1);

          digitalWrite(5, 0);

          digitalWrite(10, 1);

          digitalWrite(9, 0);

     

          break;

         

     

         case 0xFF18E7: //Keypad button "2"    

         //stop  

          digitalWrite(3, 0);

          digitalWrite(5, 0);

          digitalWrite(9, 0);

          digitalWrite(10, 0);

           
          break;

   

   

         case 0xFF7A85: //Keypad button "3"    

          //backwards  

        digitalWrite(3, 0);

        digitalWrite(5, 1);

        digitalWrite(9, 0);

        digitalWrite(10, 1);

         
          break;

         

         case 0xFF10EF: //Keypad button "4"    

         // turn left

         digitalWrite(3, 1); // BL

         digitalWrite(5, 0);

         digitalWrite(9, 0);

         digitalWrite(10, 0);

       

          break;

     

         

          case 0xFF38C7: //keypad 5

          //turn right

         digitalWrite(3, 0);

         digitalWrite(5, 0);

         digitalWrite(9, 1); // BR

         digitalWrite(10, 0);

         

          break;

         }

       irrecv.resume();      

   }    
