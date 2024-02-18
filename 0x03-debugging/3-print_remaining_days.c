#include <stdio.h>
#include "main.h"


/**
 * is_leap_year - Checks if a year is a leap year.
 * @year: The year to check.
 * Return: 1 if true otherwise false.
 */
char is_leap_year(int year)
{
	return ((year % 100 != 0 && year % 4 == 0) ||
			(year % 100 == 0 && year % 400 == 0));
}

/**
 * convert_day_back - converts day of year to day of month, without accounting
 * for leap year
 * @month: month in number format
 * @day: day of year
 * Return: day of year
 */
int convert_day_back(int month, int day)
{
	switch (month)
	{
		case 2:
			day -= 31;
			break;
		case 3:
			day -= 59;
			break;
		case 4:
			day -= 90;
			break;
		case 5:
			day -= 120;
			break;
		case 6:
			day -= 151;
			break;
		case 7:
			day -= 181;
			break;
		case 8:
			day -= 212;
			break;
		case 9:
			day -= 243;
			break;
		case 10:
			day -= 273;
			break;
		case 11:
			day -= 304;
			break;
		case 12:
			day -= 334;
			break;
		default:
			break;
	}
	return (day);
}

/**
 * print_remaining_days - takes a date and prints how many days are
 * left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of month
 * @year: year
 * Return: void
 */
void print_remaining_days(int month, int day, int year)
{
	int days_in_year, is_leap;

	is_leap = is_leap_year(year);

	if (month == 2 && convert_day_back(month, day) >= 29 && !is_leap)
	{
		printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
		return;
	}

	day += is_leap && month > 2 ? 1 : 0;
	days_in_year = is_leap ? 366 : 365;
	printf("Day of the year: %d\n", day);
	printf("Remaining days: %d\n", days_in_year - day);
}
