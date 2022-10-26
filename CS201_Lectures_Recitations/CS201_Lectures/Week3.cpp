/*
#include <iostream>
using namespace std;
*/

//false is zero. If the statement inside the if function is equal to zero, it wll return the false case.
//boolean output yields 0 or 1 when put in in/out streams.
// || means or ; && means and.

/*
int main()
{
	float input_number;
	cout << "Please enter input number = ";
	cin >> input_number;
	if (input_number >= 100.0 || input_number <= 0.0) {
		cout << "The number you entered is out of range." << endl;
	}
	return 0;
}
*/

//same code using boolean algebra.

/*
int main()
{
	float input_number;
	bool first_case;
	bool second_case;

	cout << "Please enter input number = ";
	cin >> input_number;
	first_case = bool(input_number > 100.0);
	second_case = bool(input_number < 0.0);

	if (first_case + second_case == 1) {
		cout << "The number you entered is out of range." << endl;
	}
	else {
		cout << "Good Number";
	}
	return 0;
}
*/

// do not write cryptic code.
// when you write !12, compiler will assume a boolean operation and it should return TRUE.

/*
int main() {
	float note;
	cout << "Please enter your grade : ";
	cin >> note;
	if (note <= 50.0 && note >= 0.0) {
		cout << "Low" << endl;
	}
	else if (note <= 75.0 && note > 50.0) {
		cout << "Medium" << endl;
	}
	else if (note > 75.0 && note <= 100.0) {
		cout << "High" << endl;
	}
	else
		cout << "Invalid" << endl;
	return 0;
}
*/

//cut the circuit of if-else statement via avoiding using nested if's. Use "and" instead.
//dangling else: this is not python, indentations are only decorative.

/*
void Circle_Area(int rad) {
	cout << "Circle area of a " << rad << "-radius pizza is " << 3.14 * rad * rad << " centimeters." << endl;
}

int main() {
	float lol;
	cout << "Enter the radius of the pizza: ";
	cin >> lol;
	Circle_Area(lol);
	return 0;
}
*/

//case where an auxiliary function returns a float:
//as you can see, a LITERAL should be defined in order to print it.
//what we do with the function (writing things inside) is called passing a parameter.
//this is just like python.

/*
float Circle_Area(int rad) {
	cout << "Circle area of a " << rad << "-radius pizza is " << 3.14 * rad * rad << " centimeters." << endl;
	return 3.14 * rad * rad;
}

int main() {
	float lol;
	float lmao;
	cout << "Enter the radius of the pizza: ";
	cin >> lol;
	lmao = Circle_Area(lol);
	cout << lmao;
	return 0;
}
*/

//functional programming provides a way to modularize the program.