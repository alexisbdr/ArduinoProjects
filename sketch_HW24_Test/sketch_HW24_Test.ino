void setup() {
  // put your setup code here, to run once:
DDRB = 0b011110; //Set digit pins 9-12 as outputs   
DDRD = 0b11111111; //Set segment pins 0-7 as outputs
}

void loop() {
  // put your main code here, to run repeatedly:
PORTB = 0b000000;
PORTD = 0b11111111; 
}








