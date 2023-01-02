#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
/*
int main()
{
	int fib_array[10];

	fib_array[0] = 1;
	fib_array[1] = 1;

	for (int i = 2; i < 10; i++)
	{
		fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
	}
	
	for (int j = 0; j < 10; j++)
	{
		cout << fib_array[j] << " " << endl;
	}

	return 0;
}
*/

/*
void string_operation(string mystr, int myint)
{
	string last_string = mystr.substr(myint - 1, string::npos);
	string prev_string = mystr.substr(0, myint);

	string final_string = last_string + prev_string;

	cout << final_string;
}

void power(int n)
{
	int counter = 0;
	do
	{
		cout << pow(2, counter) << endl;
		counter++;
	} while (pow(2, counter) < n);

}

void tree()
{
	int width;
	cout << "Please enter the width of the tree";
	cin >> width;
	
	// for this tree, the width and the height will be equal

	for	(int i = 0; i < width; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "x";
		}

		cout << endl;
	}
}
*/
/*
void box(int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if ((i == 0) || (i == height - 1))
			{
				cout << "+";
			}
			else if ((j == 0) || (j == height - 1))
			{
				cout << "+";
			}
			else
			{
				cout << " ";
			}
		}

		cout << endl;
	}
}

void tree(int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((j > width/ 2 + i) || (j < width/ 2 - i))
			{
				cout << " ";
			}
			else
			{
				cout << "+";
			}
		}

		cout << endl;
	}
}

void phone_bill(int area_code, int duration)
{
	if ((area_code >= 200) && (area_code <= 299))
	{
		cout << 100 * duration;
	}

	else if ((area_code >= 300) && (area_code <= 499))
	{
		cout << 150 * duration;
	}

	else if ((area_code >= 500) && (area_code <= 599))
	{
		cout << 300 * duration;
	}
}

void month_year_after_x_months(int year, int month, int month_passed)
{
	int month_aggregate;
	month_aggregate = year * 12 + month + month_passed;

	int current_month;
	current_month = month_aggregate % 12;

	int current_year;
	current_year = month_aggregate / 12;

	cout << current_year << endl << current_month << endl;
}

int main()
{
	box(5);
	cout << endl;
	box(3);
	cout << endl;
	tree(3,5);
	cout << endl;
	tree(5,8);

	int month;
	cin >> month;

	int year;
	cin >> year;

	month_year_after_x_months(year, month, 100);

	int custom_month_passed;
	cin >> custom_month_passed;

	month_year_after_x_months(year, month, custom_month_passed);

	int area_code, duration;
	cin >> area_code >> duration;

	if ((area_code <= 200) || (area_code >= 500) || (duration < 0))
	{
		cout << "Invalid area code.";
	}
	else
	{
		phone_bill(area_code, duration);
	}

	return 0;
}
*/