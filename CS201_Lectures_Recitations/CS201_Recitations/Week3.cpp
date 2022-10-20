// this is a recitation about precedence of operators.

// slaytlardan precedence larý ve operatörlerin hangi karakterlerle iliþkili olduklarýný ezberle.

// programlarýnýn baþýna <string> librarysi koymayý unutma vs2012 string librarysi istiyor bit operationlar için.

#include <iostream>
#include <string>
using namespace std;

// code that finds whether drawing a given triangle is possible.

/*
int main() {
	float side1;
	float side2;
	float side3;

	cout << "Please enter the lengths associated with the sides of the supposed triangle.";
	cin >> side1 >> side2 >> side3;
	if (((side1 + side2) > side3) && ((side2 + side3) > side1) && ((side3 + side1) > side2)) {
		cout << "Drawing this triangle is possible." << endl;
	}

	return 0;
}
*/

// code that finds the new wages of workers.

/*
int main() {
	float salary;

	cout << "Please enter your salary";
	cin >> salary;

	if ((salary <= 1000) && (salary > 0)) {
		salary = salary + (salary * 0.15);
	}
	else if ((salary <= 2000) && (salary > 1000)) {
		salary = salary + (salary * 0.10);
	}
	else if ((salary <= 3000) && (salary > 2000)) {
		salary = salary + (salary * 0.05);
	}
	else if (salary > 3000) {
		salary = salary + (salary * 0.025);
	}

	cout << "Your new salary is " << salary << "." << endl;
	return 0;

}
*/

// code that calculates the square inch price of a pizza.

/*
float cost;
float radius;

void prompt() {
	cout << "Please enter the cost and the radius of the pizza.";
	cin >> cost >> radius;
}

void calculations(float a, float b) {
	float si_price;
	si_price = cost / (radius * radius * 3.14);
	cout << si_price;
}

int main() {
	prompt();
	calculations(cost, radius);
	return 0;
}
*/

int main() {
	cout << "Hello";
	return 0;
}