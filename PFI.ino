#include <LiquidCrystal.h>
#include <math.h>

const int n = 250;
const int iteration = 12;
int V[n], I[n];
float prev_pf = 1;
float phase, angle, f, pf, T, current, voltage;
int j, k, count, vol_0, cur_0, flagV1, flagI1, temp1, temp2, mode;
int I_pin = A4, V_pin = A5, relay_1 = 4, relay_2 = 5, relay_3 = 6, relay_4 = 7, lcd_pwm = 10;

LiquidCrystal lcd(12, 11, 53, 52, 51, 50);

void setup()
{
  initialization();
//  calc_pf();
//  display_lcd(angle, pf);
}

void loop()
{
  calc_pf();
  rms();
  display_lcd(angle,pf,voltage,current);

  if (pf > 0 && abs(prev_pf - pf) > 0.04 ) {
    prev_pf = pf;
    for (int i = 0; i < 16 ; i++)
    {
      calc_mode(i);
      calc_pf();
      rms();
      display_lcd(angle,pf,voltage,current);

      
      if (abs(pf) > prev_pf)
      {
        mode = i;
        prev_pf = pf;
      }

      delay(500);
    }

    calc_mode(mode);
  }
}

