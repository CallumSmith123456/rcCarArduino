 int Lena = 5;
int Lin1 = 4;
int Lin2 = 12;
int Lin3 = 9;
int Lin4 = 13;
int Lenb = 6;
int Rena = 11;
int Rin1 = 8;
int Rin2 = 7;
int Rin3 = 2;
int Rin4 = 3;
int Renb = 10;


String stringSerialData; 
String stringDir;
String stringPwm;
int dir;
int pwm;
int halfPwm;
int x = 5;

void setup() {
  pinMode(Lena, OUTPUT);
  pinMode(Lin1, OUTPUT); 
  pinMode(Lin2, OUTPUT); 
  pinMode(Lin3, OUTPUT); 
  pinMode(Lin4, OUTPUT); 
  pinMode(Lenb, OUTPUT);
  pinMode(Rena, OUTPUT);
  pinMode(Rin1, OUTPUT); 
  pinMode(Rin2, OUTPUT); 
  pinMode(Rin3, OUTPUT); 
  pinMode(Rin4, OUTPUT); 
  pinMode(Renb, OUTPUT);

  Serial.begin(9600); 
  Serial.setTimeout(10);
}

void loop() {
  if (Serial.available () > 0) {
    stringSerialData = Serial.readString();
  }
  stringPwm = stringSerialData.substring(2); 
  stringDir = stringSerialData.substring(0, 1); 

//  Serial.println(stringDir);
//  Serial.println(stringPwm);

  dir = stringDir.toInt(); 
  pwm = stringPwm.toInt(); 

  halfPwm = pwm / 2;
  Serial.println(dir);
  Serial.println(pwm);

if (stringSerialData == '0') {
  turnOffAllPins();
}

   if (dir == 1) {
    driveMotor(1, 0, pwm);
    driveMotor(2, 0, pwm);
    driveMotor(3, 0, pwm);
    driveMotor(4, 0, pwm);
  }
  
  if (dir == 2) {
    driveMotor(1, 0, pwm);
    driveMotor(2, 0, pwm);
    driveMotor(3, 0, halfPwm);
    driveMotor(4, 0, halfPwm);
  }
  
  if (dir == 3) {
    driveMotor(1, 0, pwm);
    driveMotor(2, 0, pwm);
    driveMotor(3, 1, pwm);
    driveMotor(4, 1, pwm);
  }
  
  if (dir == 4) {
    driveMotor(1, 1, pwm);
    driveMotor(2, 1, pwm);
    driveMotor(3, 1, halfPwm);
    driveMotor(4, 1, halfPwm);
  }
  
  if (dir == 5) {
    driveMotor(1, 1, pwm);
    driveMotor(2, 1, pwm);
    driveMotor(3, 1, pwm);
    driveMotor(4, 1, pwm);
        
  }
  
  if (dir == 6) {
   driveMotor(1, 1, halfPwm);
   driveMotor(2, 1, halfPwm);
   driveMotor(3, 1, pwm);
   driveMotor(4, 1, pwm); 
  }
  
  if (dir == 7) {
    driveMotor(1, 1, pwm);
    driveMotor(2, 1, pwm);
    driveMotor(3, 0, pwm);
    driveMotor(4, 0, pwm);
  }
  
  if (dir == 8) {
    driveMotor(1, 0, halfPwm);
    driveMotor(2, 0, halfPwm);
    driveMotor(3, 0, pwm);
    driveMotor(4, 0, pwm);
  }
}


//change motor function
void driveMotor(int motor, int dir, int pwm) {
  if (motor == 1 && dir == 0) {
    digitalWrite(Lin1, HIGH);
    digitalWrite(Lin2, LOW); 
    analogWrite(Lena, pwm); 
  }

  else if (motor == 2 && dir == 0) {
   digitalWrite(Lin3, HIGH); 
   digitalWrite(Lin4, LOW);
   analogWrite(Lenb, pwm); 
  }

  if (motor == 3 && dir == 0) {
    digitalWrite(Rin2, HIGH); 
    digitalWrite(Rin1, LOW); 
    analogWrite(Rena, pwm); 
  }

  else if (motor == 4 && dir == 0) {
    digitalWrite(Rin4, HIGH);
    digitalWrite(Rin3, LOW); 
    analogWrite(Renb, pwm); 
  }

  else if (motor == 1 && dir == 1) {
    digitalWrite(Lin1, LOW);
    digitalWrite(Lin2, HIGH); 
    analogWrite(Lena, pwm);  
  }

  else if (motor == 2 && dir == 1) {
    digitalWrite(Lin3, LOW); 
    digitalWrite(Lin4, HIGH); 
    analogWrite(Lenb, pwm); 
  }

  else if (motor == 3 && dir == 1) {
    digitalWrite(Rin1, HIGH);
    digitalWrite(Rin2, LOW); 
    analogWrite(Rena, pwm); 
  }

  else if (motor == 4 && dir == 1) {
    digitalWrite(Rin3, HIGH);
    digitalWrite(Rin4, LOW); 
    analogWrite(Renb, pwm); 
  }

  if (motor == 1 && dir == 2) {
    digitalWrite(Lin1, LOW);
    digitalWrite(Lin2, LOW); 
    analogWrite(Lena, pwm); 
  }

  else if (motor == 2 && dir == 2) {
   digitalWrite(Lin3, LOW); 
   digitalWrite(Lin4, LOW);
   analogWrite(Lenb, pwm); 
  }

  else if (motor == 3 && dir == 2) {
    digitalWrite(Rin2, LOW); 
    digitalWrite(Rin1, LOW); 
    analogWrite(Rena, pwm); 
  }

  else if (motor == 4 && dir == 2) {
    digitalWrite(Rin4, LOW);
    digitalWrite(Rin3, LOW); 
    analogWrite(Renb, pwm); 
  }  
}

void turnOffAllPins() {
  digitalWrite(Lin1, LOW);
  digitalWrite(Lin2, LOW);
  digitalWrite(Lin3, LOW);
  digitalWrite(Lin4, LOW); 
  digitalWrite(Rin1, LOW);
  digitalWrite(Rin2, LOW);
  digitalWrite(Rin3, LOW);
  digitalWrite(Rin4, LOW); 

  analogWrite(Lena, 0);
  analogWrite(Lenb, 0);
  analogWrite(Rena, 0);
  analogWrite(Renb, 0);
}
