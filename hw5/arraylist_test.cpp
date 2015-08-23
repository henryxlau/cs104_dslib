#include <iostream>
#include <cstdlib>
#include "ilist.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "plusonearraylist.h"
#include "plustenarraylist.h"
#include "doublingarraylist.h"

int main()
{
	IList<int> * oneArray = new PlusOneArrayList<int>;
	IList<int> * tenArray = new PlusTenArrayList<int>;
	IList<int> * doubleArray =  new DoublingArrayList<int>;

	for (int i = 0; i < 20; i++)
	{
		oneArray->insert(i,rand() % 100 +1);
	}
	
	for (int i = 0; i < 20; i++)
	{
		tenArray->insert(i,rand() % 100 +1);
	}

	for (int i = 0; i < 20; i++)
		doubleArray->insert(i,rand() % 100 +1);

	for (int i = 0; i < oneArray->size(); i++)
		cout << "oneArray: " << oneArray->get(i) << endl;
	cout << "oneArray's Size: " << oneArray->size() << endl;
	for (int i = 0; i < tenArray->size(); i++)
		cout << "tenArray: " << tenArray->get(i) << endl;
	cout << "tenArray's Size: " << tenArray->size() << endl;
	for (int i = 0; i < doubleArray->size(); i++)
		cout << "doubleArray: " << doubleArray->get(i) << endl;
	cout << "doubleArray's Size: " << doubleArray->size() << endl;

	for (int i = 0; i < 5; i++)
		oneArray->remove(i);
	for (int i = 0; i < 5; i++)
		tenArray->remove(i);
	for (int i = 0; i < 5; i++)
		doubleArray->remove(i);

	doubleArray->set(14, 10000);

	for (int i = 0; i < oneArray->size(); i++)
		cout << "oneArray: " << oneArray->get(i) << endl;
	cout << "oneArray's Size: " << oneArray->size() << endl;
	for (int i = 0; i < tenArray->size(); i++)
		cout << "tenArray: " << tenArray->get(i) << endl;
	cout << "tenArray's Size: " << tenArray->size() << endl;
	for (int i = 0; i < doubleArray->size(); i++)
		cout << "doubleArray: " << doubleArray->get(i) << endl;
	cout << "doubleArray's Size: " << doubleArray->size() << endl;

	oneArray->~IList();
	tenArray->~IList();
	doubleArray->~IList();

	return 0;
}