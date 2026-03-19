#include<iostream>
#include"Header1.h"
#include<string>
using namespace std;
int main()
{
	string fname, lname, standing;
	float gpa, credits;
	Student student;

	cout << "Enter first and last name, GPA, credits: ";
	cin >> student.fname >> student.lname >> student.gpa >> credits;
	student.credits(credits);

	cout << student.fname << " " <<  student.lname << " " << student.gpa << " " << student.standing();

	return 0;
}