int digit; 
int segment[4]; 
int sequence;
int numbit[11]; 
int digbit[5]; 
int number;
int Ta ;
int Tb; 
int time_diff;
int first_time;
int PB1;
int PB2;
int pass;

void setup() {
  // put your setup code here, to run once:
DDRB = B011110; //Set digit pins 9-12 as outputs   
DDRD = B11111111; //Set segment pins 0-7 as outputs
digbit[0] = B111111;
digbit[1] = B101111; //Pin 12-->Digit 1
digbit[2] = B110111; //Pin 11-->Digit 2 
digbit[3] = B111011; //Pin 10-->Digit 3
digbit[4] = B111101; //Pin 9-->Digit 4 
numbit[0] = B00111111;  
numbit[1] = B00000110;
numbit[2] = B01011011;
numbit[3] = B01001111;
numbit[4] = B01100110;
numbit[5] = B01101101;
numbit[6] = B01111101;
numbit[7] = B00000111;
numbit[8] = B01111111;
numbit[9] = B01100111;
numbit[10]= B00000000;
pinMode(14,OUTPUT);
pinMode(15,OUTPUT);
pinMode(16,INPUT);
pinMode(17,INPUT);
}

void loop() {
digitalWrite(14, HIGH);
digitalWrite(15, HIGH);
delay(200);
digitalWrite(14, LOW);
digitalWrite(15, LOW);
delay(random(1000,3000)); 
light_number(8888,500);
Ta = 0 ; 
Tb = 0 ; 
pass = 0;
first_time = millis();
while (millis()-first_time<=500 ){
  PB1 = digitalRead(16);
  PB2 = digitalRead(17);
  
  if ((PB1) & (pass!=1)) { 
    Ta = millis(); 
    pass = 1;       
    }
  if ((PB2) & (pass!=2)){
    Tb = millis();
    pass = 2;
    }
  
if ((Ta!=0) & (Tb!=0)){
  time_diff = abs(Ta-Tb);
 if (Ta<Tb){
    digitalWrite(14,HIGH);
    light_number(time_diff,1000);
    digitalWrite(14,LOW);
  }
  if (Ta>Tb){
    digitalWrite(15,HIGH);
    light_number(time_diff,1000);
    digitalWrite(15,LOW); 
  } 
  if (time_diff<=5){    
     digitalWrite( 14,HIGH);
     digitalWrite(15,HIGH);
     light_number(0000,1000);
     digitalWrite(14,LOW);
     digitalWrite(14,LOW);
  }

}}}

void light_number(int number, int timer){
  segment[0] = ((number)%10);     //Stores ones
  segment[1] = ((number/10)%10);  //Stores tens
  segment[2] = ((number/100)%10); //Stores hundreds
  segment[3] = (number/1000);     //Stores thousands
  
 first_time = millis();
 while (millis()-first_time <= timer)  {
      if (segment[3]>0) {                
         lightup(1,segment[3]);
         delay(.1);
         lightup(0,10);
  
      }
      if ((segment[3]>0) | (segment[2]>0)) {     
        lightup(2,segment[2]);
        delay(.1);
        lightup(0,10);
      }
      if ((segment[3]>0) | (segment[2]>0) | (segment[1]>0)){  
         lightup(3,segment[1]);
         delay(.1);
         lightup(0,10);
      }
      
      lightup(4,segment[0]);   
      delay(.1);
      lightup(0,10);
}}


void lightup(int digit, int segment){ 
  //Start by turning on the corresponding digit to a HIGH
  PORTB = digbit[digit];
  PORTD = numbit[segment];
return; 
}
