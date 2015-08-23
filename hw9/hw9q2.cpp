#include <iostream>
#include "bst.h"
using namespace std;

int main(int argc, char const *argv[])
{
	//test for binary search tree
	BinarySearchTree<int, int> bst;

	//my inserts in to the bst.
	bst.insert(10,1);
	bst.insert(5,100);
	bst.insert(12,15);
	bst.insert(13,14);
	bst.insert(11,100);
	
	try{
		//tried to look up 50 which is not in the bst.
		cout << bst.lookup(50);
	}
	catch (KeyNotFoundException & e)
	{
		cout << e.what() << endl;
	}
	
	//Output the value from smallest to largest key (test for the operator++)
	for (BinarySearchTree<int, int>::iterator it = bst.begin(); it != bst.end(); ++it)
	{
		cout << it->second << " ";
	}

	cout << endl;

	bst.print();

	return 0;
}