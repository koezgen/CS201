#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Kanat Ozgen

bool checkWinner(string (&tictactoeBoard)[3][3], string sign)
{
	if ((tictactoeBoard[0][0] == sign) && (tictactoeBoard[0][1] == sign) && (tictactoeBoard[0][2] == sign))
	{
		return true;
	}
	else if ((tictactoeBoard[1][0] == sign) && (tictactoeBoard[1][1] == sign) && (tictactoeBoard[1][2] == sign))
	{
		return true;
	}
	else if ((tictactoeBoard[2][0] == sign) && (tictactoeBoard[2][1] == sign) && (tictactoeBoard[2][2] == sign))
	{
		return true;
	}
	else if ((tictactoeBoard[0][0] == sign) && (tictactoeBoard[1][1] == sign) && (tictactoeBoard[2][2] == sign))
	{
		return true;
	}
	else if ((tictactoeBoard[0][2] == sign) && (tictactoeBoard[1][1] == sign) && (tictactoeBoard[2][0] == sign))
	{
		return true;
	}
	else if ((tictactoeBoard[0][0] == sign) && (tictactoeBoard[1][0] == sign) && (tictactoeBoard[2][0] == sign))
	{
		return true;
	}
	else if ((tictactoeBoard[0][1] == sign) && (tictactoeBoard[1][1] == sign) && (tictactoeBoard[2][1] == sign))
	{
		return true;
	}
	else if ((tictactoeBoard[0][2] == sign) && (tictactoeBoard[1][2] == sign) && (tictactoeBoard[2][2] == sign))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkFormat(string move)
{
	if (move.length() == 3)
	{
		if (move.at(1) == '-')
		{
			if (isdigit(move.at(0)) && isdigit(move.at(2)))
			{
				if (0 < (stoi(move.substr(0, 1))) && (stoi(move.substr(0, 1)) <= 3) && (0 < (stoi(move.substr(2, 1)))) && (stoi(move.substr(2, 1)) <= 3))
				{
					return true;
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

void playerMove(string name, string sign, string (&tictactoeBoard)[3][3])
{
	// assigning a flag variable for a while loop.
	bool format_check_var = true;

	// take and validate the move
	string move;
	
	while (format_check_var)
	{
		cout << name << ", please enter your move: ";
		cin >> move;

		if (checkFormat(move))
		{
			if (tictactoeBoard[int(move.at(0) - 1 - '0')][int(move.at(2) - 1 - '0')] == " ")
			{
				tictactoeBoard[int(move.at(0) - 1 - '0')][int(move.at(2) - 1 - '0')] = sign;
				format_check_var = false;
			}
			else
			{
				cout << "That location is already full!" << endl;
			}
		}
		else
		{
			cout << "Please enter correct move format!" << endl;
		}
	}
}

void print(string tictactoeBoard[][3])
{
	cout << "Current board: " << endl;
	cout << " " << tictactoeBoard[0][0] << " | " << tictactoeBoard[0][1] << " | " << tictactoeBoard[0][2] << endl;
	cout << "-----------" << endl;
	cout << " " << tictactoeBoard[1][0] << " | " << tictactoeBoard[1][1] << " | " << tictactoeBoard[1][2] << endl;
	cout << "-----------" << endl;
	cout << " " << tictactoeBoard[2][0] << " | " << tictactoeBoard[2][1] << " | " << tictactoeBoard[2][2] << endl;
}

bool array_emptiness_checker(string (&tictactoeBoard)[3][3])
{
	int counter = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tictactoeBoard[i][j] == " ")
			{
				counter += 1;
			}
		}
	}

	if (counter == 0)
	{
		return false;
	}

	else
	{
		return true;
	}
}

void playGame(string &p1name, string &user_sign1, string &p2name, string &user_sign2, int &p1score, int &p2score, string (&tictactoeBoard)[3][3])
{
	cout << "Starting a new game..." << endl;

	while ((checkWinner(tictactoeBoard, user_sign1) == false) && (checkWinner(tictactoeBoard, user_sign2) == false) && (array_emptiness_checker(tictactoeBoard) == true))
	{
		print(tictactoeBoard);
		playerMove(p1name, user_sign1, tictactoeBoard);
		if ((checkWinner(tictactoeBoard, "X") == false) && (checkWinner(tictactoeBoard, "O") == false) && (array_emptiness_checker(tictactoeBoard) == true))
		{
			print(tictactoeBoard);
			playerMove(p2name, user_sign2, tictactoeBoard);
		}
	}
	
	if (checkWinner(tictactoeBoard, user_sign1))
	{
		cout << p1name << " is the winner!" << endl;
		if (user_sign1 == "X")
		{
			p1score += 1;
		}
		else
		{
			p2score += 1;
		}
	}
	
	if (checkWinner(tictactoeBoard, user_sign2))
	{
		cout << p2name << " is the winner!" << endl;
		if (user_sign2 == "O")
		{
			p2score += 1;
		}
		else
		{
			p1score += 1;
		}
	}

	if (array_emptiness_checker(tictactoeBoard) == false)
	{
		cout << "The game ended in a draw!" << endl;
	}

}

// { {" "," "," "}, {" "," "," "}, {" "," "," "}};
int main()
{
	// define the game vector
	string tictactoeBoard1[3][3] = { {" "," "," "}, {" "," "," "}, {" "," "," "} };
	string tictactoeBoard2[3][3] = { {" "," "," "}, {" "," "," "}, {" "," "," "} };

	// define the variables
	string p1name, p2name;
	string user_sign1 = "X";
	string user_sign2 = "O";
	int p1score = 0;
	int p2score = 0;

	cout << "Welcome to Tic-Tac-Toe!" << endl;
	
	cout << "Player 1, please enter your name: ";
	cin >> p1name;
	cout << "Hello, " << p1name << ". You are going to play with " << user_sign1 << endl;

	cout << "Player 2, please enter your name: ";
	cin >> p2name;
	cout << "Hello, " << p2name << ". You are going to play with " << user_sign2 << endl << endl;

	playGame(p1name, user_sign1, p2name, user_sign2, p1score, p2score, tictactoeBoard1);

	cout << "Current Scores: " << endl;
	cout << p1name << ": " << p1score << "   " << p2name << ": " << p2score << endl << endl;

	playGame(p2name, user_sign2, p1name, user_sign1, p1score, p2score, tictactoeBoard2);

	cout << "Current Scores: " << endl;
	cout << p1name << ": " << p1score << "   " << p2name << ": " << p2score << endl << endl;

	cout << "Final Scores: " << endl;
	cout << p1name << ": " << p1score << "   " << p2name << ": " << p2score << endl;

	if (p1score > p2score)
	{
		cout << p1name << " is the overall winner!" << endl;
	}
	else if (p1score < p2score)
	{
		cout << p2name << " is the overall winner!" << endl;
	}
	else if (p1score == p2score)
	{
		cout << "The overall game ended in a draw!" << endl;
	}

	return 0; 
}
