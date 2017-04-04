int number;
int digit;
int timer;
int digbit[5];
int numbit[11];
int segment[4];
int PB1;
int PB2;
int first_time; 
int number_left;
int number_right; 
int pass;
int new_number_right;
int new_number_left;



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
number_right = 0;
number_left=random(100);
}

void loop() {
  //Setting up left part of diplay 
  light_number_right(number_right);
 // number_left = random(100);
  light_number_left(number_left);



      PB1 = digitalRead(16);
      PB2 = digitalRead(17);
while (digitalRead(16) | digitalRead(17)){
      light_number_right(number_right);
      light_number_left(number_left);
      if (PB1){
        pass=1;
        new_number_right = number_right-1;
        if (number_right<0){ 
            number_right=99; 
        }
            delay(.1);
      }

      if (PB2){
        pass = 1;
        new_number_right = number_right+1;
        delay(.1);  
      }    
}
number_right = new_number_right;
light_number_right(number_right);

      if (number_right==number_left & pass!=1){
          pass = 1;
          digitalWrite(14,HIGH); digitalWrite(15,HIGH);
          delay(500);
          digitalWrite(14,LOW); digitalWrite(15,LOW);
          number_left = random(100);
        }
       
pass = 0;   
}

void light_number_right(int number){
    segment[0] = ((number)%10);     //Stores ones
    segment[1] = ((number/10)%10);  //Stores tens
    
 //first_time = millis();
 //while (millis()-first_time <= timer)  {
                   
     
         lightup(3,segment[1]);
         delay(.1);
         lightup(0,10);
      
      
        lightup(4,segment[0]);   
        delay(.1);
        lightup(0,10);
}

void light_number_left(int number){
  segment[0] = ((number)%10);     //Stores ones
  segment[1] = ((number/10)%10);  //Stores tens
  
// first_time = millis();
// while (millis()-first_time <= timer)  {
               
         lightup(1,segment[1]);
         delay(.1);
         lightup(0,10);
  
        
        lightup(2,segment[0]);
        delay(.1);
        lightup(0,10);

         
}

void lightup(int digit, int segment){ 
  //Start by turning on the corresponding digit to a HIGH
  PORTB = digbit[digit];
  PORTD = numbit[segment];
return; 
}
