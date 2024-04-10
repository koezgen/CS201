/*
 * This program takes two strings (words) as inputs and checks whether second word starts
 * with the last letter of first word.
 */

#include <iostream>
#include <string>

using namespace std;

// check if last letter of first word is same as first letter of second word
bool check(string word1, string word2)
{	
	bool result = false;
	int lenWord1 = word1.length();

	if (word1.substr(lenWord1-1,1) == word2.substr(0,1))
	{
		result = true;
	}

	return result;
}

/*
int main()
{
	string word1;
	string word2;

	cout << "Enter first word: ";
	cin >> word1;

	cout << "Enter second word: ";
	cin >> word2;

	if ( !check(word1, word2) ) // if (check(word1, word2) == false)
	{
		cout << "Second word does not with the last letter of first word" << endl;
	}
	else
	{
		cout << "Second word starts with the last letter of first word" << endl;
	}

	return 0;
}
*/