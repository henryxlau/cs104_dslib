#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdlib.h>
using namespace std;

struct Item {
	Item() {value = 0; next = NULL;}
	Item(int val, Item *n) {value = val; next = n;}
	int value;
	Item *next;
};

Item *head;

bool isEven(int n)
{
	n = abs(n);
	return (n % 2 == 0);
}

bool isSquare(int n)
{
	if (n < 0)
		return false;
	double num = static_cast<double>(n);
	num = sqrt(num);
	int root = static_cast<int>(num);
	return n == (root * root);
}

bool isPrime(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			count++;
	}
	if (count == 2)
		return true;
	else
		return false;
}

void insert(int n)
{
	Item *currentItem = new Item(n, NULL);
	//currentItem->value = n;
	//currentItem->next = NULL;
	if (head == NULL)
		head = currentItem;
	else
	{
		currentItem->next = head;
		head = currentItem;
	}
}

void remove(Item *deleteItem)
{
	Item * temp = deleteItem;
	Item * next;
	while (temp != NULL)
	{
		next = temp->next;
		delete temp;
		temp = next;
	}
	deleteItem = NULL;
}

Item * filter(Item *head, bool (*f)(int))
{
	if (head == NULL)
	{
		return head;
	}
	else
	{
		if(f(head->value) == true)
		{
			return new Item(head->value, filter(head->next,f));
		}
		else
		{
			return filter(head->next, f);
		}
	}
}

void print (Item *p)
{
	if (p != NULL)
	{
		print (p->next);
		cout << p->value << endl;
	}
}

int main(int argc, char * argv[])
{
	Item * outputItem;
	head = NULL;
	ifstream inFile(argv[1]);
	int temp;
	int i = 0;
	string arg2 = argv[2];
	stringstream ss(arg2);
	char input;
	ss >> input;

	if (inFile.fail())
	{
		cout << "Error - file did not open! \n\n";
		return 1;
	}
	else
	{		
		while (inFile.good())
		{
			inFile >> temp;
			insert(temp);
		}

		switch(toupper(input)) 
		{
		case 'A': outputItem = filter(head, &isEven);
			break;
		case 'B': outputItem = filter(head, &isSquare);
			break;
		case 'C': outputItem = filter(head, &isPrime);
			break;
		default: cout << "Invalid input!" << endl;
			return 0;
		}
		
		print(outputItem);
	}

	remove(head);
	remove(outputItem);

	return 0;
}
