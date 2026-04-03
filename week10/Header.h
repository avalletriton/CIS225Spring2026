#include<string>
using namespace std;
class student {
public:
	student();   // constructor method
	void st_fn(string fn);
	string st_fn();
	void st_ln(string ln);
	string st_ln();
	void st_score(float s);
	float st_score();
	string st_pass_or_fail();
	// need a pointer to the next object
	student* nxt_ptr;
protected:   // protected can be inherited
	float m_score;
	string m_ln;
	string m_fn;
	string m_pf_msg;
};
student::student()  //constructor
{
	nxt_ptr = NULL;
	m_score = 0;
}
void student::st_fn(string fn)
{
	m_fn = fn;
}
string student::st_fn()
{
	return m_fn;
}
void student::st_ln(string ln)
{
	m_ln = ln;
}
string student::st_ln()
{
	return m_ln;
}
void student::st_score(float s)
{
	m_score = s;
}
float student::st_score()
{
	return m_score;
}
string student::st_pass_or_fail()
{
	if (m_score >= 60)
		return "PASSED";
	else
		return "FAILED";
}
