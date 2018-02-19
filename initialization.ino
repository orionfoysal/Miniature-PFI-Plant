void initialization()
{
  Serial.begin(9600);
  analogReference(EXTERNAL);
  lcd.begin(16, 2);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
  pinMode(relay_1,OUTPUT);
  pinMode(relay_2,OUTPUT);
  pinMode(relay_3,OUTPUT);
  pinMode(relay_4,OUTPUT);

  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, HIGH);
  digitalWrite(relay_3, HIGH);
  digitalWrite(relay_4, HIGH);
  
  pinMode(lcd_pwm, OUTPUT);
  analogWrite(lcd_pwm, 30);
}

