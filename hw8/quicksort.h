#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

template <class T>
class QuickSort
{
public:
	QuickSort(int n): size(n), curr(0) { data = new T[size]; }
	~QuickSort() { delete [] data; }
	void mySwap(T &x, T &y);
	//int split(int left, int right, int pivot);
	void quicksort(int start, int end);
	void randQuicksort(int start, int end);
	void print();
	void inputData(T input);
	T getData(int i);
	void mixArray(int n, int input);

private:
	T *data;
	int size;
	int curr;
};

template <class T>
void QuickSort<T>::mixArray(int n, int input)
{
	for (int i = 0; i < n; i++)
	{
		mySwap(data[rand() % input], data[rand() % input]);
	}
}

template <class T>
void QuickSort<T>::inputData(T input)
{
	if (curr < size)
	{
		data[curr] = input;
		curr++;
	}
	else
	{
		cout << "Out of Bound!" << endl;
	}
	// for (int i = 0; i < size; i++)
	// {
	// 	cout << "Enter " << i+1 << " element: ";
	// 	cin >> data[i];
	// }
}

template <class T>
void QuickSort<T>::mySwap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

// int QuickSory::split(int left, int right, int pivot)
// {
// 	int left = start;
// 	int right = end;
	
// 	while (right > left)
// 	{
// 		while ((pivot >= data[left]) && (right > left))
// 		{
// 			left++;
// 		}
// 		mySwap(data[left], data[right]);

// 		while ((pivot < data[right]) && (right > left))
// 		{
// 			right--;
// 		}
// 		mySwap(data[left], data[right]);
// 	}
// 	return left;
// }

// void QuickSort::quicksort(int start, int end)
// {
// 	int pivot = data[end];
// 	int index;

// 	if (start < end)
// 	{
// 		index = split(start, end, pivot);
// 		data[index] = pivot;
// 		quicksort(start, index-1);
// 		quicksort(index+1, end);
// 	}
// }

template <class T>
void QuickSort<T>::quicksort(int start, int end)
{
	int leftBound = start;
	int rightBound = end - 1;
	int tempSize = end - start;
	
	if (tempSize > 1)
	{
		T pivot = data[rightBound];
		
		while (rightBound > leftBound)
		{
			while ((pivot < data[rightBound]) && (rightBound > leftBound))
			{
				rightBound--;
			}
			
			while ((pivot > data[leftBound]) && (rightBound >= leftBound))
			{
				leftBound++;
			}
			
			if (leftBound < rightBound)
			{
				mySwap(data[leftBound], data[rightBound]);
				leftBound++;
			}
		}

		quicksort(start, leftBound);
		quicksort(rightBound, end);
	}
}

template <class T>
void QuickSort<T>::randQuicksort(int start, int end)
{
	int leftBound = start;
	int rightBound = end - 1;
	int tempSize = end - start;
	
	if (tempSize > 1)
	{
		T pivot = data[rand() % tempSize + leftBound];
		
		while (rightBound > leftBound)
		{
			while ((pivot < data[rightBound]) && (rightBound > leftBound))
			{
				rightBound--;
			}
			
			while ((pivot > data[leftBound]) && (rightBound >= leftBound))
			{
				leftBound++;
			}
			
			if (leftBound < rightBound)
			{
				mySwap(data[leftBound], data[rightBound]);
				leftBound++;
			}
		}

		randQuicksort(start, leftBound);
		randQuicksort(rightBound, end);
	}

	// int random = rand() % end + start;
	// mySwap(data[random], data[end]);
	// int pivot = data[end];
	// int index;

	// if (start < end)
	// {
	// 	//index = split(start, end, pivot);
	// 	data[index] = pivot;
	// 	randQuicksort(start, index-1);
	// 	randQuicksort(index+1, end);
	// }
}

template <class T>
void QuickSort<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i+1 << ".) " << data[i] << endl;
	}
}

template <class T>
T QuickSort<T>::getData(int i)
{
	return data[i];
}

#endif //QUICKSORT_H