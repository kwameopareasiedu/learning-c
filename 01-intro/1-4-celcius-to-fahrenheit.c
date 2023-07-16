#include <stdio.h>

#define LOWER_C 0
#define UPPER_C 300

int main() {
  float c_temp = LOWER_C;

  printf("Celcius To Fahrenheit\n");
  printf("=====================\n");

  while (c_temp < UPPER_C) {
    float f_temp = (9.0f / 5.0f * c_temp);
    printf("%-6.0f %6.2f\n", c_temp, f_temp);

    c_temp += 20;
  }

  return 0;
}