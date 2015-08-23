#ifndef MAP_H_
#define MAP_H_
#include "LinkedList.h"

template <class keyType, class valueType>
struct mapNode
{
	keyType _key;
	valueType _value;
};

template <class keyType, class valueType>
class Map
{
public:
	Map();
    ~Map();
	int size () const;
	void add (const keyType & key, const valueType & value); 
	void remove (const keyType & key);
	valueType const & get (const keyType & key) const;
private:
	LinkedList< mapNode<keyType,valueType> > internalStorage;
     /* You should store all of your associations inside one list.
        It is part of your assignment to figure out what types you 
        should store in that list.
        (Hint: you may need to add an additional definition.) */

     /* If you like, you can add further data fields and private
        helper methods.
        In particular, a 'find' function could be useful, which
        will find the index in the list at which a given key sits. */
};

template <class keyType, class valueType>
Map<keyType, valueType>::Map() {} // constructor for a new empty map

template <class keyType, class valueType>
Map<keyType, valueType>::~Map()
{
	internalStorage.~LinkedList();
} // destructor

template <class keyType, class valueType>
int Map<keyType, valueType>::size () const
{
	return internalStorage.size();
}// returns the number of key-value pairs

template <class keyType, class valueType>
void Map<keyType, valueType>::add (const keyType & key, const valueType & value)
{
	for (int i = 0; i < size(); i++)
	{
		if (internalStorage.get(i)._key == key)
			throw logic_error ("ERROR -  Key already exist!");
	}

	mapNode<keyType,valueType> *temp = new mapNode<keyType, valueType>;
	temp->_key = key;
	temp->_value = value;
	internalStorage.insert(0, *temp);
}
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should throw an exception.
      */

template <class keyType, class valueType>
void Map<keyType, valueType>::remove (const keyType & key)
{
	for (int i = 0; i < size(); i++)
	{
		if (internalStorage.get(i)._key == key)
		{
			internalStorage.remove(i);
			return;
		}
	}
	throw logic_error ("ERROR -  Key does not exist!");
}
     /* Removes the association for the given key.
        If the key has no association, it should throw an exception. */

template <class keyType, class valueType>
valueType const & Map<keyType, valueType>::get (const keyType & key) const
{
	for (int i = 0; i < size(); i++)
	{
		if (internalStorage.get(i)._key == key)
		{
			return internalStorage.get(i)._value;
		}
	}
	throw logic_error("ERROR -  Key does not exist!"); 
}
	/* Returns the value associated with the given key.
        If the key has no association, it should throw an exception. */

#endif //MAP_H_