//Write a program that reads in a line of data consisting of a student id (string of 5 char), student’s first name, student’s last name and GPA from a file into parallel arrays.
// Display the data from those arrays and a message that corresponds to the table below.
// Write a function to read the data into the arrays and another function that displays the data from the arrays.
// You can make up the data file using the format above.
// There should be 10 students in the file and so your arrays should accommodate 10 occurrences.
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
void load_array(string id[], string fname[], string lname[], string gpa[])
{
	int i;
	ifstream infile;

	infile.open("stats.txt");

	for (i = 0; i <= 9; i++)
	{
		infile >> id[i] >> fname[i] >> lname[i] >> gpa[i];
	}

	infile.close();
}
void print_array(string id[], string fname[], string lname[], string gpa[])
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		cout << id[i] << " " << fname[i] << " " << lname[i] << " " << gpa[i] << endl;
	}
}
int main()
{
	string id[10], fname[10], lname[10], gpa[10];

	load_array(id, fname, lname, gpa);

	cout << "ID   Name L-Name GPA" << endl;

	print_array(id, fname, lname, gpa);

	return 0;
}