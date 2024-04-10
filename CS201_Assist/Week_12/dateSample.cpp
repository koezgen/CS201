#include <iostream>
#include <string>
#include "date.h"
using namespace std;

int main(){
	int m, d, y, diff;
	cout << "Please enter your birth date: ";
	cin >> d >> m >> y;
	Date bdate(m, d, y);
	Date tdate;
	diff = tdate-bdate;

	Date tt_days_before = bdate - 23;

	cout << "Your birth day is on " << bdate.DayName() << "." << endl;
	cout << "You lived " << diff*24*3600 << " seconds." << endl;

	return 0;
}
