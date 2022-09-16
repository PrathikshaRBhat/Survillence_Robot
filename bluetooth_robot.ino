char BT_input;

int enA = 5;
int in1 = 2;
int in2 = 3;
// Motor B connections
int enB = 7;
int in3 = 4;
int in4 = 6;

int obleft = 11;
int ob_val_left;

int obright = 12;
int ob_val_right;

int obcenter = 13;
int ob_val_center;


int mail_pin_left= 14;
int mail_pin_right= 15;
int mail_pin_center= 8;

void setup() {
  Serial2.begin(9600);  
  Serial.begin(9600);
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT); 

  pinMode(mail_pin_left, OUTPUT);
  pinMode(mail_pin_right, OUTPUT);
  pinMode(mail_pin_center, OUTPUT); 

  pinMode(obleft, INPUT);
  pinMode(obright, INPUT);
  pinMode(obcenter, INPUT);
 
  analogWrite(enA, 230);
  analogWrite(enB, 230);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {

ob_val_left = digitalRead(obleft);
delay(10);
ob_val_right = digitalRead(obright);
delay(10);
ob_val_center = digitalRead(obcenter);
delay(10);
Serial.println(ob_val_left);
  Serial.println(ob_val_right);
  Serial.println(ob_val_center);

if(!ob_val_left || !ob_val_right || !ob_val_center)
{
  if (!ob_val_left)
  {
digitalWrite(mail_pin_left, HIGH);  
  }
  else if(!ob_val_right)
  {
    digitalWrite(mail_pin_right, HIGH);      
  }
  else if(!ob_val_center)
  {
    digitalWrite(mail_pin_center, HIGH);      
  }

digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(2000);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  delay(2000);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}
else
{
digitalWrite(mail_pin_left, LOW);
digitalWrite(mail_pin_right, LOW);
digitalWrite(mail_pin_center, LOW);  
}
  
if (Serial2.available())
  {
   BT_input=Serial2.read();
   Serial.println(BT_input);
    if (BT_input=='s')
    {
      digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
      Serial.println("Motors are Off");
    }
    else if (BT_input=='b')
    {
       digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
      Serial.println("Backward");
    }
    else if (BT_input=='f')
    {
      digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
      Serial.println("Forward");
    }
   else if (BT_input=='r')
    {
      analogWrite(enA, 200);
  analogWrite(enB, 200);
      digitalWrite(in1, 0); 
      digitalWrite(in2, 0); 
      digitalWrite(in3, 0); 
      digitalWrite(in4, 1); 
      Serial.println("right");

      delay(1500); // to increase the right turn
analogWrite(enA, 200);
  analogWrite(enB, 120);
      digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
    }
    else if (BT_input=='l')
    {
      analogWrite(enA, 200);
  analogWrite(enB, 200);
      digitalWrite(in1, 0); 
      digitalWrite(in2, 1); 
      digitalWrite(in3, 0); 
      digitalWrite(in4, 0); 
      Serial.println("left");

      delay(2000); // to increase the left turn
      
    analogWrite(enA, 200);
  analogWrite(enB, 200);
  
      digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
    }
  }
}
