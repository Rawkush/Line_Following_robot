int lMotFwd=12; 
int rMotFwd=6;
int lMotRev=13;
int rMotRev=7; 

int onblack= 100;  // reading for black line from sensor is less than this
int onWhite= 700; // reading for white line is greater than this

void setup() {

  // pinMode(A0,INPUT); 
  pinMode(A1,INPUT);  //extreme left sensor
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);  // middle sensor
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);  // extreme right sensor
    
  pinMode(lMotFwd,OUTPUT); 
  pinMode(rMotFwd,OUTPUT);
  pinMode(lMotRev,OUTPUT);  
  pinMode(rMotRev,OUTPUT); 

 

}

void moveForward()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,HIGH);
}

void turnLeft()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,HIGH);
}


void turnRight()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,LOW);
}

void turnCircle()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,LOW);
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

int sensor1=analogRead(A1);//sensor1
int sensor2=analogRead(A2);//sensor2
int sensor3=analogRead(A3);//sensor3
int sensor4=analogRead(A4);//sensor4
int sensor5=analogRead(A5);//sensor5

 
if((sensor5<onblack)&&(sensor2<onblack||sensor3<onblack||sensor4<onblack))
{

  turnLeft();
}else
if((sensor1>onWhite && sensor5>onWhite)&&(sensor2<onblack||sensor3<onblack||sensor4<onblack))
{moveForward();
}else
if((sensor5<onblack))
  {
    turnLeft();
   
  }else
if(sensor1<onblack)
  {
    turnRight();
  }
else
if( sensor1>onWhite && sensor5>onWhite && sensor2<onWhite && sensor2<onWhite && sensor4<onWhite)
{
 moveForward();
 delay(15);

 turnCircle();  
 delay(40);


}

}
