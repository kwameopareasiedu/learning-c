#include <stdio.h>

int is_leap_year(int year);

int day_of_year(int year, int month, int day);

void month_day(int year, int year_day, int *month, int *day);

int get_suffix_index(int day);

static char days_in_month[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // Non-leap year month days
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // Leap year month days
};

static char *months_in_year[] = {
    "", "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December",
};

static int dates[5][3] = {
    {1993, 05, 05},
    {2002, 10, 06},
    {2011, 01, 24},
    {2011, 07, 13},
    {2012, 10, 28},
};

static char *suffixes[] = {"st", "nd", "rd", "th"};

int main() {
  printf("Perform date conversions\n");
  printf("========================\n");
  int year_days[5];

  printf("Convert date to day of year\n");


  for (int i = 0; i < 5; i++) {
    int *date_parts = dates[i];
    int year = *date_parts;
    int month = *(date_parts + 1);
    int day = *(date_parts + 2);
    int year_day = day_of_year(year, month, day);
    char *suffix = suffixes[get_suffix_index(year_day)];

    printf("%d-%02d-%02d is the %d%s day of the year\n", year, month, day, year_day, suffix);
    year_days[i] = year_day;
  }

  printf("\nConvert day of year to month and day\n");
  for (int i = 0; i < 5; i++) {
    int *date_parts = dates[i];
    int year = *date_parts;
    int year_day = year_days[i];

    int month_in_year, day_in_month;
    month_day(year, year_day, &month_in_year, &day_in_month);
    char *day_in_month_suffix = suffixes[get_suffix_index(day_in_month)];
    char *month_in_year_name = months_in_year[month_in_year];

    printf("Day %d of %d is %d%s %s %d\n", year_day, year, day_in_month, day_in_month_suffix, month_in_year_name, year);
  }

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

int get_suffix_index(int day) {
  if (day == 1 || day == 21 || day == 31) {
    return 0;
  } else if (day == 2 || day == 22) {
    return 1;
  } else if (day == 3 || day == 23) {
    return 2;
  } else {
    return 3;
  }
}