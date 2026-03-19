//#pragma once
#include<string>
using namespace std;
class Student
{
public:
	string fname;
	string lname;
	float gpa;
	void credits(float credits);
	string standing();
private:
	string m_standing;
	float m_credits;
};
void Student::credits(float credits)
{
	credits = m_credits;
	if (credits > 120)
	{
		m_standing = "Senior";
	}
	else if (credits > 80)
	{
		m_standing = "Junior";
	}
	else if (credits > 50)
	{
		m_standing = "Sophmore";
	}
	else
	{
		m_standing = "Freshman";
	}
}
string Student::standing()
{
	return m_standing;
}