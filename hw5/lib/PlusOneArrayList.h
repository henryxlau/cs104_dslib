#ifndef PLUSONEARRAYLIST_H
#define PLUSONEARRAYLIST_H
#include "ArrayList.h"

template <class T>
class PlusOneArrayList : public ArrayList<T>
{
public:
	void resize();
};

template <class T>
void PlusOneArrayList<T>::resize()
{
	T * temp = new T[ArrayList<T>::capacity+1];
	for (int i = 0; i < ArrayList<T>::capacity; i++)
	{
		temp[i] = ArrayList<T>::data[i];
	}
	ArrayList<T>::capacity = ArrayList<T>::capacity + 1;
	delete [] ArrayList<T>::data;
	ArrayList<T>::data = temp;
}

#endif //PLUSONEARRAYLIST_H