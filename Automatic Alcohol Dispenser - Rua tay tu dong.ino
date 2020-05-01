#define inPin 12
#define LedStand 13
#define LedPump 11
#define Buzzer 10
#define OutPump 9

#define TimeToBegin 500
#define TimeToPump 300

int val1, val2=-1;
char buf[10];
int count = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println("HELLO");
  
  pinMode(inPin, INPUT);
  pinMode(LedPump, OUTPUT);
  pinMode(LedStand, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(OutPump, OUTPUT);
  

  digitalWrite(Buzzer, LOW);
  digitalWrite(LedPump, LOW);
  digitalWrite(LedStand, HIGH);
  digitalWrite(OutPump, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  val1 = digitalRead(inPin);
  if(val1!=val2)
  {
    val2 = val1;
    sprintf(buf, "Value = %d", val2);
    Serial.println(buf);
    count = 0;
    //if(val2 == 1) count = 0;
  }

  if(val2 == 0)
    count++;

  

  if(count >= TimeToBegin/10 && count < (TimeToPump+TimeToBegin)/10)
  {
    digitalWrite(LedPump, HIGH);
    digitalWrite(LedStand, LOW);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(OutPump, LOW); //Pump out
    //Serial.println(count);
  }
  if(count >= (TimeToPump+TimeToBegin)/10 || val2 == 1)
  {
    digitalWrite(LedPump, LOW);
    digitalWrite(LedStand, HIGH);
    digitalWrite(Buzzer, LOW);
    digitalWrite(OutPump, HIGH); //Pump off
    Serial.println(count);
    //count = 0;
    //val2 = -1;
  }

  delay(10);
}
