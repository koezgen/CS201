#include "movie.h"
#include <iostream>
#include <string>
using namespace std;

// Kanat Özgen

// constructors

Movie::Movie()
{
	year = 0;
}

Movie::Movie(string n, int y, string g)
{
	name = n;
	year = y;
	genre = g;
}

// these are the member functions
// the ones with the set are mutators
// whereas the ones with get are accessors.

string Movie::getName() const
{
	return name;
}

void Movie::setName(string n)
{
	name = n;
}

void Movie::setGenre(string g)
{
	genre = g;
}

string Movie::getGenre() const
{
	return genre;
}

void Movie::setYear(int y)
{
	year = y;
}

int Movie::getYear() const
{
	return year;
}

void Movie::print(int a) const
{
	if (a == 1)
	{
		cout << "Movie name: " << name << "Release Year: " << year << endl;
	}

	if (a == 2)
	{
		cout << "Movie name: " << name << "Genre: " << genre << endl;
	}

	if (a == 3)
	{
		cout << "Movie name: " << name << "Release Year: " << year << " Genre: " << genre << endl;
	}
}
