/* Find the number of smileys in a given string */

#include <iostream>
#include <string>

using namespace std;

int findSmileys(string inputString)
{
	unsigned int smileys = 0, index = 0, length;
	string searchPattern = ":)";

	length = inputString.length();
	while (index < length)
	{
		index = inputString.find(searchPattern, index);

		if (index != string::npos)
		{
			index += searchPattern.length();
			smileys++;
		}
	}
	
	return smileys;
}
//rfind with two parameters:
//the search only includes characters between the beginning of the string and position entered,
//ignoring any possible occurrences after it.

int rfindSmileys(string inputString)
{
	unsigned int smileys = 0, index;

	string searchPattern=":)";

	index = inputString.length() - 1;
	
	while (index > 0 && index != string::npos)
	{
		index = inputString.rfind(searchPattern, index);

		if (index == 0)
		{
			smileys++;
		}
		else if (index > 0 && index != string::npos)
		{
			index -= searchPattern.length();
			smileys++;
		}
	}
	
	return smileys;
}


int main()
{
	string inputStr;

	cout <<"Enter the input string: ";
	cin >> inputStr;
	cout << "Number of smileys in the given string \"" << inputStr << "\" is: " << findSmileys(inputStr) << endl;
	
//  cout << "Number of smileys in the given string \"" << inputStr << "\" is: " << rfindSmileys(inputStr) << endl;

    return 0;
}