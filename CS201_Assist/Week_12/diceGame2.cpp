/*
Write a C++ program that simulates a version of the craps game, 
which is a dice game where the players make wagers on the outcome 
of the roll or a series of rolls. 

Here are the rules for this version: The player rolls two dice, each with 6 sides. 
After the dice have come to rest, the sum of the spots on the two upward faces is calculated. 
If the sum is 7 or 11 on the first throw, then the player wins. 
If the sum is 2, 3, or 12 on the first throw, then the player loses. 
For any other possible sum value on the first throw, your program should prompt 
for a wager and the user should continue throwing until the outcome of the thrown 
dice accumulates to the wager. If so, the player wins; otherwise, 
i.e. if the summed outcomes becomes greater than the wager, then the player loses.
*/

#include <iostream>
#include "prompt.h"
#include "dice.h"
using namespace std;

int main(){
	
	Dice d1(6), d2(6);
	int outcome = d1.Roll() + d2.Roll();

	if (outcome == 7 || outcome == 11){
		cout << "The outcome is " << outcome << ". You won the game!" << endl;
	}
	else if (outcome == 2 || outcome == 3 || outcome == 12){
		cout << "The outcome is " << outcome << ". You lost the game!" << endl;
	}
	else{
		cout << "The outcome is " << outcome << ". Let's hear your wager!" << endl;
		int wager = PromptlnRange("Please enter your wager", 2, 12);
		int sum = 0;
		while (sum < wager){
			outcome = d1.Roll() + d2.Roll();
			sum += outcome;
			cout << "The outcome is " << outcome << ", and the sum is now " << sum << "." << endl;
		}
		if (sum == wager){
			cout << "You won the game!" << endl;
		}
		else{
			cout << "You lost the game!" << endl;
		}
	}

	return 0;
}