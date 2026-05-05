#include<iostream>
#include<fstream>
#include "Header.h"
using namespace std;

void Insert_BTree(TreeNode*& tree, string lname)  // Note: passing Root by reference because it may need be updated
{
	//TreeNode *tree;
	//tree=Root;
	// if the tree is empty, make a new node
	// and make it the root of the tree
	if (tree == NULL)
	{
		// add code to insert a new node
		tree = new TreeNode;
		tree->GetLastName(lname);
		tree->Left = NULL;
		tree->Right = NULL;
	}
	// Check if name is already in the tree, if so simply return
	// assumes no duplicate values
	if (tree->GetLastName() == lname)
		return;
	// The tree is not empty so insert the new node into left or right subtree
	if (lname < tree->GetLastName())
		Insert_BTree(tree->Left, lname);
	else
		Insert_BTree(tree->Right, lname);
}
void DisplayTree(TreeNode* tree)
{
	// add code for in-order traversal and display of the tree
	if (tree == NULL)
	{
		return;
	}
	DisplayTree(tree->Left);
	cout << tree->GetLastName();
	DisplayTree(tree->Right);
}
void Search_Tree(TreeNode* tree, string slname, bool& found_flag)
{
	// add code to search the tree for  specific node and indicate if not found
	if (tree == NULL)
	{
		found_flag = false;
		return;
	}
	else if (tree->GetLastName() == slname)
	{
		found_flag = true;
	}
	else if (tree->GetLastName() < slname)
	{
		Search_Tree(tree->Right, slname, found_flag);
	}
	else
	{
		Search_Tree(tree->Left, slname, found_flag);
	}
}
int Display_Menu()
{
	int option;

	cout << "*******************************************" << endl;
	cout << "1. Display Tree" << endl;
	cout << "2. Search Tree" << endl;
	cout << "3. Add to Tree" << endl;
	cout << "4. Remove from Tree" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter Menu Item";
	cin >> option;

	return option;
}
void Search_Tree(TreeNode* tree)
{
	string lname;
	bool found_flag;

	cout << endl << endl << "************************" << endl << endl;

	cout << "Enter last name to search for, ctl+z to stop";
	cin >> lname;
	while (!cin.eof())
	{
		found_flag = false;

		Search_Tree(tree, lname, found_flag);

		if (found_flag == true)
			cout << lname << " is in the tree" << endl;
		else
			cout << lname << " is not in the tree" << endl;

		cout << "Enter last name to search for, ctl+z to stop";
		cin >> lname;
	}
}
void Delete_Tree(TreeNode*& tree)
{
	TreeNode* NodeToDelete = tree;

	TreeNode* AttachPoint;

	if (tree->Right == NULL)
		tree = tree->Left;   //tree is the node above's tree->Left
	else if (tree->Left == NULL)
		tree = tree->Right;
	else
		// node has two children
	{


		AttachPoint = tree->Right;

		//locate the smallest node in the right subtree
		//by moving as far left as possible

		// add code here
		while (AttachPoint->Left != NULL)
		{
			AttachPoint = AttachPoint->Left;
		}

		// end of add code

		// attach the left subrtree of the original tree
		// as the left subtree of the smallest node
		// in the right subtree

		// add code hee
		AttachPoint->Left = tree->Left;
		// end of add code

		//replace original tree with its right subtree
		// add code here
		tree = AttachPoint;

		// end of add code

		//delete original node
		delete NodeToDelete;
	}


}
void Remove_Tree(TreeNode*& tree, string lname)
{
	if (tree == NULL) return;

	if (lname < tree->GetLastName())
		Remove_Tree(tree->Left, lname);
	else if (lname > tree->GetLastName())
		Remove_Tree(tree->Right, lname);
	else
		// We have found the node to delete.
		Delete_Tree(tree);
}



void Insert_Tree(TreeNode*& tree, string lname)
{
	// check for empty tree
	if (!tree)
	{
		tree = new TreeNode;
	}
}
int main()
{
	TreeNode* tree = NULL;
	ifstream infile;
	string lname;
	int option;

	infile.open("btdata.txt");

	while (!infile.eof())
	{
		infile >> lname;
		Insert_BTree(tree, lname);
	}

	option = Display_Menu();

	while (option != 5)
	{
		if (option == 1)
			DisplayTree(tree);
		else if (option == 2)
			Search_Tree(tree);
		else if (option == 3)
		{
			cout << "Enter Last Name to Insert into the Tree";
			cin >> lname;
			Insert_BTree(tree, lname);
		}
		else if (option == 4)
		{
			cout << "Enter Last Name to Delete";
			cin >> lname;
			Remove_Tree(tree, lname);
		}

		cin.clear();
		option = Display_Menu();
	}


	system("pause");
}