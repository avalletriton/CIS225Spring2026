//I created a text file that contains a list of movies.
//This list includes their title, genre, release year, rating.
//Using an array of structs, I want to make a program with a menu.
//This program can display movies based on genre or release date.
//When searching by rating, it will display the every rating equal to or greater than the input.
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include "movies.h"
#include<string>
using namespace std;
void displaymovies(const Movie[], const int);
const int array_size = 6;

void search_date(const Movie movies[], int count, string& date)
{
	int i;
	bool item;

	item = false;
	for (i = 0; i < count; i++)
	{
		if (movies[i].release >= date)
		{
			cout << "Title: " << movies[i].title << endl;
			cout << "Genre: " << movies[i].genre << endl;
			cout << "Release date: " << movies[i].release << endl;
			cout << "Rating out of 10: " << movies[i].rating << endl;
			cout << endl;
			item = true;
		}
	}
	if (item == false)
	{
		cout << "Movie not found" << endl;
	}
}
void search_genre(const Movie movies[], int count, string& g)
{
	int i;
	bool t;

	t = false;
	for (i = 0; i < count; i++)
	{
		if (movies[i].genre == g)
		{
			cout << "Title: " << movies[i].title << endl;
			cout << "Genre: " << movies[i].genre << endl;
			cout << "Release date: " << movies[i].release << endl;
			cout << "Rating out of 10: " << movies[i].rating << endl;
			cout << endl;
			t = true;
		}
	}
	cout << endl;
	if (t == false)
	{
		cout << "Genre not found" << endl;
	}
}
void menu_selection(const Movie movies[], int count, string& date, string& options)
{
	int i;
	string g;
	if (options == "1")
	{
		displaymovies(movies, count);
	}
	else if (options == "2")
	{
		cout << "Please enter release date to search: ";
		cin.ignore();
		getline(cin, date);
		search_date(movies, count, date);
	}
	else if (options == "3")
	{
		cout << "Enter genre for search (comedy, action, adventure): ";
		cin >> g;
		search_genre(movies, count, g);
	}
}
void menu(const Movie movies[], int count, string& date, string& options)
{
	while (options != "4")
	{
		cout << "------ MENU ------" << endl;
		cout << "1. Display Movie List" << endl;
		cout << "2. Search by release date" << endl;
		cout << "3. Search by genre" << endl;
		cout << "4. Exit" << endl;
		cout << "-------------------" << endl;
		cout << "Please enter the number corresponding to option: ";
		cin >> options;
		menu_selection(movies, count, date, options);
	}
}
int main()
{
	int i;
	string date, options;
	Movie movies[array_size];
	ifstream file("movie.txt");

	if (!file)
	{
		cerr << "Error opening file." << endl;
		return 1;
	}

	string line;
	int count = 0;

	while (count < array_size)
	{
		string line;
		getline(file, line);
		if (line.empty())
			continue;

		stringstream ss(line); 

		getline(ss, movies[count].title, ',');
		getline(ss, movies[count].genre, ',');
		getline(ss, movies[count].release, ',');
		ss >> movies[count].rating;

		if (!movies[count].title.empty() && movies[count].title[0] == ' ')
			movies[count].title.erase(0, 1);

		if (!movies[count].genre.empty() && movies[count].genre[0] == ' ')
			movies[count].genre.erase(0, 1);

		if (!movies[count].release.empty() && movies[count].release[0] == ' ')
			movies[count].release.erase(0, 1);

		count++;
	}

	file.close();

	menu(movies, count, date, options);

	return 0;
}
void displaymovies(const Movie movies[], const int size)
{
	cout << endl << "Movie List" << endl << endl;

	for (int i = 0; i < size; ++i)
	{
		cout << "Title: " << movies[i].title << endl;
		cout << "Genre: " << movies[i].genre << endl;
		cout << "Release date: " << movies[i].release << endl;
		cout << "Rating out of 10: " << movies[i].rating << endl;
		cout << endl;
	}
}