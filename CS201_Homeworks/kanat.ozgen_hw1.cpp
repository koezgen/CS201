#include <iostream>
#include <string>
using namespace std;

//Kanat Ozgen

float hw_grade(float hw_avg, float weighted_exam_avr)
{
	if (hw_avg / weighted_exam_avr >= 3) {
		return 0;
	}
	else if ((hw_avg / weighted_exam_avr) < 3 && (hw_avg / weighted_exam_avr) > 2) {
		return hw_avg * (3 - (hw_avg / weighted_exam_avr));
	}
	else if (hw_avg / weighted_exam_avr <= 2) {
		return hw_avg;
	}
	return hw_avg;
}

float quiz_grade(float quiz1, float quiz2, float quiz3, float quiz4)
{
	float lowest_quiz;
	float sum_of_the_highest_quizzes;
	lowest_quiz = quiz1;

	if (quiz2 < lowest_quiz)
	{
		lowest_quiz = quiz2;
		if (quiz3 < lowest_quiz)
		{
			lowest_quiz = quiz3;
			if (quiz4 < lowest_quiz)
			{
				lowest_quiz = quiz4;
			}
			else
			{
				lowest_quiz = quiz3;
			}
		}
		else if (lowest_quiz > quiz4)
		{
			lowest_quiz = quiz4;
		}
	}
	else if (quiz3 < lowest_quiz)
	{
		lowest_quiz = quiz3;
		if (quiz4 < lowest_quiz)
		{
			lowest_quiz = quiz4;
		}
	}
	else if (quiz4 < lowest_quiz)
	{
		lowest_quiz = quiz4;
	}
	else lowest_quiz = quiz1;


	sum_of_the_highest_quizzes = quiz1 + quiz2 + quiz3 + quiz4 - lowest_quiz;

	return (sum_of_the_highest_quizzes / 30) * 100;
}


int main()
{
	string name;
	float midterm;
	float final;
	
	float weighted_exam_avr;

	cout << "The purpose of this program is to calculate your CS201 grade. What is your name? ";
	cin >> name;
	cout << "Hello " << name << ", what are your midterm and final exam grades? ";
	cin >> midterm >> final;

	weighted_exam_avr = ((midterm * 0.30) + (final * 0.35)) / 0.65;

	if (weighted_exam_avr < 30)
	{
		cout << name << ", your weighted exam average is less than 30, you will fail the course!" << endl;
	}

	else
	{
		float hw1, hw2, hw3, hw4, hw5;
		float quiz1, quiz2, quiz3, quiz4;
		float hw_avg;
		float course_numeric_grade;

		cout << "What are the grades of your 5 homework? ";
		cin >> hw1 >> hw2 >> hw3 >> hw4 >> hw5;

		hw_avg = (hw1 + hw2 + hw3 + hw4 + hw5) / 5;
		if (hw_avg / weighted_exam_avr >= 3) {
			cout << "You'll get NONE of the points earned from homework!" << endl;
		}
		else if ((hw_avg / weighted_exam_avr) < 3 && (hw_avg / weighted_exam_avr) > 2) {
			cout << "You'll get " << hw_avg * (3 - (hw_avg / weighted_exam_avr)) << " from the points earned from homework!" << endl;
		}
		else if (hw_avg / weighted_exam_avr <= 2) {
			cout << "You'll get all the points earned from homework!" << endl;
		}
		cout << "What are the grades of your 4 quizzes? If any, enter your grade as 0 for missed quizzes. ";
		cin >> quiz1 >> quiz2 >> quiz3 >> quiz4;

		
		course_numeric_grade = (quiz_grade(quiz1, quiz2, quiz3, quiz4) * 0.10) + (hw_grade(hw_avg, weighted_exam_avr) * 0.25) + (midterm * 0.30) + (final * 0.35);

		cout << name << ", your grade for CS201 is: " << course_numeric_grade << endl;
	}

	return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> f6b465f9c90f7f5bcfc004eb7da180855bf735b0
