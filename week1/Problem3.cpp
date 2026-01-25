//Enter the student’s last name, credit hours and financial aid, use ctl+z to stop.
// Pass credit hours and financial aid to a function by value.
// Pass tuition and tuition owed by reference. Compute tuition to be credit hours times $250.
// Compute tuition owed to be tuition minus the financial aid.
// Display student’s last name, tuition and tuition owed.
//Sum and display total tuition owed by all students, count of number of entries and average amount owed by students.
#include<iostream>
#include<iomanip>
using namespace std;
void comp_tuition(float hours, float aid, float& tuition, float& debt)
{
	tuition = hours * 250;
	debt = tuition - aid;
}
int main()
{
	string lname, stop;
	float hours, aid, tuition, debt, sumtuition, entries, averagedebt;
	sumtuition = 0;
	entries = 0;

	while (!cin.eof())
	{
		cout << "Please enter student's last name: ";
		cin >> lname;
		cout << "Please etner student's credit hours: ";
		cin >> hours;
		cout << "Please enter student's financial aid: ";
		cin >> aid;
		cout << "Enter any letter to continue or press ctrl z to stop: ";
		cin >> stop;

		comp_tuition(hours, aid, tuition, debt);

		cout << "Last name: " << lname << endl;
		cout << "Tuition: " << tuition << endl;
		cout << "Tuition owed : " << debt << endl;
		cout << "------------------------------------" << endl;

		entries = entries + 1;
		sumtuition = sumtuition + tuition;
		averagedebt = sumtuition / entries;
	}
	cout << "Entries: " << entries << endl;
	cout << "Total tuition owed: " << sumtuition << endl;
	cout << "Average tuition: " << averagedebt << endl;
	return 0;
}