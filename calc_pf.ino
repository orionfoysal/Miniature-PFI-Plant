void calc_pf(){
  float temp_angle = 0;
  float temp_pf = 0;
  
  for(int p=0; p<iteration; p++){

    for (int i = 0; i < n; i++)
    {
      I[i] = analogRead(I_pin);
      V[i] = analogRead(V_pin);
      delayMicroseconds(5);
    }

  /*----------------------------------------------
    Only for debugging purpose
  */

    // for (i = 0; i < n; i++)
    // {
    //   Serial.print(V[i]);
    //   Serial.print("\t");
    //   Serial.println(I[i]);
    // }
  //---------------------------------------------

   int i = 0;
    while (1)
    {
      if ( V[i] == 0 && V[i + 1] > 0)
      {
        T = 0;
        break;
      }
      i++;
    }
    vol_0 = i;
    cur_0 = i;

    for (j = i + 1; ; j++)
    {
      T++;
      if (V[j] > 0 && V[j + 1] == 0)
        flagV1 = j;
      if ( I[j] > 0 && I[j + 1] == 0)
        flagI1 = j;
      temp1 = flagI1 - flagV1;
      if (I[j] == 0 && I[j + 1] > 0){
        cur_0 = j;
      }
      if (V[j] == 0 && V[j + 1] > 0)
        break;
    }

    temp2= cur_0-vol_0;
    if (temp2>T/2) temp2= temp2-T;

    phase = (temp1+ temp2)/2;

    angle = phase * (360.0 / T);

    if (angle > 90)
      angle = angle - 360;

    pf = cosine(angle);

    temp_pf+=pf;
    temp_angle+=angle;

  /*------------------------------------------------------------
    For debugging purpose only
  */

    // Serial.println(T);
    // Serial.println(cur_0);
    // Serial.println(vol_0);
    // Serial.println(temp1);
    //  Serial.println(flagI1);
    // Serial.println(flagV1);
    // Serial.println(temp2);
    // Serial.println(angle);
    // Serial.println(phase);
    // Serial.println(pf);

  //----------------------------------------------------------

  }

  pf = temp_pf/iteration;
  angle = temp_angle/iteration;

}

float cosine ( float n) /* takes the angle in degrees and returns the cosine of the angle*/
{
  n = n * 3.1416 / 180;
  int i;
  float temp, sum = 1;
  temp = 1;
  for (i = 2; i < 1000; i += 2)
  {
    temp = temp * (((-1) * (n * n)) / (i * (i - 1)));
    sum += temp;
  }
  return sum;
}
