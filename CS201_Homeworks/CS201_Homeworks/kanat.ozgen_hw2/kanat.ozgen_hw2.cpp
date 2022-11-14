#include <string>
#include <iostream>
#include "strutils.h"
using namespace std;

//Kanat Ozgen

bool check_input_format(const string & expression)
{
	bool flag;
	string lhs_trial;
	string rhs_trial;
	string result_trial;

	flag = true;

	if (expression.find("=") != string::npos)
	{
		if ((expression.find(".") == string::npos))
		{
			if ((expression.substr(0, expression.find("=") - 1).find("-") != string::npos) || (expression.substr(0, expression.find("=") - 1).find("+") != string::npos))
			{
				if (expression.substr(1).find("+") != string::npos)
				{
					lhs_trial = expression.substr(0, expression.substr(1).find("+") + 1);
					rhs_trial = expression.substr(expression.substr(1).find("+") + 2, expression.find("=")-expression.substr(1).find("+") - 2);
					result_trial = expression.substr(expression.find("=") + 1);

					if ((lhs_trial.at(0) == '+') || (lhs_trial.at(0) == '-'))
					{
						lhs_trial = lhs_trial.substr(1);
					}

					if ((rhs_trial.at(0) == '+') || (rhs_trial.at(0) == '-'))
					{
						rhs_trial = rhs_trial.substr(1);
					}

					if ((result_trial.at(0) == '+') || (result_trial.at(0) == '-'))
					{
						result_trial = result_trial.substr(1);
					}

					if ((rhs_trial.length() == 0) || (lhs_trial.length() == 0) || (lhs_trial.length() == 0))
					{
						return false;
					}
					else {
					for (int i = 0; i <= rhs_trial.length() - 1; i++)
					{
						if (isdigit(rhs_trial.at(i)) == false)
						{
							flag = false;
						}
					}

					for (int i = 0; i <= lhs_trial.length() - 1; i++)
					{
						if (isdigit(lhs_trial.at(i)) == false)
						{
							flag = false;
						}
					}

					for (int i = 0; i <= result_trial.length() - 1; i++)
					{
						if (isdigit(result_trial.at(i)) == false)
						{
							flag = false;
						}
					}

					return flag;
					}
				}
				else if (expression.substr(1).find("-") != string::npos)
				{
					lhs_trial = expression.substr(0, expression.substr(1).find("-") + 1);
					rhs_trial = expression.substr(expression.substr(1).find("-") + 2, expression.find("=")-expression.substr(1).find("-") - 2);
					result_trial = expression.substr(expression.find("=") + 1);

					if ((lhs_trial.at(0) == '+') || (lhs_trial.at(0) == '-'))
					{
						lhs_trial = lhs_trial.substr(1);
					}

					if ((rhs_trial.at(0) == '+') || (rhs_trial.at(0) == '-'))
					{
						rhs_trial = rhs_trial.substr(1);
					}

					if ((result_trial.at(0) == '+') || (result_trial.at(0) == '-'))
					{
						result_trial = result_trial.substr(1);
					}

					if ((rhs_trial.length() == 0) || (lhs_trial.length() == 0) || (lhs_trial.length() == 0))
					{
						return false;
					}
					else {
					for (int i = 0; i <= rhs_trial.length() - 1; i++)
					{
						if (isdigit(rhs_trial.at(i)) == false)
						{
							flag = false;
						}
					}

					for (int i = 0; i <= lhs_trial.length() - 1; i++)
					{
						if (isdigit(lhs_trial.at(i)) == false)
						{
							flag = false;
						}
					}

					for (int i = 0; i <= result_trial.length() - 1; i++)
					{
						if (isdigit(result_trial.at(i)) == false)
						{
							flag = false;
						}
					}

					return flag;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void question_parser(const string & expression, int & rhs, int & lhs, string & operation, int & result)
{
	// decide what the operation is
	if ((expression.substr(1).find("+") != string::npos))
	{
		operation = "+";
		rhs = atoi(expression.substr(expression.substr(1).find("+") + 2, expression.find("=")-expression.substr(1).find("+") - 2));
		lhs = atoi(expression.substr(0, expression.substr(1).find("+") + 1));
		result = atoi(expression.substr(expression.find("=") + 1));
	}
	if (expression.substr(1).find("-") != string::npos)
	{
		operation = "-";
		rhs = atoi(expression.substr(expression.substr(1).find("-") + 2, expression.find("=") - expression.substr(1).find("-") - 2));  
		lhs = atoi(expression.substr(0, expression.substr(1).find("-") + 1));
		result = atoi(expression.substr(expression.find("=") + 1));
	}
	
	// parse the input into individual memory parts.
	// these memory parts will be then called by the operation_result function.
}

int operation_result(int & lhs, int & rhs, string & operation)
{
	if (operation == "+")
	{
		return (lhs + rhs);
	}
	if (operation == "-")
	{
		return (lhs - rhs);
	}

	// function won't enter here, this is my school number:
	return 30973;
}

void worker_function(int & points, int & joker, int & counter)
{
	int rhs;
	int lhs;
	string operation;
	int result;

	string expression;
	cout << "Please enter question #" <<  counter << " and its answer: ";
	cin >> expression;
	StripWhite(expression);
	if (check_input_format(expression))
	{
		question_parser(expression, rhs, lhs, operation, result);
		if (operation_result(lhs, rhs, operation) == result)
		{
			points += 25;
			cout << "Correct answer! You got 25 points for this math expression." << endl << endl;
		}
		else if (joker > 0)
		{
			string joker_request;
			cout << "Wrong!" << endl;
			cout << "Would you like to use your joker option to correct the answer? ";
			cin >> joker_request;
			ToLower(joker_request);

			if (joker > 0)
			{
				if (joker_request == "yes")
				{   
					joker -= 1;
					cout << "Please enter the expression again: ";
					cin >> expression;
					if (check_input_format(expression))
					{
						question_parser(expression, rhs, lhs, operation, result);
						if (operation_result(lhs, rhs, operation) == result)
						{
							points += 25;
							cout << "Correct answer! You got 25 points for this joker option." << endl << endl;
						}
						else
						{
							points -= 10;
							cout << "Sorry! The answer should have been: " << operation_result(lhs, rhs, operation) << ". You got -10 penalty points for this joker option." << endl << endl;
						}
					}
					else
					{
						points -= 10;
						cout << "Wrong input format! You got -10 penalty points for this joker option." << endl << endl;
					}

				}
				else if (joker_request == "no")
				{
					cout << "Sorry! The answer should have been: "<< operation_result(lhs, rhs, operation) << ". You got 0 points for this math expression." << endl << endl;
				}
			}
			else
			{
				cout << "Sorry! The answer should have been: "<< operation_result(lhs, rhs, operation) << ". You got 0 points for this math expression." << endl << endl;
			}
		}
		else
		{
			cout << "Sorry! The answer should have been: "<< operation_result(lhs, rhs, operation) << ". You got 0 points for this math expression." << endl << endl;
		}
	}
	else
	{
		points -= 10;
		cout << "Wrong input format! You got -10 penalty points for this math expression." << endl << endl;
	}
}

int main()
{
	int points = 0;
	int joker = 1;
	int counter = 1;

	worker_function(points, joker, counter);
	
	counter += 1;

	worker_function(points, joker, counter);
	
	counter += 1;

	worker_function(points, joker, counter);
	
	counter += 1;
	
	worker_function(points, joker, counter);

	if (points < 0)
	{
		points = 0;
	}

	cout << "End of the program. You got " << points << " points in total." << endl;
	return 0;
}

/*
int rhs_supposed;
	int lhs_supposed;
	int result_supposed;

	// check if there's a properly placed equal sign.
	if (expression.find("=") != -1)
	{
		if (expression.find("=") == expression.rfind("="))
		{
			// check if the + sign is correct.
			if (expression.find("+") != -1)
			{
				if (expression.rfind("+") == expression.find("+"))
				{
					rhs_supposed = ((expression.substr(expression.find("+"), (expression.find("=")-expression.find("+"))));
					lhs_supposed = (expression.substr(0, expression.find("+")));
					result_supposed = (expression.substr(expression.find("=")));
					if ((rhs_supposed != "") || (lhs_supposed != "") || (result_supposed != ""))
					{
						return true;
					}
				}
				else if (expression.find("-") != -1)
				{
					int first_minus = expression.find("-");
					int second_minus = expression.find("-", first_minus +1);
					int third_minus = expression.find("-", second_minus +1);

					if (second_minus != string::npos)
					{
						string rhs_supposed = (expression.substr(expression.find("-"), (expression.find("=")-expression.find("-"))));
						string lhs_supposed = (expression.substr(0, expression.find("+")));
						string result_supposed = (expression.substr(expression.find("=")));
						if ((rhs_supposed != "") || (lhs_supposed != "") || (result_supposed != ""))
						{
							return true;
						}
					}

					else if (third_minus != string::npos)
					{
						string rhs_supposed = (expression.substr(expression.find("-"), (expression.find("=")-expression.find("-"))));
						string lhs_supposed = (expression.substr(0, expression.find("+")));
						string result_supposed = (expression.substr(expression.find("=")));
						if ((rhs_supposed != "") || (lhs_supposed != "") || (result_supposed != ""))
						{
							return true;
						}
					}
				}
			}
			else if (third_minus)
		}
	}
	// check for the operation.
	// use the function library.
*/

/*
	int rhs2;
	int lhs2;
	string operation2;
	int result2;

	string expression2;
	cout << "Please enter question #2 and its answer: ";
	cin >> expression2;
	if (check_input_format(expression2))
		{
			
		}
	else
		{
			points -= 10;
			cout << "Wrong input format! You got -10 penalty points for this math expression." << endl;
		}
*/
