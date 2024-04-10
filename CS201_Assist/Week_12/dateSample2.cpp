/*
 * This program inputs a year and prints the name of the months that have their
 * last day on Sundays in that year.
 */
#include <iostream>
#include <string>
#include "date.h"
using namespace std;

int main(){
	int year;
	string day;

	cout << "Enter a year: ";
	cin >> year;
	
	Date d(1, 1, year);
	cout << endl << "Month(s) that end on Sundays in year " << year << ":" << endl;

	for (int i=1; i <= 12; i++){
		d = d + d.DaysIn() - 1;		// set d as the last day of i-th month
		day = d.DayName();			// get name of the day
		if (day == "Sunday")		// if name is Sunday then display name of the month
			cout << d.MonthName() << endl;
		d++;						// increase d so month becomes next month	
	}
	cout << endl;

	return 0;
}
