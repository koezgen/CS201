#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using namespace std;

class Movie
{
	private:
		string	name;
		string	genre;
		int		year;

	public:
		Movie();
		Movie(string n, int y, string g);
	
		void setName(string n);
		string getName() const;
		void setGenre(string g);
		string getGenre() const;
		void setYear(int y);
		int getYear() const;
		void print(int a) const;
};
#endif