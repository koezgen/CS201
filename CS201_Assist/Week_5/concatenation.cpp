#include <iostream>
#include <string>

using namespace std;

//We have six inputs, they are concatenated in reverse order to form 
//an output string sepetated by comas
//Input: "One" "Two" "Three"
//Output: "Three, Two, One"

/*
int main()
{
	int numRuns = 6;
	string input, output = "";
	int counter = 0;

	while(counter < numRuns - 1)
	{
		cout << "Please enter a word to be concatenated: ";
		cin >> input;
		output = ", " + input + output;
		counter ++;
	}
	
	//handle the last input here (don't add ",")
	cout << "Please enter a word to be concatenated: ";
	cin >> input;
	output = input + output;
	cout << output;
	
	cout << endl << "Final output is: " << output << endl;

	return 0;
}
*/