/*
This program inputs a 

E.g. Input: "35;256;5", output: "The sum of 35, 256, 5 is". 

*/

#include <iostream>
#include <string>
#include "strutils.h"

using namespace std;


int main()
{
	string line, number;
	int index, length;
    int num, sum = 0;

	cout << "Enter string of numbers: ";
	cin >> line;

    cout << "The sum of ";

	length = line.length();

    // search for ; sign
	index = line.find(";");

    // while there is a ; in input line
	while (index != string::npos)
	{   
        // set a as first operand
		number = line.substr(0, index);

        // convert number to integer
		num = atoi(number);

        // add number to sum
        sum = sum + num;

        // display number
        cout << num << ", ";

        // first move the string line after the found ;
        line = line.substr(index+1, length);
        // search for ; sign
        index = line.find(";");
	}

    // convert remaining number to integer, add to sum and display
	num = atoi(line);
    sum = sum + num;
    cout << num << " is " << sum << endl;

	return 0;
}