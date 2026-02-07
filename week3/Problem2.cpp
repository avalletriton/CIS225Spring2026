#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
void load_array(string fname[], string lname[], double salary[])
{
	int i;
	ifstream infile;

	infile.open("Empldata.txt");
	for (i = 0; i <= 9; i++)
	{
		getline(infile, fname[i], ','); //The way getline works is it reads until it sees a specific charater, then stops when the character. The character in this line is the comma.
		getline(infile, lname[i], ',');//It will read John, Jones, as "John" " Jones"
		if (!lname[i].empty() && lname[i][0] == ' ')//lname[i][0] checks the first character of the string.
			lname[i].erase(0, 1);//if the first character of the string is a space, erase(0,1) gets rid of the space.
		infile >> salary[i];
		infile.ignore(1000, '\n');//Use \ and not /
	}//Ignore is structure in the following way: [(check a certain amount of characters), '(specific character to ignore)']
	infile.close();
}
void Display_array(string fname[], string lname[], double salary[])
{
	int i;
	cout << fixed << setprecision(2);
	for (i = 0; i < 10; i++)
	{
		cout << fname[i] << " " << lname[i] << " " << salary[i] << endl;
	}
}
void search_array(string fname[], string lname[], double salary[], string& slname)
{
	int i;
	bool Employee;

	Employee = false;
	for (i = 0; i < 10; i++)
	{
		if (slname == lname[i])
		{
			cout << fname[i] << " " << lname[i] << " " << salary[i] << endl;
			Employee = true;
		}
	}
	if (Employee == false)
	{
		cout << "Employee not found" << endl;
	}
}
void search_salary(string fname[], string lname[], double salary[], string slname, double& s_s)
{
	int i;
	bool money;

	money = false;
	for (i = 0; i <= 9; i++)
	{
		if (s_s <= salary[i])
		{
			cout << fname[i] << " " << lname[i] << " " << salary[i];
			money = true;
		}
	}
	cout << endl;
	if (money == false)
	{
		cout << "Employee not found" << endl;
	}
}
void menu_selection(string fname[], string lname[], double salary[], string& slname, string& option, double& s_s)
{
	int i;
	if (option == "1")
	{
		Display_array(fname, lname, salary);
	}
	else if (option == "2")
	{
		cout << "Please enter Employee's last name for search: ";
		cin.ignore();
		getline(cin, slname);
		search_array(fname, lname, salary, slname);
	}
	else if (option == "3")
	{
		cout << "Enter employee salary for search: ";
		cin >> s_s;
		search_salary(fname, lname, salary, slname, s_s);
	}
}
void menu(string fname[], string lname[], double salary[], string& slname, string& option, double& s_s)
{
	while (option != "4")
	{
		cout << "------ MENU ------" << endl;
		cout << "1. Display Employee Data in Order" << endl;
		cout << "2. Search for Employee Last Name" << endl;
		cout << "3. Search for all Employees with salaries Greater Than ___" << endl;
		cout << "4. Exit" << endl;
		cout << "-------------------" << endl;
		cout << "Please enter the number corresponding to option: ";
		cin >> option;
		menu_selection(fname, lname, salary, slname, option, s_s);
	}
}
int main()
{
	string fname[10], lname[10], slname, option;
	double salary[10], s_s;
	s_s = 0;

	load_array(fname, lname, salary);
	menu(fname, lname, salary, slname, option, s_s);

	return 0;
}