#include <stdio.h>

void month_day(int, int, int*, int*);

int main()
{
    int expected_m = 2;
    int expected_d = 29;

    int year = 1988;
    int yearday = 60;

    int m, d;

    month_day(year, yearday, &m, &d);
    printf("should be: m=%d, d=%d. got m=%d, d=%d\n", expected_m, expected_d, m, d);
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap(int);

/* day of year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    if (year < 0)	/* invalid year */
	return -1;

    int i, leap;
    leap = is_leap(year);
    if ((month < 1) || (month > 12) || (day < 1) || (day > daytab[leap][month]))
	return -1;	/* invalid month, day combination */

    for (i = 1; i < month; i++)
	day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = is_leap(year);
    if (year < 0 || yearday < 1 || (yearday > 365) || (leap && yearday > 366))
        *pmonth = *pday = -1;	    

    for (i = 1; yearday > daytab[leap][i]; i++)
	yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

/* is_leap: returns 1 if year is a leap year, 0 otherwise */
int is_leap(int year)
{
    return year%4 == 0 && year%100 != 0 || year%400 == 0;
}
