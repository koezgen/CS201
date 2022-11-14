#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


// there's something called a sentinel value where a loop will break when the parameter reaches that value.

/*
int main()
{
	int num;
	int sum;
	int numterms;

	while (num != -1)
	{
		numterms++;
		sum += num;
		cin >> num;
	}
	return 0;
}
*/

// in the while setting, you won't know where you are going to get out of the loop. For loop is more suitable
// cases where you deal with a finite set of elements.

/*
int main()
{
	for (int i = 0; i > 0; i++)
	{
		string name;
		cin >> name;
		cout >> name;
	}
}
*/

// check out the sumnums.cpp file that was uploaded to sucourse for more information regarding loops.

// you can use loops to reverse strings and conduct string operations.

/*
void VerticalOutput(const string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		cout << str.at(i) << endl;
	}
}

string ReverseString(const string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		cout << str.at(str.length() - i - 1);
	}
}

bool isPalyndrome(const string &str)
{
	string reverse;
	reverse = "a" * (str.lengt

	for (int i = 0; i < str.length(); i++)
	{
		reverse[i] = str.at(str.length() - 1);
	}

	if (reverse == str)
	{
		cout << "The string provided is a palyndrome!";
		return true;
	}
	else
	{
		cout << "The string provided is NOT a palyndrome!";
		return false;
	}
}

int main()
{
	VerticalOutput("string");
	ReverseString("kanat");
	isPalyndrome("racecar");
	return 0;
}
*/

// 