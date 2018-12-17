
#include <stdio.h>
#include <math.h>

float compute_angle(int hour, int min) {
   float ha = (float)(hour + min / 60.0f) * 360 / 12.0f; // position of hours hand
   float ma = (float)min * 360 / 60.0f; // position of minutes hand
   float a = fabs(ha - ma);
   if(a > 180)
       a = 360 - a;
   return a; // return the angle difference
}

int main() {

    int hour = 10, min = 10;
    printf("angle: %3.f\n", compute_angle(hour, min));
    return 1;
}


