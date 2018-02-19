void rms()
{
  int i = 0;
  int init;
  int count = 0;
  float sum = 0, temp;

  for (int s = 0; s < n; s++)
  {
    I[s] = analogRead(I_pin);
    V[s] = analogRead(V_pin);
    delayMicroseconds(5);
  }
//
//  for(int q =0; q<n;q++)
//  Serial.println(I[q]);
  
  while (1)
  {
    i++;
    if (I[i] == 0 && I[i + 1] > 0) {
      init = i;
      break;
    }
  }
  for (i = init+1; I[i] > 0; i++)
  {
    temp = 0.005610912 * I[i] - 0.062193121;
    sum += temp * temp;
    count++;
  }
    Serial.print("sum: ");
    Serial.println(sum);
    Serial.print("Count: ");
    Serial.println(count);
    current = sqrt(sum / count);


  i = 0;
  count = 0;
  sum = 0;


  while (true)
  {
    i++;
    if (V[i] == 0 && V[i + 1] > 0) {
      init = i;
      break;
    }
  }

  for (i = init+1; V[i] > 0; i++)
  {
    temp = 0.013527 * V[i] + 7.13664;
    sum += temp * temp;
    count++;
  }

  voltage = sqrt(sum / count);

}
