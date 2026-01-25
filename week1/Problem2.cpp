//Enter the weight of a package and zip code.
// Use ctl+z to stop. Use a single function to do the computations specified next.
// Pass these weight and zip code by value, and pass postage, area charge and weight charge by reference.
// Compute postage to be sum of weight charge and area charge. Use tables below to find the charges.
// Compute weight charge to be weight x weight charge per ounce.
//Find the area charge in the table based on zip code.
//Then compute postage to be area charge plus weight charge.
//The function should return the weight charge, area charge and postage.
//Display area charge, weight charge and postage.Count and display the number of entries made.
#include<iostream>
#include<iomanip>
using namespace std;
void comp_expenses(float weight, float zip, float& Acharge, float& Wcharge, float& postage)
{
	float charge_per_ounce;

	//Area Charge
	if (zip == 60171)
	{
		Acharge = 2;
	}
	else if (zip == 60172)
	{
		Acharge = 2.5;
	}
	else if (zip == 60635)
	{
		Acharge = 3;
	}
	else
		Acharge = 5;

	//weight charge
	if (weight > 100)
	{
		charge_per_ounce = 0.02f;
	}
	else if (weight > 50)
	{
		charge_per_ounce = 0.03f;
	}
	else
		charge_per_ounce = 0.05f;

	Wcharge = weight * charge_per_ounce;
	postage = Wcharge + Acharge;
}
int main()
{
	float weight, zip, Acharge, Wcharge, postage, entry;

	Acharge = 0;
	Wcharge = 0;
	postage = 0;
	entry = 0;

	while (!cin.eof())
	{
		cout << "Please enter weight: ";
		cin >> weight;
		cout << "Please enter zip(60171, 60172, 60635, other)(or press ctrl to stop): ";
		cin >> zip;

		comp_expenses(weight, zip, Acharge, Wcharge, postage);

		cout << "Weight charge: " << Wcharge << endl;
		cout << "Area Charge: " << Acharge << endl;
		cout << "Posetage: " << postage << endl;
		cout << "----------------------------------" << endl;

		entry = entry + 1;
	}
	cout << "Entries: " << entry;
	return 0;
} 