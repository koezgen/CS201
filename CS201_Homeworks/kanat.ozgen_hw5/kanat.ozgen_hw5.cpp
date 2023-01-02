#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "movie.h"
using namespace std;

// Kanat Ozgen

// below functions are from the string manipulation class
void ToLower(string& s)
// postcondition: s all lower case     
{
	int len = s.length();
	for (int k = 0; k < len; k++)
	{
		s[k] = tolower(s[k]);
	}
}

string LowerString(const string& s)
{
	string word = s;
	ToLower(word);
	return word;
}

// This should do the sorting 
Movie vector_sorter(vector<Movie>& unsorted)
{
	Movie top = unsorted[0];

	for (int i = 0; i < unsorted.size(); i++)
	{
		if (unsorted[i].getYear() > top.getYear())
		{
			top = unsorted[i];
			unsorted[i] = unsorted[unsorted.size() - 1];
			unsorted[unsorted.size() - 1] = top;
			i = 0;
		}

		if (unsorted[i].getYear() == top.getYear())
		{
			if (unsorted[i].getName() < top.getName())
			{
				top = unsorted[i];
				unsorted[i] = unsorted[unsorted.size() - 1];
				unsorted[unsorted.size() - 1] = top;
				i = 0;
			}
		}

		if ((i == unsorted.size() - 1) && (unsorted[0].getYear() == top.getYear()) && (unsorted[0].getYear() == top.getYear()) && (unsorted[0].getName() == top.getName()))
		{
			unsorted[0] = unsorted[unsorted.size() - 1];
			unsorted[unsorted.size() - 1] = top;
		}
	}

	return top;
}

bool is_genre_present(vector<Movie> arbitrary, string input_genre)
{
	// this is done per default
	bool flag = false;
	for (int i = 0; i < arbitrary.size(); i++)
	{
		if (LowerString(arbitrary[i].getGenre()) == LowerString(input_genre))
		{
			flag = true;
		}
	}

	return flag;
}

int main()
{
	string filename;
	ifstream input;

	cout << "Welcome to the movie recommender program!" << endl << endl;
	cout << "Please enter the movie list filename: ";
	cin >> filename;
	input.open(filename.c_str());

	while (input.fail())
	{
		cout << "Please check filename! Enter a correct movie list filename: ";
		cin >> filename;
		input.open(filename.c_str());
	}

	int film_count = 0;

	vector<Movie> FilmDatabase;

	while (!input.eof())
	{
		Movie film;
		string line;
		string word;
		string film_concat;
		int bufferyear = 0;
		string buffergenre;
		int num = 0;

		getline(input, line);
		istringstream singular_film_data(line);

		while (singular_film_data >> word)
		{
			if ((atoi(word.c_str()) == 0) && (bufferyear == 0))
			{
				film_concat = film_concat + word + " ";
			}

			else if (bufferyear != 0)
			{
				buffergenre = word;
			}

			else
			{
				bufferyear = atoi(word.c_str());
			}
		}

		film.setName(film_concat);
		film.setYear(bufferyear);
		film.setGenre(buffergenre);

		FilmDatabase.push_back(film);
		film_count++;
	}

	int selection = 0;
	int print_selection = 0;

	cout << "Please select your action:" << endl;
	cout << "1. Select the genre of the movie that you want to watch" << endl;
	cout << "2. Select the year of the movie that you want to watch" << endl;
	cout << "3. Exit program" << endl;
	cout << endl;

	// this should stay the same, we have no business with this.
	vector<Movie> SortedFilmDatabase;

	for (int i = 0; i < film_count; i++)
	{
		SortedFilmDatabase.push_back(vector_sorter(FilmDatabase));
		FilmDatabase.pop_back();
	}

	while (selection != 3)
	{
		cout << "Enter your choice: ";
		cin >> selection;

		if (selection == 1)
		{
			print_selection = 1;
			vector<int> genre_sort_array;
			string genre_selection;

			cout << "Please enter the genre of the movie you want to watch: ";
			cin >> genre_selection;
			cout << endl;

			//if (LowerString(input).find(LowerString(genre_selection)) != string::npos)
			if (is_genre_present(SortedFilmDatabase ,genre_selection))
			{
				cout << genre_selection << " movies from newest to oldest:" << endl;

				for (int i = 0; i < SortedFilmDatabase.size(); i++)
				{
					if (LowerString(SortedFilmDatabase[i].getGenre()) == LowerString(genre_selection))
					{
						//cout << "Movie name: " << SortedFilmDatabase[i].getName() << "Release Year: " << SortedFilmDatabase[i].getYear() << endl;
						SortedFilmDatabase[i].print(print_selection);
					}
				}

				cout << endl;
			}

			else
			{
				cout << "There are no " << genre_selection << " movies!" << endl << endl;
			}
		}

		else if (selection == 2)
		{
			int counter1 = 0;
			int counter2 = 0;
			string year_selection;
			cout << "Please enter the year of the movie you want to watch: ";
			cin >> year_selection;
			int lower_bound = 0;
			int upper_bound = 0;

			if (year_selection.find("-") != string::npos)
			{
				lower_bound = stoi(year_selection.substr(0, year_selection.find("-")));
				upper_bound = stoi(year_selection.substr(year_selection.find("-") + 1, string::npos));
			}

			for (int g = 0; g < SortedFilmDatabase.size(); g++)
			{
				if (SortedFilmDatabase[g].getYear() == stoi(year_selection))
				{
					counter1++;
				}
			}

			for (int i = 0; i < SortedFilmDatabase.size(); i++)
			{
				if ((SortedFilmDatabase[i].getYear() >= lower_bound) && (SortedFilmDatabase[i].getYear() <= upper_bound))
				{
					counter2++;
				}
			}

			if (year_selection.find("-") == string::npos)
			{
				if (counter1 == 0)
				{
					cout << "There are no movies released in " << year_selection << "!" << endl << endl;
				}

				else
				{
					print_selection = 2;
					cout << "Movies released in " << year_selection << " from A to Z:" << endl;

					for (int y = 0; y < SortedFilmDatabase.size(); y++)
					{
						if (SortedFilmDatabase[y].getYear() == stoi(year_selection))
						{
							//cout << "Movie name: " << SortedFilmDatabase[y].getName() << "Genre: " << SortedFilmDatabase[y].getGenre() << endl;
							SortedFilmDatabase[y].print(print_selection);
						}
					}

					cout << endl;
				}
			}

			else if (counter2 != 0)
			{
				print_selection = 3;
				cout << "Movies released between the years " << year_selection << " from A to Z with decreasing year ordering:" << endl;

				if (counter2 != 0)
				{
					for (int y = 0; y < SortedFilmDatabase.size(); y++)
					{
						if ((SortedFilmDatabase[y].getYear() >= lower_bound) && (SortedFilmDatabase[y].getYear() <= upper_bound))
						{
							//cout << "Movie name: " << SortedFilmDatabase[y].getName() << "Release Year: " << SortedFilmDatabase[y].getYear() << " Genre: " << SortedFilmDatabase[y].getGenre() << endl;
							SortedFilmDatabase[y].print(print_selection);
						}
					}

					cout << endl;
				}
			}

			else
			{
				cout << "There are no movies released between " << year_selection << "!" << endl << endl;
			}
		}

		else if ((selection > 3) || (selection < 1))
		{
			cout << "Invalid action!" << endl << endl;
		}
	}

	cout << "Thank you..." << endl;
	return 0;
}