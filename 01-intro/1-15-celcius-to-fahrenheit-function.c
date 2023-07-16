#include <stdio.h>

#define LOWER_C 0
#define UPPER_C 300

float convert(float);

int main() {
  printf("Celcius To Fahrenheit With Functions\n");
  printf("====================================\n");

  float c_temp = LOWER_C;

  while (c_temp < UPPER_C) {
    printf("%-6.0f %6.2f\n", c_temp, convert(c_temp));
    c_temp += 20;
  }

  return 0;
}

float convert(float c_temp) {
  return (9.0f / 5.0f * c_temp);
}