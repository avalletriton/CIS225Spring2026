//Write a program that uses a two-dimensional array to store the highest and lowest temperatures for each month of the year.
// The program should output the average high, average low, and the highest and lowest temperatures for the year.
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
const int months = 12;
void GetData(double temps[][2], int rows) //reads and stores data in two dimensional array
{
	int i;
	for (i = 0; i < rows; i++)
	{
		cout << "Enter the " << (i + 1) << " month's low temperature: ";
		cin >> temps[i][0];

		cout << "Enter the " << (i + 1) << " month's high temperature: ";
		cin >> temps[i][1];
	}
	
}
double averageHigh(const double temps[][2], int rows) //Calculates and returns the average high temperature for the year
{
	double total = 0;
	int i;

	for (i = 0; i < rows; i++)
	{
		total += temps[i][1];
	}
	return total / rows;
}
double averageLow(const double temps[][2], int rows) // calculates and returns the average low temperature for the year
{
	double total = 0;
	int i;

	for (i = 0; i < rows; i++)
	{
		total += temps[i][0];
	}
	return total / rows;
}
int indexHighTemp(const double temps[][2], int rows) // returns the index of the highest temperature in the array
{
	int dex = 0;

	for (int i = 1; i < rows; i++)
	{
		if (temps[i][1] > temps[dex][1])
			dex = i;
	}

	return dex;
}
int indexLowTemp(const double temps[][2], int rows) // returns the index of the lowest low temperature in the array
{
	int dex = 0;

	for (int i = 1; i < rows; i++)
	{
		if (temps[i][0] < temps[dex][0])
			dex = i;
	}

	return dex;
}
int main()
{
	double temps[months][2];
	
	//funtions
	GetData(temps,months);
	double AH = averageHigh(temps, months);
	double AL = averageLow(temps, months);
	int highIndex = indexHighTemp(temps, months);
	int lowIndex = indexLowTemp(temps, months);

	cout << "---------------------------------------" << endl;
	cout << "Average High: " << AH << endl;
	cout << "Average Low: " << AL << endl;
	cout << "Highest Temperature of the year: " << temps[highIndex][1] << endl;
	cout << "Lowest Temperature of the year : " << temps[lowIndex][0] << endl;

	return 0;
}