#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include "quicksort.h"
using namespace std;

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int input;
	double time = 0.0;
	cout << "Array Size: ";
	cin >> input;

	QuickSort<int> a1(input);
	QuickSort<int> a2(input);
	QuickSort<int> a3(input);
	QuickSort<int> a4(input);
	QuickSort<int> a5(input);
	QuickSort<int> a6(input);
	QuickSort<int> a7(input);
	QuickSort<int> a8(input);
	QuickSort<int> a9(input);
	QuickSort<int> a10(input);
	QuickSort<int> a11(input);
	QuickSort<int> a12(input);
	QuickSort<int> a13(input);
	QuickSort<int> a14(input);
	QuickSort<int> a15(input);
	QuickSort<int> a16(input);
	QuickSort<int> a17(input);
	QuickSort<int> a18(input);
	QuickSort<int> a19(input);
	QuickSort<int> a20(input);

	for (int i = 0; i < input; i++)
	{
		a1.inputData(i);
		a2.inputData(i);
		a3.inputData(i);
		a4.inputData(i);
		a5.inputData(i);
		a6.inputData(i);
		a7.inputData(i);
		a8.inputData(i);
		a9.inputData(i);
		a10.inputData(i);
		a11.inputData(i);
		a12.inputData(i);
		a13.inputData(i);
		a14.inputData(i);
		a15.inputData(i);
		a16.inputData(i);
		a17.inputData(i);
		a18.inputData(i);
		a19.inputData(i);
		a20.inputData(i);
	}

	// cout << "Array is: " << endl;
	// a1.print();

	int x[10] = {0, 50, 100, 300, 500, 1000, 2000, 5000, 10000, 20000};
	
	for (int i = 0; i < 10; i++)
	{
		a1.mixArray(x[i], input);
		a2.mixArray(x[i], input);
		a3.mixArray(x[i], input);
		a4.mixArray(x[i], input);
		a5.mixArray(x[i], input);
		a6.mixArray(x[i], input);
		a7.mixArray(x[i], input);
		a8.mixArray(x[i], input);
		a9.mixArray(x[i], input);
		a10.mixArray(x[i], input);
		a11.mixArray(x[i], input);
		a12.mixArray(x[i], input);
		a13.mixArray(x[i], input);
		a14.mixArray(x[i], input);
		a15.mixArray(x[i], input);
		a16.mixArray(x[i], input);
		a17.mixArray(x[i], input);
		a18.mixArray(x[i], input);
		a19.mixArray(x[i], input);
		a20.mixArray(x[i], input);

		clock_t start = clock();
		a1.randQuicksort(0, input);
		a2.randQuicksort(0, input);
		a3.randQuicksort(0, input);
		a4.randQuicksort(0, input);
		a5.randQuicksort(0, input);
		a6.randQuicksort(0, input);
		a7.randQuicksort(0, input);
		a8.randQuicksort(0, input);
		a9.randQuicksort(0, input);
		a10.randQuicksort(0, input);
		a11.randQuicksort(0, input);
		a12.randQuicksort(0, input);
		a13.randQuicksort(0, input);
		a14.randQuicksort(0, input);
		a15.randQuicksort(0, input);
		a16.randQuicksort(0, input);
		a17.randQuicksort(0, input);
		a18.randQuicksort(0, input);
		a19.randQuicksort(0, input);
		a20.randQuicksort(0, input);
		clock_t end = clock();

		time = (double)(end - start) / ((double)CLOCKS_PER_SEC);

		//cout << "For " << i << " = Time: " << fixed << setprecision(4) << time << endl;
		cout << fixed << setprecision(4) << time << endl;
	}
	// cout << "Sorted Array is: " << endl;
	// a1.print();
	return 0;
}