#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <string>
#include <sstream>
#include <stdexcept>

#include "Ilist.h"

template <class T>
class ArrayList : public IList<T>
{
public:
	ArrayList() : capacity(10), length(0) {
		data = new T[capacity];
	}
	~ArrayList() { 
		delete [] data; 
	}
	int size() const;
	void insert(int position, T const & val);
	void remove(int position);
	void set(int postion, T const & val);
	T & get(int	position);
	T const & get (int position) const;

protected:
	virtual void resize() = 0;
	T * data;
	int capacity;
	int length;
};

template <class T>
int ArrayList<T>::size() const
{
	return length;
}

template <class T>
void ArrayList<T>::insert(int position, T const & val)
{
	if (position >= 0 && position <= length)
	{
		if (length == capacity)
		{
			resize();
		}
		for (int i = length - 1; i >= position; --i)
		{
			data[i+1] = data[i];
		}
		data[position] = val;
		++length;
	}
	else 
		throw out_of_range("Index is out of range");
}

template <class T>
void ArrayList<T>::remove(int position)
{
	if (position >= 0 && position < length)
	{
		for (int i = position + 1; i < length; i++)
			data[i-1] = data[i];
		--length;
	}
	else
		throw out_of_range("Index is out of range");
}

template <class T>
void ArrayList<T>::set(int position, T const & val)
{
	if (position >= 0 && position < length)
	{
		data[position] = val;
	}
	else
		throw out_of_range("Index is out of range");
}

template <class T>
T & ArrayList<T>::get(int position)
{
	return data[position];
}

template <class T>
T const & ArrayList<T>::get (int position) const
{
	return data[position];
}

#endif //ARRAYLIST_H