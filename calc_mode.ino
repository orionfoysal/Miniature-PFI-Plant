void calc_mode(int _i){

  digitalWrite(relay_1,_i%2);
  digitalWrite(relay_2,_i/2%2);
  digitalWrite(relay_3,_i/4%2);
  digitalWrite(relay_4,_i/8%2);  

  delay(500);
}
