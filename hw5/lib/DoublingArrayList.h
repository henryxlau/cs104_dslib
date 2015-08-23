#ifndef DOUBLINGARRAYLIST_H
#define DOUBLINGARRAYLIST_H
#include "ArrayList.h"

template <class T>
class DoublingArrayList : public ArrayList<T>
{
public:
	void resize();
};

template <class T>
void DoublingArrayList<T>::resize()
{
	T * temp = new T[ArrayList<T>::capacity * 2];
	for (int i = 0; i < ArrayList<T>::capacity; i++)
		temp[i] = ArrayList<T>::data[i];
	ArrayList<T>::capacity *= 2;
	delete [] ArrayList<T>::data;
	ArrayList<T>::data = temp;
}

#endif //DOUBLINGARRAYLIST_H