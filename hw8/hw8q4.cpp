#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include "Heap.h"
using namespace std;

struct comp{ 
	bool operator()(int & lhs, int & rhs) {
		return lhs < rhs;
	}
};

int main(int argc, char *argv[])
{
	srand(time(NULL));
	double insertTime = 0.0;
	double removeTime = 0.0;
	int x;
	cout << "number of nodes: ";
	cin >> x;
	try 
	{
		MaxHeap<int, comp> a(x, comp());

		for (int i = 0; i < 10; i++)
		{
			clock_t start = clock();
			for (int j = 0; j < 10000; j++)
			{
				//add
				a.add(rand() % 1000 +1);
			}
			clock_t end = clock();

			insertTime = (double)(end - start) / ((double)CLOCKS_PER_SEC);
			//for { removef }

			start = clock();
			for (int k = 0; k < 10000; k++)
			{
				//cout << a.peek() << endl;
				a.remove();
			}
			end = clock();

			removeTime = (double)(end - start) / ((double)CLOCKS_PER_SEC);

			//cout << "For " << i << " = Time: " << fixed << setprecision(4) << time << endl;
			cout << i << " Insert: " << fixed << setprecision(4) << insertTime << endl;

			cout << i << " Remove: " << fixed << setprecision(4) << removeTime << endl;
			// time =fasfasd

		}
	}
	catch (logic_error & e)
	{
		cout << e.what() << endl;
	}

	// for(int i = -1; i != -6; i--)
	// 	a.add(i);
	// try{
	// a.print();
	// cout << a.peek() << endl;
	// a.remove();
	// cout << a.peek() << endl;
	// a.remove();
	// cout << a.peek() << endl;
	// a.remove();
	// cout << a.peek() << endl;
	// a.remove();
	// cout << a.peek() << endl;
	// a.remove();
	// cout << a.peek() << endl;
	// a.remove();
	// cout << a.peek() << endl;}
	// catch (logic_error & e)
	// {
	// 	cout << e.what() << endl;
	// }


	return 0;
}