//digital inputs for buttons
int B1 = 13;
int B2 = 12;
int rSet = 4;
//digital inputs for light string control
int LS1 = 7;
int LS2 = 8;

//button state variable
//tells if button has been pushed
int B1State = 0;
int B2State = 0;
int rsetState = 0;

void setup(){
 //allows for the Arduino to get set up
 Serial.begin(9600);
//assigns value of pins and tells what to output
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
//assigns value of pins and tells what to output
  pinMode(LS1, OUTPUT);
  pinMode(LS2, OUTPUT);
}

void loop(){
  //sets the button state to whatever value the Arduino reads (0 or 1)
  B1State = digitalRead(B1);
  B2State = digitalRead(B2);
  
  //Arduino will constantly run this function in the loop
  reset();
  
  if(B1State == HIGH){
     digitalWrite(LS1, HIGH);
  }
  else if(B2State == HIGH){
     digitalWrite(LS2, HIGH);
  } 
}

/*
This function, called above, checks to see if the reset button has been pushed.
If so, it turns both LED strings off (LOW), allowing for a new string to be lit up.
*/
void reset(){
 rsetState = digitalRead(rSet);
  
 if(rsetState == HIGH){
    digitalWrite(LS1, LOW);
    digitalWrite(LS2, LOW);
 } 
}
