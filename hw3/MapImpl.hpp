/*#ifndef MAPIMPL_H_
#define MAPIMPL_H_
#include "Map.h"

template <class keyType, class valueType>
Map<keyType, valueType>::Map() {} // constructor for a new empty map

template <class keyType, class valueType>
Map<keyType, valueType>::~Map()
{
	internalStorage.~List();
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
      //Adds a new association between the given key and the given value.
         //If the key already has an association, it should throw an exception.
      

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
     //Removes the association for the given key.
        //If the key has no association, it should throw an exception. 

template <class keyType, class valueType>
valueType& Map<keyType, valueType>::get (const keyType & key) const
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
	 //Returns the value associated with the given key.
        //If the key has no association, it should throw an exception.

#endif //MAPIMPL_H_*/