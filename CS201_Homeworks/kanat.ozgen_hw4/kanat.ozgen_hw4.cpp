#include <iostream>
#include <string>
#include <vector>
#include "randgen.h"
using namespace std;

struct Film
{
	string name;
	int year;
	string genre;
};

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

Film vector_sorter(vector<Film> &unsorted)
{
	Film top = unsorted[0];

	for (int i = 0; i < unsorted.size(); i++)
	{
		if (unsorted[i].year > top.year)
		{
			top = unsorted[i];
			unsorted[i] = unsorted[unsorted.size() - 1];
			unsorted[unsorted.size() - 1] = top;
			i = 0;
		}

		else if (unsorted[i].year == top.year)
		{
			if (unsorted[i].name < top.name)
			{
				top = unsorted[i];
				unsorted[i] = unsorted[unsorted.size() - 1];
				unsorted[unsorted.size() - 1] = top;
				i = 0;
			}
		}
	}

	return top;
}

int main()
{
	RandGen rand;
	rand.SetSeed(1907);
	
	string raw_FilmDatabase;
	cout << "Welcome to the movie recommender program!" << endl << endl;
	cout << "Please enter the movie, year and genre list:" << endl;
	cin >> raw_FilmDatabase;
	cout << endl;

	vector<Film> FilmDatabase(10);
	int film_sep_index = 0;
	
	// This creates the data structure
	for (int i = 0; i < 10; i++)
	{
		Film film;
		string singular_film_data;

		if (film_sep_index == 0)
		{
			singular_film_data = raw_FilmDatabase.substr(0, raw_FilmDatabase.find("|"));

			FilmDatabase[i].name = singular_film_data.substr(0, singular_film_data.find(";"));
			FilmDatabase[i].year = stoi(singular_film_data.substr(singular_film_data.find(";") + 1, 4));
			FilmDatabase[i].genre = singular_film_data.substr(singular_film_data.rfind(";") + 1);

			film_sep_index = raw_FilmDatabase.find("|");
		}

		else if (film_sep_index == string::npos)
		{
			singular_film_data = raw_FilmDatabase.substr(raw_FilmDatabase.rfind("|") + 1);

			FilmDatabase[i].name = singular_film_data.substr(0, singular_film_data.find(";"));
			FilmDatabase[i].year = stoi(singular_film_data.substr(singular_film_data.find(";") + 1, 4));
			FilmDatabase[i].genre = singular_film_data.substr(singular_film_data.rfind(";") + 1);
		}
		
		else
		{
			singular_film_data = raw_FilmDatabase.substr(film_sep_index + 1, (raw_FilmDatabase.find("|", film_sep_index + 1) - film_sep_index - 1));

			FilmDatabase[i].name = singular_film_data.substr(0, singular_film_data.find(";"));
			FilmDatabase[i].year = stoi(singular_film_data.substr(singular_film_data.find(";") + 1, 4));
			FilmDatabase[i].genre = singular_film_data.substr(singular_film_data.rfind(";") + 1);

			film_sep_index = raw_FilmDatabase.find("|", raw_FilmDatabase.find(FilmDatabase[i].name));
		}
	}

	int selection = 0;

	cout << "Please select your action:" << endl;
	cout << "1. Select the genre of the movie that you want to watch" << endl;
	cout << "2. Select the year of the movie that you want to watch" << endl;
	cout << "3. Choose a random movie" << endl;
	cout << "4. Exit program" << endl;
	cout << endl;

	vector<Film> SortedFilmDatabase;
	
	for (int i = 0; i < 10; i++)
	{
		SortedFilmDatabase.push_back(vector_sorter(FilmDatabase));
		FilmDatabase.pop_back();
	}

	while (selection != 4)
	{
		cout << "Enter your choice: ";
		cin >> selection;
		
		if (selection == 1)
		{
			vector<int> genre_sort_array;
			string genre_selection;

			cout << "Please enter the genre of the movie you want to watch: ";
			cin >> genre_selection;
			cout << endl;

			if (LowerString(raw_FilmDatabase).find(LowerString(genre_selection)) != string::npos)
			{
				cout << genre_selection << " movies from newest to oldest:" << endl;

				for (int i = 0; i < SortedFilmDatabase.size(); i++)
				{
					if (LowerString(SortedFilmDatabase[i].genre) == LowerString(genre_selection))
					{
						cout << "Movie name: " << SortedFilmDatabase[i].name << " Release Year: " << SortedFilmDatabase[i].year << endl;
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
			int lower_bound;
			int upper_bound;
			
			if (year_selection.find("-") != string::npos)
			{
				lower_bound = stoi(year_selection.substr(0, year_selection.find("-")));
				upper_bound = stoi(year_selection.substr(year_selection.find("-") + 1, string::npos));
			}

			for (int g = 0; g < SortedFilmDatabase.size(); g++)
			{
				if (SortedFilmDatabase[g].year == stoi(year_selection))
				{
					counter1++;
				}
			}
			
			for (int i = 0; i < SortedFilmDatabase.size(); i++)
			{
				if ((SortedFilmDatabase[i].year >= lower_bound) && (SortedFilmDatabase[i].year <= upper_bound))
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
					cout << "Movies released in " << year_selection << " from A to Z:" << endl;

					for (int y = 0; y < SortedFilmDatabase.size(); y++)
					{
						if (SortedFilmDatabase[y].year == stoi(year_selection))
						{
							cout << "Movie name: " << SortedFilmDatabase[y].name << " Genre: " << SortedFilmDatabase[y].genre << endl;
						}
					}

					cout << endl;
				}
			}

			else if (counter2 != 0)
			{
				cout << "Movies released between the years " << year_selection << " from A to Z with decreasing year ordering:" << endl;

				if (counter2 != 0)
				{
					for (int y = 0; y < SortedFilmDatabase.size(); y++)
					{
						if ((SortedFilmDatabase[y].year >= lower_bound) && (SortedFilmDatabase[y].year <= upper_bound))
						{
							cout << "Movie name: " << SortedFilmDatabase[y].name << " Release Year: " << SortedFilmDatabase[y].year << " Genre: " << SortedFilmDatabase[y].genre << endl;
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

		else if (selection == 3)
		{
			int rng = rand.RandInt(SortedFilmDatabase.size());
			cout << "Movie name: " << SortedFilmDatabase[rng].name << " Release year: " << SortedFilmDatabase[rng].year << " Genre: " << SortedFilmDatabase[rng].genre << endl << endl;
		}

		else if ((selection > 4) || (selection < 1))
		{
			cout << "Invalid action!" << endl << endl;
		}
	}
	
	cout << "Thank you..." << endl;
	return 0;
}