/*
 * rbbst.h
 *
 *  Created on: Apr 14, 2014
 *      Author: kempe
 */

#include <iostream>
#include <exception>
#include <cstdlib>
#include "bst.h"

/* -----------------------------------------------------
 * Red-Black Nodes 
 ------------------------------------------------------*/

enum Color {red, black};

template <class KeyType, class ValueType>
class RedBlackNode : public Node<KeyType, ValueType>
{
public:
	RedBlackNode (KeyType k, ValueType v, RedBlackNode<KeyType, ValueType> *p)
	: Node<KeyType, ValueType> (k, v, p)
	  { color = red; }

	virtual ~RedBlackNode () {}

	RedBlackNode<KeyType, ValueType> *getUncle (RedBlackNode<KeyType, ValueType> *node) const
	{
		if (node != NULL)
		{
			if (node->getParent() != NULL)
			{
				if (node->getParent()->getParent() != NULL)
				{
					if (node == node->getParent()->getLeft())
						return node->getParent()->getRight();
					else
						return node->getParent()->getLeft();
				}
			}
		}
		return NULL;
	}

	RedBlackNode<KeyType, ValueType> *getGrandparent(RedBlackNode<KeyType, ValueType> *node) const
	{
		if (node != NULL)
		{
			if (node->getParent() != NULL)
			{
				if (node->getParent()->getParent() != NULL)
				{
					return node->getParent()->getParent();
				}
			}
		}
		return NULL;
	}

	Color getColor () const
	{ return color; }

	void setColor (Color c)
	{ color = c; }

        /* The type casting allows us to treat getParent, getLeft, getRight
           as returning RedBlackNode instead of Node */
	virtual RedBlackNode<KeyType, ValueType> *getParent () const
	{ return (RedBlackNode<KeyType,ValueType>*) this->_parent; }

	virtual RedBlackNode<KeyType, ValueType> *getLeft () const
	{ return (RedBlackNode<KeyType,ValueType>*) this->_left; }

	virtual RedBlackNode<KeyType, ValueType> *getRight () const
	{ return (RedBlackNode<KeyType,ValueType>*) this->_right; }

protected:
	Color color;
};

/* -----------------------------------------------------
 * Red-Black Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class RedBlackTree : public BinarySearchTree<KeyType, ValueType>
{
public:
	void add (KeyType key, ValueType value)
	{
		RedBlackNode<KeyType, ValueType> * tempNode = (RedBlackNode<KeyType, ValueType>*)this->root;
		RedBlackNode<KeyType, ValueType> * tempNodeParent = NULL;

		while (tempNode != NULL)
		{
			if (tempNode->getKey() > key)
			{
				tempNodeParent = tempNode;
				tempNode = tempNode->getLeft();
			}
			else if (tempNode->getKey() < key)
			{
				tempNodeParent = tempNode;
				tempNode = tempNode->getRight();
			}
			else
			{
				break;
			}
		}

		if (tempNode == NULL)
		{
			tempNode = new RedBlackNode<KeyType, ValueType> (key,value,tempNodeParent);
			if ((RedBlackNode<KeyType, ValueType>*)this->root == NULL)
			{
				this->root = tempNode;
			}
			else
			{
				if (tempNodeParent->getKey() > key)
				{
					tempNodeParent->setLeft(tempNode);
				}

				else 
				{
					tempNodeParent->setRight(tempNode);
				}
				fixtree((RedBlackNode<KeyType, ValueType>*)this->root);
			}
		}
		else
		{
			tempNode->setValue(value);
		}
	}
  /* This one is yours to implement.
     It should add the (key, value) pair to the tree, 
     making sure that it remains a valid Red-Black Tree.
     If the key is already in the tree (with a possibly different associated value),
     then it should overwrite the value with the new one.
     We strongly recommend defining suitable (private) helper functions. */
     
     void fixtree(RedBlackNode<KeyType, ValueType> * curr)
     {
     	while (curr != this->root && curr->getParent()->getColor() == red)
     	{
     		if (curr->getGrandparent(curr) != NULL)
     		{
	     		if (curr->getParent() == curr->getGrandparent(curr)->getLeft())
	     		{
	     			// std::cout << "temp: " << temp << std::endl;
					// std::cout << "gram: " << curr->getGrandparent(curr)->getKey() << std::endl;
					// std::cout << "righ: " << curr->getGrandparent(curr)->getRight() << std::endl;
	     			RedBlackNode<KeyType, ValueType> * temp = curr->getGrandparent(curr)->getRight();
	     			
	     			if (temp->getColor() == red)
	     			{
	     				curr->getParent()->setColor(black);
	     				temp->setColor(black);
	     				curr->getGrandparent(curr)->setColor(black);
	     				curr = curr->getParent()->getParent();
	     			}
	     			else
	     			{
	     				if (curr == curr->getParent()->getRight())
	     				{
	     					curr = curr->getParent();
	     					leftRotate(curr);
	     				}
	     				curr->getParent()->setColor(black);
	     				curr->getGrandparent(curr)->setColor(red);
	     				rightRotate(curr->getGrandparent(curr));
	     			}
	     		}
	     		else
	     		{
	     			RedBlackNode<KeyType, ValueType> * temp = curr->getParent()->getParent()->getLeft();
	     			
	     			// if (temp == NULL)
	     			// {
	     			// 	RedBlackNode<KeyType, ValueType> * temp2 = curr->getParent()->getParent();
	     			// 	temp = curr->getParent();
	     			// 	temp->setLeft(curr->getRight());
	     			// 	temp2->setRight(curr->getLeft());
	     			// 	temp->setParent(curr);
	     			// 	temp2->setParent(curr);
	     			// 	curr->setRight(temp);
	     			// 	curr->setLeft(temp2);
	     			// 	// rightRotate(curr);
	     			// 	// leftRotate(curr);

	     			// }

	     			if (temp->getColor() == red)
	     			{
	     				curr->getParent()->setColor(black);
	     				temp->setColor(black);
	     				curr->getGrandparent(curr)->setColor(red);
	     				curr = curr->getGrandparent(curr);
	     			}
	     			else
	     			{
	     				if (curr == curr->getParent()->getLeft())
	     				{
	     					curr = curr->getParent();
	     					rightRotate(curr);
	     				}
	     				curr->getParent()->setColor(black);
	     				curr->getGrandparent(curr)->setColor(red);
	     				leftRotate(curr->getGrandparent(curr));
	     			}
	     		}
     		}
     		else
     		{
     			break;
     		}
     	}
     	((RedBlackNode<KeyType, ValueType>*)this->root)->setColor(black);
     }

     void leftRotate(RedBlackNode<KeyType,ValueType> * x)
     {
     	RedBlackNode<KeyType, ValueType> * y = x->getRight();
     	x->setRight(y->getLeft());
     	if (y->getLeft() != NULL)
     		y->getLeft()->setParent(x);
     	y->setParent(x->getParent());
     	if (x->getParent() == NULL)
     		this->root = y;
     	else if (x->getParent()->getLeft() == x)
     		x->getParent()->setLeft(y);
     	else
     		x->getParent()->setRight(y);
     	y->setLeft(x);
     	x->setParent(y);
     }

     void rightRotate(RedBlackNode<KeyType,ValueType> * y)
     {
     	RedBlackNode<KeyType, ValueType> * x = y->getLeft();

     	y->setLeft(x->getRight());
     	if (x->getRight() != NULL)
     		x->getRight()->setParent(y);
     	x->setParent(y->getParent());
     	if (y->getParent() == NULL)
     		this->root = x;
     	else if (y->getParent()->getLeft() == y)
     		y->getParent()->setLeft(x);
     	else
     		y->getParent()->setRight(x);
     	x->setLeft(y);
     	y->setParent(x);
     }
};