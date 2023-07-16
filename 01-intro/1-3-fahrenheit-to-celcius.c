#include <stdio.h>

#define LOWER_F 0
#define UPPER_F 300

int main() {
  float f_temp = LOWER_F;

  printf("Fahrenheit To Celcius\n");
  printf("====================\n");

  while (f_temp < UPPER_F) {
    float c_temp = 5.0 * (f_temp - 32) / 9.0;
    printf("%-6.0f %6.2f\n", f_temp, c_temp);

    f_temp += 20;
  }

  return 0;
}