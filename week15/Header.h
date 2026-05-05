#include<string>
using namespace std;
class TreeNode {
public:
	void GetLastName(string lname);
	string GetLastName();
	TreeNode* Left;
	TreeNode* Right;
protected:
	string m_lname;
};
void TreeNode::GetLastName(string lname)
{
	m_lname = lname;
}
string TreeNode::GetLastName()
{
	return m_lname;
}
#pragma once