const int lMotFwd=9;  // connection on pin 9 left motor forward
const int rMotFwd=10; //connection on pin 10 right motor forward
const int lMotRev=11; //connection on pin 11 left motor reverse
const int rMotRev=12;  //connection on pin 12 right motor reverse
const int onblack= 300;  // reading for black line from sensor is less than this
const int onWhite= 700; // reading for white line is greater than this

void setup() {

  Serial.begin(9600);
  
  // pinMode(A0,INPUT);  
  pinMode(A1,INPUT);  //extreme left sensor
  pinMode(A2,INPUT);  //left
  pinMode(A3,INPUT);  // middle sensor
  pinMode(A4,INPUT);   // right
  pinMode(A5,INPUT);  // extreme right sensor
    
  pinMode(lMotFwd,OUTPUT); 
  pinMode(rMotFwd,OUTPUT);
  pinMode(lMotRev,OUTPUT);  
  pinMode(rMotRev,OUTPUT); 

 

}


bool isOnBlack(int sensor){

if( sensor<=onblack)
return true;
else
return false;
}


bool isOnWhite(int sensor){
  if(sensor>=onWhite)
  return true;
  else
  return false;
}




void moveForward()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,HIGH);

  digitalWrite(rMotRev,LOW);
  digitalWrite(lMotRev,LOW);
  
}

void turnLeft()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,HIGH);

  
  digitalWrite(rMotRev,LOW);
  digitalWrite(lMotRev,LOW);
}


void turnRight()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,LOW);
  
  digitalWrite(rMotRev,LOW);
  digitalWrite(lMotRev,LOW);
}

void turnCircle()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotRev,LOW);
  digitalWrite(lMotRev,HIGH);
  digitalWrite(rMotFwd,HIGH);
}

void Stop()
{

digitalWrite(lMotFwd,LOW);
digitalWrite(rMotFwd,LOW);
digitalWrite(lMotRev,LOW);
digitalWrite(rMotRev,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
int sensor1=analogRead(A1);//sensor1  Extreme Left
int sensor2=analogRead(A2);//sensor2 
int sensor3=analogRead(A3);//sensor3  middle
int sensor4=analogRead(A4);//sensor4  
int sensor5=analogRead(A5);//sensor5   Extreme right
Serial.print("extreme Left: ");
Serial.print(sensor1);
Serial.print("\t lower left: ");
Serial.print(sensor2);
Serial.print("\t middle: ");
Serial.print(sensor3);
Serial.print("\t lowerRight: ");
Serial.print(sensor4);
Serial.print("\t Extreme Right: ");
Serial.println(sensor5);


if( isOnBlack(sensor1)){
  turnLeft();
}else{

  if(isOnBlack(sensor3)&&isOnWhite(sensor1)){
    moveForward();
  }else

  if( isOnWhite(sensor1)&& isOnWhite(sensor3)&& isOnBlack(sensor5)  ){
    turnRight();
  }else
  
  if(isOnBlack(sensor2)){
    turnLeft();
  }else
  if(isOnBlack(sensor4)){
    turnRight();
  }else
  if( isOnWhite(sensor1) && isOnWhite(sensor2) && isOnWhite(sensor3) && isOnWhite(sensor4) && isOnWhite(sensor5) ){
    turnCircle();   // replace with left if gap is present
  }


}


}
