#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

void positive_or_negative(int i);
int largest_number(int a, int b, int c);

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/
void print_remaining_days(int month, int day, int year);

/**
* convert_day - converts day of month to day of year, without accounting
* for leap year
* @month: month in number format
* @day: day of month
* Return: day of year
*/
int convert_day(int month, int day);


#endif /* MAIN_H */
