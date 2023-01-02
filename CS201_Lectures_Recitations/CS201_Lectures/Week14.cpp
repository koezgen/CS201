//recursion

#include <iostream>
#include <string>
using namespace std;


// fonksiyonun archetype ini çýkaracaksýn. gerisi çorap söküðü gibi gelir

void printreverse(string & s, int l)
{
	cout << s[l];
	for (int i = 0; i < s.length(); i++)
	{
		printreverse(s, l - 1);
	}
}

/*
void fibo(int length)
{
	int initial = 1;
	cout << 	

}
*/

double expo(int number, int power)
{

	return number * expo(number, power - 1);
}

int main()
{
	/*
	string sample;
	cin >> sample;
	printreverse(sample, sample.length());
	return 0;
	*/

	cout << expo(2, 3);

	return 0;
}