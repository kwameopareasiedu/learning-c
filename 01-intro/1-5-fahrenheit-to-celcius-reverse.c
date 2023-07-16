#include <stdio.h>

#define LOWER_F 0
#define UPPER_F 300
#define TEMP_STEP 20

int main() {
  printf("Fahrenheit to Celcius - Reversed\n");
  printf("================================\n");

  float f_temp = UPPER_F;

  while (f_temp >= LOWER_F) {
    float c_temp = 5.0 * (f_temp - 32) / 9.0;
    printf("%-6.0f %6.2f\n", f_temp, c_temp);

    f_temp -= TEMP_STEP;
  }

  return 0;
}