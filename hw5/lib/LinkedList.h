#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Ilist.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

template <class T>
struct Item
{
	T value;
	Item<T> *prev, *next;
};

template <class T>
class LinkedList : public IList<T>
{
public:
	LinkedList() : head(NULL), tail(NULL) { };
	virtual ~LinkedList();
	virtual int size () const;
	virtual void insert (int position, const T & val);
	virtual void remove (int position);
	virtual void set (int position, const T & val);
	virtual T & get (int position);
	virtual T const & get (int position) const;

private:
	Item<T> *head, *tail;
};

template <class T>
LinkedList<T>::~LinkedList()
{
	while (head != NULL)
	{
		Item<T> * temp = head;
		head = head->next;
		if (head != NULL)
		{
			delete temp;
			head->prev = NULL;
		}
	}
} // destructor

template <class T>
int LinkedList<T>::size () const
{
	Item<T> * temp = head;
	int size = 0;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return size;
}  // returns the number of elements in the list

template <class T>
void LinkedList<T>::insert (int position, const T & val)
{
	Item<T> * target = head;

	Item<T> *temp = new Item<T>;
	temp->next = NULL;
	temp->prev = NULL;
	temp->value = val;

	if (position == 0 && head == NULL)
	{
		head = tail = temp;
	}
	else if (position == 0 && head != NULL)
	{
		temp->next = head;
		head->prev = temp;
		temp->prev = NULL;
		head = temp;
	}
	else if(position > 0 && position < size())
	{
		temp->prev = target->prev;
		temp->next = target;
		target->prev = temp;
		temp->prev->next = temp;
	}
	else if(position == size())
	{ 
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}
      /* Inserts val into the list before the given position,
         shifting all later items one position to the right.
         Inserting before 0 makes it the new first element.
         Inserting before size() makes it the new last element.
         Your function should throw an exception if position is
         outside the legal range. */

template <class T>
void LinkedList<T>::remove (int position)
{
	Item<T> * target = head;

	int i = 0;
	while (i != position)
	{
		if (target == NULL)
			throw out_of_range("Index is out of range");
		target = target->next;
		i++;
	}
	Item<T> * temp = target;

	if (position == 0 && head == NULL)
	{
		cout << "Empty Linked List!" << endl;
	}
	else if (position == 0 && head != NULL)
	{
		if (target->next != NULL)
		{
			target->next->prev = NULL;
			head = target->next;
			delete temp;
		}
		else
		{
			delete head;
			head = NULL;
		}
	}
	else if(position > 0 && position < size())
	{
		target->prev->next = target->next;
		target->next->prev = target->prev;
		delete temp;
	}
	else if(position == size())
	{ 
		target->prev->next = NULL;
		tail = target->prev;
		target = tail;
		delete temp;
	}
}
      /* Removes the item from the given position, shifting all
         later items one position to the left.
         Your function should throw an exception if position is
         outside the legal range. */

template <class T>
void LinkedList<T>::set (int position, const T & val)
{
	Item<T> * target = head;

	int i = 0;
	while (i != position)
	{
		if (target == NULL)
			throw out_of_range("Index is out of range");
		target = target->next;
		i++;
	}
	
	target->value = val;
}
      /* Overwrites the given position with the given value.
         Does not affect any other positions.  
         Your function should throw an exception if position is
         outside the legal range. */
  
template <class T>
T & LinkedList<T>::get (int position)
{
	Item<T> * target = head;

	int i = 0;
	while (i != position)
	{
		if (target == NULL)
			throw out_of_range("Index is out of range");
		target = target->next;
		i++;
	}

	return target->value;
}
      /* Returns the item at the given position.
         Your function should throw an exception if position is
         outside the legal range. */

template <class T>
T const & LinkedList<T>::get (int position) const
{
	Item<T> * target = head;

	int i = 0;
	while (i != position)
	{
		if (target == NULL)
			throw out_of_range("Index is out of range");
		target = target->next;
		i++;
	}

	return target->value;
}
      /* Returns the item at the given position.
         Your function should throw an exception if position is
         outside the legal range */

#endif //LINKEDLIST_H