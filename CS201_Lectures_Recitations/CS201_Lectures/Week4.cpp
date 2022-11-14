/*
#include <iostream>
#include <string>
using namespace std;
*/

// do not use global variables as it destroys modularity.

/*
bool is_leap_or_not(int year) {

	bool Flag = false;
	if (year % 4 == 0) {
		Flag = true;
		if (year % 100 == 0) {
			Flag = false;
			if (year % 400 == 0) {
				Flag = true;
			}
		}

 	}
	return Flag;
}

int main() 
{
	int year;
	bool leap_year;
	cin >> year;
	leap_year = is_leap_or_not(year);
	cout << leap_year;
	return 0;
}
*/

// use function prototypes so that compiler knows about the functions that will be used later. 
// see order.cpp for more relevance.

/*
#include <iostream>
#include <string>
using namespace std;
void test();
bool test();
*/

// a pointer-like method to record to another memory with the use of a function. use "&" to do it.

/*
void take_names(string & name, string & surname) 
{
	cin >> name >> surname;
}

int main() 
{
	string name;
	string surname;
	take_names(name, surname);
	cout << name << surname << endl;
	return 0;
}
*/



