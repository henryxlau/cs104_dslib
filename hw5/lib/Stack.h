#include "IList.h"
#include "LinkedList.h"

template <typename T>
class Stack : private LinkedList<T>
	/* may add inheritance declarations here 
    - decide if inheritance is private or public */
{
public:
  // add appropriate constructors and destructors
	Stack();
	~Stack();
	bool isEmpty() const;
	void push(const T& val);
	void pop();
	T const & top() const;
};

template <class T>
Stack<T>::Stack() {}

template <class T>
Stack<T>::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
}

template <class T>
bool Stack<T>::isEmpty() const
{
	if (this->size() == 0)
		return true;
	else
		return false;
} /* returns whether the stack contains any elements */

template <class T>
void Stack<T>::push(const T& val)
{
	this->insert(0, val);
} /* adds a value to the top of the stack */

template <class T>
void Stack<T>::pop()
{
	if (!isEmpty())
		this->remove(0);
	else
		throw logic_error("Stack is empty");
} /* deletes the top value from the stack */

template <class T>
T const & Stack<T>::top() const
{
	if (!isEmpty())
		return this->get(0);
	else {
		throw logic_error("Stack is empty");
	}
}  /* returns the top value on the stack */
