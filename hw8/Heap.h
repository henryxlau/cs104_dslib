#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <iostream>
#include <stdexcept> 

template <class T, class Comparator>
class MaxHeap 
{
public:
  MaxHeap (int d, Comparator comp);
  ~MaxHeap ();
  void add (const T & item);
  const T & peek () const;
  void remove ();
  bool isEmpty ();
  void mySwap(T &x, T &y);
  int getParent(int location);
  void resize();
  void trickleUp(int curr);
  void trickleDown(int curr);
  void print();

private:
  //vector<T> heap;
  T * heap;
  int numNodes;
  int size;
  int maxSize;
  Comparator compare;
};

template <class T, class Comparator>
MaxHeap<T, Comparator>::MaxHeap(int d, Comparator comp)
{
  if (d < 2)
  {
    throw std::out_of_range ("Must be larger than 2");
  }
  else
  {
    numNodes = d;
    maxSize = 1000000;
    heap = new T[maxSize];
    size = 0;
    compare = comp;
  }
}
       /* Constructor that builds a d-ary Max Heap using the given
          comparator to compare elements and decide which one is
          larger. 
          This should work for any d >= 2,
          but doesn't have to do anything for smaller d.*/

template <class T, class Comparator>
MaxHeap<T, Comparator>::~MaxHeap()
{
  delete [] heap;
}

template <class T, class Comparator>
void MaxHeap<T, Comparator>::resize()
{
  T * temp = new T[maxSize * 2];
  for (int i = 0; i < maxSize; i++)
    temp[i] = heap[i];
  maxSize *= 2;
  delete [] heap;
  heap = temp;
}

template <class T, class Comparator>
void MaxHeap<T, Comparator>::mySwap(T &x, T &y)
{
  T temp = x;
  x = y;
  y = temp;
}

template<class T, class Comparator>
int MaxHeap<T, Comparator>::getParent(int location)
{
  return (location - 1)/numNodes;
}

template <class T, class Comparator>
void MaxHeap<T, Comparator>::add (const T & item)
{
  if (size == maxSize)
  {
    resize();
  }
  size++;
  int index = size -1;
  heap[index] = item;
  trickleUp(index);
}
   /* adds the item to the heap */

template <class T, class Comparator>
void MaxHeap<T, Comparator>::trickleUp(int curr)
{
  int parent = getParent(curr);
  if (heap[curr] > heap[parent])
  {
    mySwap(heap[curr], heap[parent]);
    trickleUp(parent);
  }
}

template <class T, class Comparator>
const T & MaxHeap<T, Comparator>::peek () const
{
  if (size == 0) 
    throw std::out_of_range ("Heap is empty");
  else
    return heap[0];
}
   /* returns the element with maximum priority.
      Throws an exception if the heap is empty. */

template <class T, class Comparator>
void MaxHeap<T, Comparator>::remove()
{
  mySwap(heap[size -1], heap[0]);
  size--;
  trickleDown(0);
}
   /* removes the element with maximum priority. */

template <class T, class Comparator>
void MaxHeap<T, Comparator>::trickleDown(int curr)
{
  if (!((curr * numNodes +1) > size)) {
    int largestNum = 0;
    for (int i = curr * numNodes + 1; i <= curr * numNodes + numNodes && i < size; i++) {
       if (heap[i] > heap[largestNum])
       {
          largestNum = i;
       }
    }
    mySwap(heap[curr], heap[largestNum]);
    if (largestNum > 0)
      trickleDown(largestNum);
  }
}

template <class T, class Comparator>
bool MaxHeap<T, Comparator>::isEmpty ()
{
  if (size == 0)
    return true;
  else
    return false;
}
   /* returns true iff there are no elements on the heap. */

template <class T, class Comparator>
void MaxHeap<T, Comparator>::print()
{
  for (int i = 0; i < size; i++)
  {
    std::cout << heap[i] << ", ";
  }
  std::cout << std::endl;
}

#endif // MAXHEAP_H