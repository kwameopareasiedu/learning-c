#include <stdio.h>

int is_leap_year(int year);

int day_of_year(int year, int month, int day);

void month_day(int year, int day_of_year, int *month, int *day);

static char days_in_month[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // Non-leap year month days
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // Leap year month days
};

int main() {
  printf("Perform date conversions\n");
  printf("========================\n");
  return 0;
}

int is_leap_year(int year) {
  return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int day_of_year(int year, int month, int day) {
  int i, leap = is_leap_year(year);

  for (i = 1; i < month; i++) {
    day += days_in_month[leap][i];
  }

  return day;
}

void month_day(int year, int year_day, int *month, int *day) {
  int i, leap = is_leap_year(year);

  for (i = 1; year_day > days_in_month[leap][i]; i++) {
    year_day -= days_in_month[leap][i];
  }

  *month = i;
  *day = year_day;
}