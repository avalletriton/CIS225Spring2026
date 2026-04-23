#include <iostream>
#include<string>
#include <iomanip>
#include<fstream>
#include "Header.h"
using namespace std;
int display_menu()
{
	int op;

	cout << endl << endl;
	cout << " 1. Display Stack " << endl;
	cout << " 2. Push " << endl;
	cout << " 3. Pop  " << endl;
	cout << " 4. Exit " << endl;
	cout << " Please enter selection" << endl;
	cin >> op;

	return op;
}
void Display_Stack(Employee* Top)
{
	while (Top != NULL)
	{
		cout << Top->first_name() << endl;
		cout << Top->last_name() << endl;
		cout << Top->salary() << endl;
		cout << endl << endl;

		// complete code
		Top = Top->nxt_ptr;
	}
}
void Pop(Employee*& Top)
{
	// complete code
	if (Top == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		Employee* temp = Top;
		Top = Top->nxt_ptr;
		delete temp;
	}

	Display_Stack(Top);
}
void Push(Employee*& Top)
{
	// complete code
	string fn, ln;
	float s;

	cout << "Enter first name: ";
	cin >> fn;
	cout << "Enter last name: ";
	cin >> ln;
	cout << "Enter salary: $";
	cin >> s;


	Employee* n = new Employee;

	n->first_name(fn);
	n->last_name(ln);
	n->salary(s);

	n->nxt_ptr = Top;
	Top = n;

	Display_Stack(Top);
}

int main()
{
	string fn, ln;
	float s;
	ifstream infile;
	Employee* MyEmployee;
	Employee* Top = NULL;
	int option;

	infile.open("lab10d.txt");

	while (!infile.eof())
	{
		infile >> fn >> ln >> s;

		MyEmployee = new Employee;
		MyEmployee->first_name(fn);
		MyEmployee->last_name(ln);
		MyEmployee->salary(s);

		if (Top == NULL)
			Top = MyEmployee;
		else
		{
			MyEmployee->nxt_ptr = Top;
			Top = MyEmployee;
		}

	} //end of loop
	infile.close();

	option = display_menu();

	while (option != 4)
	{
		if (option == 1)
			Display_Stack(Top);
		else if (option == 2)
			Push(Top);
		else
			Pop(Top);

		option = display_menu();
	} // end of loop

	system("pause");

	return 0;
}