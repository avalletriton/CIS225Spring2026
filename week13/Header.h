#include <string>
using namespace std;
class Employee
{
public:
	Employee();
	void first_name(string fname);
	string first_name();
	void last_name(string lname);
	string last_name();
	void salary(float s);
	float salary();
	Employee* nxt_ptr;
protected:
	float m_salary;
	string m_fn;
	string m_ln;
};
Employee::Employee()
{
	nxt_ptr = NULL;
}
void Employee::first_name(string fn)
{
	m_fn = fn;
}
string Employee::first_name()
{
	return m_fn;
}
void Employee::last_name(string ln)
{
	m_ln = ln;
}
string Employee::last_name()
{
	return m_ln;
}
float Employee::salary()
{
	return m_salary;
}
void Employee::salary(float s)
{
	m_salary = s;
}