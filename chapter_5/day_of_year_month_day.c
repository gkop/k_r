#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int year = 2012;
    int month = 8;
    int day = 9;
    int yearday = day_of_year(year, month, day);
    printf("%i/%i/%i is day #%i\n", month, day, year, yearday);
    yearday++;
    month_day(year, yearday, &month, &day);
    printf("day #%i of %i is %i/%i\n", yearday, year, month, day);
    return 0;
}

static char daytab[][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += *(*(daytab+leap)+i);
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > *(*(daytab+leap)+i); i++)
        yearday -= *(*(daytab+leap)+i);
    *pmonth = i;
    *pday = yearday;
}
