//#pragma once
#include<string>
using namespace std;
class Item
{
public:
	string name;
	string description;
	float unitprice;
	void quantity(float quantity);
	float quantity();
	float discountprice();
private:
	float m_discount, m_quantity;
};
void Item::quantity(float quantity)
{
	m_quantity = quantity;
	if (m_quantity > 1000)
	{
		m_discount = 0.25;
	}
	else if (m_quantity <= 1000 && m_quantity > 500)
	{
		m_discount = 0.1;
	}
	else
	{
		m_discount = 0;
	}
}
float Item::quantity()
{
	return m_quantity;
}
float Item::discountprice()
{
	return (1 - m_discount) * unitprice * m_quantity;
}