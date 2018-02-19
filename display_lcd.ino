void display_lcd(float _angle, float _pf, float _voltage, float _current) {

  int an = (int)_angle;
  String Angle = String(an);
  String PF = String(_pf);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A:" + Angle);
  lcd.setCursor(7,0);
  lcd.print("PF:" + PF);

  if (angle == 0)
    lcd.print("");
  else if (angle < 0)
    lcd.print("ld");
  else  lcd.print("lg");

  lcd.setCursor(0, 1);
  lcd.print("V:" + String(_voltage));
  lcd.print(" I:" + String(_current));


}
