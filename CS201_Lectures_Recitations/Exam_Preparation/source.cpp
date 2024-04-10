#include "date.h"
#include "randgen.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

////struct City
////{
////	string name;
////	unsigned long int population;
////};
//
//string stringmanip1(string mystr, int myint)
//{
//	string new_string;
//	
//	if (myint > mystr.length())
//	{
//		return mystr;
//	}
//
//	else
//	{
//		new_string = mystr.substr((mystr.length() - myint), myint) + mystr.substr(0, mystr.length() - myint);
//
//		return new_string;
//	}
//	 
//}
//
//// this works on terminal
//void posnum()
//{
//	int counter = 0;
//	int temp_num = 0;
//	string dummy;
//
//	while (cin >> temp_num)
//	{
//		if (temp_num > 0)
//		{
//			counter++;
//		}
//	}
//
//	cout << counter;
//}
//
////bool isOrdered()
////{
////	// returns false in decreasing order, true in increasing order.
////
////	static bool flag = false;
////	int dumbo1 = 0;
////	int dumbo2 = 0;
////
////	while (cin >> dumbo1)
////	{
////		if (dumbo1 == -1)
////		{
////			cout << "sentinel value entered";
////		}
////
////		else
////		{
////			cin >> dumbo2;
////
////			if (dumbo2 == -1)
////			{
////				cout << "sentinel value entered!";
////			}
////
////			else
////			{
////				if (dumbo1 > dumbo2)
////				{
////					flag = true;
////				}
////
////				else if (dumbo2 > dumbo1)
////				{
////					flag = false;
////				}
////			}
////
////		}
////		
////	}
////
////	return flag;
////}
//
//class Dice {
//public:
//	Dice(int sides);
//	int Roll();
//	int NumSides() const;
//	int NumRolls() const;
//	void ResetRollCount();
//private:
//	int myRollCount;
//	int mySides;
//};
//
//Dice::Dice(int sides)
//{
//	myRollCount = 0;
//	mySides = sides;
//}
//
////int Dice::Roll()
////{
////	RandGen rng;
////	//f3n3rbahc3
////	rng.SetSeed(1905);
////	rng.RandInt(0, 6);
////
////	myRollCount += 1;
////	/*return rng;*/
////}
//
///*void recursiveReverseSubstr(string& str, int idx)
//{
//	if 
//
//	recursiveReverseSubstr(str, idx - 1);
//}*/
//
//void Dice::ResetRollCount()
//{
//	myRollCount = 0;
//}
//
//void numbercounter()
//{
//	string asd;
//	int sum = 0;
//
//	while (cin >> asd)
//	{
//		for (int i = 0; i < asd.length(); i++)
//		{
//			if (((asd[i]) <= '9') && (asd[i] >= '0'))
//			{
//				sum += (int)asd[i] - '0';
//			}
//		}
//	}
//
//	cout << sum;
//}
//
//struct car
//{
//	string Pussy;
//	string Bitchass;
//	double sussyBakka;
//};

//////////////////////////////////////////////////////////////////////////////////////////////////

// write a city class, make a recursive binary search algorithm that scans through the sorted vector.
// use insertion sort to put the vector in order.

class City
{
	public:
		City(string name, unsigned long int population);
		City();

		string getName() const;
		unsigned long int getPop() const;

		void setName(string cityname);
		void setPop(unsigned long int pop);
		
	private:
		string name;
		unsigned long int population;
};

City::City(string cityname, unsigned long int pop)
{
	population = pop;
	name = cityname;
}

City::City()
{
	
}

string City::getName() const
{
	return name;
}

unsigned long int City::getPop() const
{
	return population;
}

void City::setName(string cityname)
{
	name = cityname;
}

void City::setPop(unsigned long int pop)
{
	population = pop;
}


void initialdb(vector<City> db)
{
	string filename;
	ifstream input;
	string s;
	string buffername;
	unsigned long int number = 0;

	cout << "please input filename";
	cin >> filename;
	input.open(filename.c_str());

	while (input.fail())
	{
		cout << "invalid file, please try again...";
		cin >> filename;
		input.open(filename.c_str());
	}

	while (getline(input, s))
	{
		istringstream onedata(s);
		onedata >> buffername >> number;
		
		db.push_back(City(buffername, number));
	}
}

void insertionSort(vector<City>& db)
{
	int k, loc, numElts = db.size();
	for (k = 1; k < numElts; k++)
	{
		City hold = db[k];
		loc = k;
		while (0 < loc && hold.getPop() < db[loc - 1].getPop())
		{
			db[loc] = db[loc - 1];
			loc--;
		}
		db[loc] = hold;
	}
}

void sortedOutput(vector<City>& db)
{
	ofstream output;
	string filename_out;

	cout << "please write the name of the file to which you want the sorted database" << endl;
	cin >> filename_out;
	output.open(filename_out.c_str(), ios::app);

	while (output.fail())
	{
		cout << "please input valid output name";
		cin >> filename_out;

		output.open(filename_out.c_str(), ios::app);
	}

	output.clear();

	for (int i = 0; i < db.size(); i++)
	{
		output << db[i].getName() << db[i].getPop() << endl;
	}
}

void recbinsearch(vector<City>& db, int key)
{
	int low = 0;
	int high = db.size() - 1;
	int mid;

	while (low <= high) {
		
		mid = (low + high) / 2;
		
		if (db[mid].getPop() == key)
			
			cout << db[mid].getPop();
		
		else if (db[mid].getPop() < key)
			
			low = mid + 1;
		
		else
			high = mid - 1;
	}
	
	cout << "not found";
}


// recursive function
void Bday(int begin_year)
{
	if (begin_year < 2023)
	{
		Date bday(5, 5, begin_year);
		cout << bday.DayName() << endl;
		Bday(begin_year + 1);
	}
}

int main()
{
	//vector<City> CityDB;
	string city = "Erzurum";

	Bday(2002);
	//initialdb(CityDB);
	//insertionSort(CityDB);
	////sortedOutput(CityDB);
	//recbinsearch(CityDB, 1300000);
	//recstringreverser(city, 3);
	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
class Polygon
{

	public:
		Polygon(int sides);
		Polygon();

		//mutators
		void SideCountIncrement();
		string setPolyName();
		Polygon operator ++ (int);

		//accessors
		int SideCount() const;
		int LengthFromCornerToCenter() const;
		int NumDiag() const;
		int NumTrig() const;
		string NamePolygon() const;

	private:
		string PolyName;
		int sideCount;
		int lengthFromCtoCorner;
};

//
//Polygon::Polygon(int sides)
//{
//
//}
//
//Polygon::Polygon()
//{
//
//}
//
//string Polygon::setPolyName()
//{
//	PolyName = sideCount;
//}
//
//int Polygon::SideCount() const
//{
//
//}
//
//void Polygon::SideCountIncrement()
//{
//
//}
//
//int Polygon::LengthFromCornerToCenter() const
//{
//
//}
//
//int Polygon::NumDiag() const
//{
//
//}
//
//int Polygon::NumTrig() const
//{
//
//}
//
//string Polygon::NamePolygon() const
//{
//
//}
//
//void
//posnum
//(int arr[])
//{
//	int i = 0;
//	int count = 0;
//
//	do 
//	{
//		if (arr[i] > 0)
//		{
//			count++;
//		}
//
//	} while (i < 199);
//}
//
//string stringmanip2(string s1, string s2, string s3)
//{
//	string part1;
//	string part2;
//
//	part1 = s1.substr((s1.substr(s1.find(s2) + 1).find(s2)) + s2.length() - 1);
//	part2 = s1.substr(0, s1.substr(s1.find(s2) + 1).find(s2));
//
//	return part2 + s3 + part1;
//}
//
//double findPvalue(double x, int n, int p)
//{
//	double sum = 0;
//	double multiple = 1;
//
//	for (int i = 3; i < n; i++)
//	{
//		for (int j = i; j < p; j++)
//		{
//			sum += abs(x - pow(j, 2));
//		}
//
//		multiple *= x * pow(sum, i);
//	}
//
//	return multiple;
//}
//
//
////void recursiveBinarySearch(vector<int> array)
////{
////
////}
//
//void telcost(float area, float duration)
//{
//	if ((area >= 200) && (area <= 299))
//	{
//		cout << duration * 100;
//	}
//
//	else if ((area >= 300) && (area <= 499))
//	{
//		cout << duration * 150;
//	}
//
//	else if ((area >= 500) && (area <= 599))
//	{
//		cout << duration * 300;
//	}
//}
//
//void orderChecker()
//{
//	// flag assumed to be true up until the point theres indoubtable evidence that there is not an order.
//	bool flag = true;
//	int dumbo = INT_MIN;
//	int dumbo2 = 0;
//
//	while ((cin >> dumbo2) && (dumbo2 != -1))
//	{
//		if (dumbo2 > dumbo)
//		{
//			dumbo = dumbo2;
//		}
//
//		else
//		{
//			flag = false;
//		}
//	}
//
//	cout << flag;
//}
//
////double fracPart(double num)
////{
////	double trouble = DBL_MIN;
////	if (double )
////
////	while 
////}
//
//int main()
//{	
//	/*float duration = 0;
//	float area = 0;
//	
//	cin >> area;
//	cin >> duration;
//
//	if ((area >= 200) && (area <= 599) && (duration > 0))
//	{
//		telcost(area, duration);
//	}
//
//	else
//	{
//		cout << "error";
//		exit(1);
//	}*/
//
//	//void 
//	//string asd = "asdasdasdasd";
//	//car Car;
//	//Car.Bitchass = "hoe";
//
//	//car Pussy;
//	//Pussy.Bitchass = "nigga";
//	//cout << Car.Bitchass << setw(1) << Pussy.Bitchass;
//
//
//	//recursiveReverseSubstr(asd, 3);
//	//orderChecker();
//	/*numbercounter();*/
//	//posnum();
//	//isOrdered();
//	//findPvalue(5.0, 2, 3);
//	//cout << stringmanip1("asdfghiqwertyu", 7);
//	//cout << stringmanip2("hatasiz sinav olmaz, hatamla sev beni", "hata", "kopya");
//	return 0;
//}
//

