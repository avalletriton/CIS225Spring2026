#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
void load_array(string id[], string fname[], string lname[], string gpa[])
{
	int i;
	ifstream infile;

	infile.open("names.txt");

	for (i = 0; i <= 9; i++)
	{
		infile >> fname[i] >> lname[i] >> gpa[i];
	}

	infile.close();
}
void print_array(string id[], string fname[], string lname[], string gpa[])
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		cout << fname[i] << " " << lname[i] << " " << gpa[i] << endl;
	}
}
//New instructions: Add a function that displays the arrays in reverse order
//Afterwards, create a menu that provides the user with options
//The menu should look like the following:
//1. Dispalay arrays in order
//2. Display arrays in reverse order
//3. search bny student last name
//4. exit
//each option should be contained in its own function.
//option 3 should prompt the user for a last name, calla sequential search functions and display firstname, last name and gpa when found or message stating name not in list if not found.
void print_array_reverse(string id[], string fname[], string lname[], string gpa[])
{
	int i;

	for (i = 9; i >= 0; i--)
	{
		cout << fname[i] << " " << lname[i] << " " << gpa[i] << endl;
	}
}
//sequential search
void search_array(string id[], string fname[], string lname[], string gpa[], string& slname)
{
	int i;
	bool found_flag; //value is true or false

	found_flag = false;

	for (i = 0; i <= 9; i++)
	{
		if (slname == lname[i])
		{
			cout << fname[i] << " " << lname[i] << " " << gpa[i] << endl;
			found_flag = true;
		}
	}
	if (found_flag == false)
	{
		cout << "Student was not found" << endl;
	}
}
void menu_select(string id[], string fname[], string lname[], string gpa[], string& slname, string& options)// Menu selection
{
	if (options == "1")
	{
		cout << "Name L-Name GPA" << endl;
		print_array(id, fname, lname, gpa);
	}
	else if (options == "2")
	{
		cout << "---List in Reverse order---" << endl;
		cout << "Name L-Name GPA" << endl;
		print_array_reverse(id, fname, lname, gpa);
	}
	else if (options == "3")
	{
		cout << "Please enter the students last name to search: ";
		cin >> slname;
		search_array(id, fname, lname, gpa, slname);
	}
	else
	{
		cout << "Not an option";
	}
}
void menu(string id[], string fname[], string lname[], string gpa[], string& slname, string& options)//Menu display loop
{
	while (options != "4") //when option 4 gets entered, the program ends
	{
		cout << "-------- MENU --------" << endl;
		cout << "1. Display arrays in order" << endl;
		cout << "2. Display arrays in reverse order" << endl;
		cout << "3. Search student by last name" << endl;
		cout << "4. Exit" << endl;
		cout << "-----------------------" << endl;
		cout << "Enter the number of the correspdonding option: ";
		cin >> options;
		menu_select(id, fname, lname, gpa, slname, options);
	}
}
int main()
{
	string id[10], fname[10], lname[10], gpa[10], slname, options;
	load_array(id, fname, lname, gpa);

	menu(id, fname, lname, gpa, slname, options);

	return 0;
}