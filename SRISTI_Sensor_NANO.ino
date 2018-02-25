int count=0;
int count2=0;
const int BuzzerPin1 =  12;
const int BuzzerPin2 = 8;
void setup()
{
  pinMode(BuzzerPin1, OUTPUT);
  pinMode(BuzzerPin2, OUTPUT);
  Serial.begin(9600);  
}
void loop()
{
  int sensorValue_MQ135 = analogRead(A0);
  Serial.print("Air Quality from MQ135= ");
  Serial.print(sensorValue_MQ135);
  Serial.print("\n");
  Serial.println();  
  delay(1000);
  //algorithm
  if (sensorValue_MQ135 > 840) {
    count++ ;                                     //counter function value increases to 1,2,3,4 and 5;
      }
  else if (count!=0){
    count = 0;                                   //counter function value nullifies to 0 if consequitive term is not = 0; 
  }
  if (count == 3){                              //buzzer will only activate if consequitive 5 values for MQ7 sensor comes above 500;
    digitalWrite(BuzzerPin1, HIGH);
    digitalWrite(BuzzerPin2, LOW);
    delay(1000);
    digitalWrite(BuzzerPin1, LOW);
    digitalWrite(BuzzerPin2, LOW);
    count = 0;                                  // counter function returns to original value;
  }
}
