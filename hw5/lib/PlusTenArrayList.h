#ifndef PLUSTENARRAYLIST_H
#define PLUSTENARRAYLIST_H
#include "ArrayList.h"

template <class T>
class PlusTenArrayList : public ArrayList<T>
{
public:
	void resize();
};

template <class T>
void PlusTenArrayList<T>::resize()
{	
	T * temp = new T[int(ArrayList<T>::capacity * 1.1)];
	for (int i = 0; i < ArrayList<T>::capacity; i++)
	{
		temp[i] = ArrayList<T>::data[i];
	}
	ArrayList<T>::capacity = int(ArrayList<T>::capacity * 1.1);
	delete [] ArrayList<T>::data;
	ArrayList<T>::data = temp;
}

#endif //PLUSTENARRAYLIST_H