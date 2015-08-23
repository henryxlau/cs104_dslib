#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> * list = new List<int>;
	try
	{
		list->insert(0,8);
		list->insert(1,15);
		list->insert(1,222);
		list->insert(2,16);
	}
	catch (const out_of_range & e)
	{ 
		cout << e.what() << endl;
	}
	cout << list->get(0) << " " << list->get(1) << " " << list->get(2) << endl;

	try
	{
		list->remove(1);
		list->remove(0);
		list->set(0, 10);
	}
	catch (const out_of_range & e)
	{
		cout << e.what() << endl;
		return 0;
	}

	cout << list->get(0) << " " << list->get(1) << endl;

	cout << "Size of list: " << list->size() << endl;

	list->~List();

	return 0;
}
