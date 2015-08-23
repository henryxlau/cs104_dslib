#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

// list definitions
#include "ilist.h"
#include "linkedlist.h"
#include "arraylist.h"
#include "plusonearraylist.h"
#include "plustenarraylist.h"
#include "doublingarraylist.h"
using namespace std;

double MeasureFrontInsertTime(IList<int> * list, int insertCount = 50000)
{
    double time = 0.0;

	clock_t start = clock();
    for(int i = 0; i < insertCount; ++i) 
	{
		list->insert(0, i);
	}
	clock_t end = clock();

	time = (double)(end - start) / ((double)CLOCKS_PER_SEC);
	return time;
}

double MeasureBackInsertTime(IList<int> * list, int insertCount = 50000)
{
    double time = 0.0;
    
	clock_t start = clock();
    for(int i = 0; i < insertCount; ++i) 
	{
		list->insert(i, i);
	}
	clock_t end = clock();

	time = (double)(end - start) / ((double)CLOCKS_PER_SEC);
    return time;
}

int main()
{
    double frontTime = 0.0, backTime = 0.0;
    IList<int> ** lists = new IList<int>*[8];

    // feel free to pass some argument to your constructor or just leave it to the default constructor
    lists[0] = new LinkedList<int>;          // front insert
    lists[1] = new LinkedList<int>;          // back  insert
    lists[2] = new PlusOneArrayList<int>;    // front insert
    lists[3] = new PlusOneArrayList<int>;    // back  insert
    lists[4] = new PlusTenArrayList<int>;    // front insert
    lists[5] = new PlusTenArrayList<int>;    // back  insert
    lists[6] = new DoublingArrayList<int>;   // front insert
    lists[7] = new DoublingArrayList<int>;   // back  insert

    for (int i = 0; i < 8; i += 2)
    {
        frontTime = MeasureFrontInsertTime(lists[i]);
        backTime  = MeasureBackInsertTime (lists[i + 1]);
		
		if (i == 0)
			cout << "Linked List: " << endl;
		else if (i == 2)
			cout << "Array Plus One: " << endl;
		else if (i == 4)
			cout << "Array Plus Ten Percent: " << endl;
		else
			cout << "Array Double: " << endl;

        // cout the duration in seconds
		cout << "Insert from front: " << fixed << setprecision(4) << frontTime << " seconds."<< endl
			 << "Insert from back: " << fixed << setprecision(4) << backTime << " seconds." << endl << endl;

        // release: you can optionally measure delete (removing all items) duration
        delete lists[i];
        delete lists[i + 1];
    }
    delete [] lists;
    return 0;
}