#include<iostream>
#include<string>
#include<fstream>
#include "Header.h"
using namespace std;
int display_menu()
{
	int option;

	cout << endl << endl;
	cout << "1. Display List" << endl;
	cout << "2. Add a student" << endl;
	cout << "3. Delete first student" << endl;
	cout << "4. Exit" << endl;
	cin >> option;

	return option;
}
void add_student(student* h)  // h is the head of the list
{
	student* r = h, * new_st = new student;
	string fn, ln;
	float s;

	cout << "Enter new students first name, last name and score: ";
	cin >> fn >> ln >> s;

	// add code to instantiate a new node, add data to the node and add node to end of the list
	// remember to check for empty list

	//load data
	h = new_st;
	new_st->st_fn(fn);
	new_st->st_ln(ln);
	new_st->st_score(s);
	new_st->nxt_ptr = NULL;

	//check if its empty
	if (h == NULL)
	{
		h = new_st;
		return;
	}

	//last node
	while (r->nxt_ptr != NULL)
	{
		r = r->nxt_ptr;
	}

	//new node
	r->nxt_ptr = new_st;
}
student* delete_front(student* head)
{
	// add code to delete the last node. 
	// remember to check for empty list

	if (head == NULL)
	{
		cout << "The list is empty";
		return NULL;
	}

	student* temporary = head;
	head = head->nxt_ptr;
	delete temporary;

	return head;
}
void display_list(student* t)
{
	// add code to traverse the list starting at the front. 
	// procced through the list until the pointer to the next node is NULL or nullptr
	// check for empty list and display a message

	if (t == NULL)
	{
		cout << "The list is empty";
		return;
	}

	while (t != NULL)
	{
		cout << t->st_fn() << " " << t->st_ln() << " " << t->st_score() << " " << t->st_pass_or_fail() << endl;
		t = t->nxt_ptr;
	}
}
int main()
{
	string ln, fn;
	float s;
	ifstream infile;
	student* head = NULL;   //pointer to a student object
	student* cp = NULL;     // pointer to end of the list
	student* new_st = NULL;  // pointer to a new student object
	int option;  // the numbe of menu item the user selects

	// initially load the list from the data file.

	infile.open("lldata1.txt");

	while (!infile.eof())
	{
		infile >> fn >> ln >> s;
		//instantiate a student object
		new_st = new student;
		//load the object with data
		new_st->st_fn(fn);
		new_st->st_ln(ln);
		new_st->st_score(s);

		// check for empty list - its a special case
		if (head == NULL)
		{
			head = new_st;
			cp = new_st;
		}
		else   // list is not empty
		{
			cp->nxt_ptr = new_st;
			cp = new_st;
		}

	}  // end of loop

	// loop to give the user some options

	option = display_menu();

	while (option != 4)
	{
		if (option == 1)
			display_list(head);
		else if (option == 2)
			add_student(head);
		else if (option == 3)
			head = delete_front(head);

		option = display_menu();

	}


	system("pause");

	return 0;

}