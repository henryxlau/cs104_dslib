#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
using namespace std;

template <class T>
struct Item
{
	T value;
	Item<T> *prev, *next;
};

template <class T>
class List
{
public:
	  List();
	  ~List();
	  int size () const;
	  void insert (int position, const T & val);
	  void remove (int position);
	  void set (int position, const T & val);
	  T& get (int position) const;
private:
      Item<T> *head, *tail;
};

template <class T>
List<T>::List()
{
	head = tail = NULL;
} // constructor

template <class T>
List<T>::~List()
{
	while (head != NULL)
	{
		Item<T> * temp = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		delete temp;
	}
} // destructor

template <class T>
int List<T>::size () const
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
void List<T>::insert (int position, const T & val)
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
void List<T>::remove (int position)
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
		target->next->prev = NULL;
		head = target->next;
		free(temp);
	}
	else if(position > 0 && position < size())
	{
		target->prev->next = target->next;
		target->next->prev = target->prev;
		free(temp);
	}
	else if(position == size())
	{ 
		target->prev->next = NULL;
		tail = target->prev;
		target = tail;
		free(temp);
	}
}
      /* Removes the item from the given position, shifting all
         later items one position to the left.
         Your function should throw an exception if position is
         outside the legal range. */

template <class T>
void List<T>::set (int position, const T & val)
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
T & List<T>::get (int position) const
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

#endif //LIST_H
