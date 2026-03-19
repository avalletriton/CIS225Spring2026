//#pragma once
#include<string>
using namespace std;
class Car
{
public:
	void make(string make);
	string make();
	void model(string model);
	string model();
	void msrp(float msrp);
	float msrp();
	float salesprice();
	void discountpercent(float discount);
	float discountpercent();
private:
	string m_make, m_model;
	float m_msrp, m_discount;
};
void Car::make(string make)
{
	m_make = make;
}
string Car::make()
{
	return m_make;
}
void Car::model(string model)
{
	m_model = model;
}
string Car::model()
{
	return m_model;
}
void Car::msrp(float msrp)
{
	m_msrp = msrp;
}
float Car::msrp()
{
	return m_msrp;
}
void Car::discountpercent(float discount)
{
	m_discount = discount;
}
float Car::discountpercent()
{
	return m_discount;
}
float Car::salesprice()
{
	return m_msrp - (m_msrp * m_discount);
}