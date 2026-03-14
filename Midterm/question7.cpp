#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int total = 10;
struct item
{
	string degree;
	int students;
	bool online;
	float cost;
};

void load_array(ifstream& infile, item list[], int& count)
{
	string degree, students, online, cost;

	while (getline(infile, degree, ','))
	{
		if (degree.size() > 0 && degree[0] == ' ')
			degree.erase(0, 1);

		getline(infile, students, ',');
		if (students.size() > 0 && students[0] == ' ')
			students.erase(0, 1);

		getline(infile, online, ',');
		if (online.size() > 0 && online[0] == ' ')
			online.erase(0, 1);

		getline(infile, cost);
		if (cost.size() > 0 && cost[0] == ' ')
			cost.erase(0, 1);

		list[count].degree = degree;
		list[count].students = stoi(students);

		if (online == "true")
		{
			list[count].online = true;
		}
		else
		{
			list[count].online = false;
		}

		list[count].cost = stof(cost);

		count++;
	}
}
void display_array(const item list[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << boolalpha << list[i].degree << "   " << list[i].students << "   " << list[i].online << "   " << list[i].cost << endl;
	}
}
int main()
{
	item list[total];
	int count = 0;
	string search;

	ifstream infile("Fields.txt");
	if (!infile)
	{
		cout << "File couldn't open." << endl;
		return 1;
	}

	load_array(infile, list, count);
	infile.close();

	
	display_array(list, count);
	cout << endl << endl;

	return 0;
}