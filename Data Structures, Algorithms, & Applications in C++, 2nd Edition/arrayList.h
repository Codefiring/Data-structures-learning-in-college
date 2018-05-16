#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iterator>
#include <sstream>
#include <string>
#include <algorithm>
#include "myExceptions.h"
#include "linearList.h"
#include "changeLength1D.h"

using namespace std;

template <class T>
class arrayList : public linearList<T>
{
  public:
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> &);
    ~arrayList() { delete[] element; };

    // ADT方法
    bool empty() const { return listSize == 0; };
    int size() const { return listSize; };
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(ostream &out) const;

    //other methods
    int capacity() const { return arrayLength; }

  protected:
    void checkIndex(int theIndex) const;
    //若索引无效则抛出异常
    T *element;
    int arrayLength;
    int listSize;
};

template <class T>
arrayList<T>::arrayList(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity=" << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template <class T>
arrayList<T>::arrayList(const arrayList<T> &theList)
{ //复制构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
}

template <class T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index =" << theIndex << "size =" << listSize;
        throw illegalParameterValue(s.str());
    }
}

template <class T>
T &arrayList<T>::get(int theIndex) const
{ // get the element in the position "theIndex"
    checkIndex(theIndex);
    return element[theIndex];
}

template <class T>
int arrayList<T>::indexOf(const T &theElement) const
{
    int theIndex = (int)(find(element, element + listSize, theElement) - element);
    //"theIndex" is the relative index.
    if (theIndex == listSize)
        return -1;
    else
        return theIndex;
}

template <class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();
}

template <class T>
void arrayList<T>::insert(int theIndex, const T &theElement)
{
    if (theIndex < 0 || theIndex > listSize)
    { // invalid index
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    if (theIndex == listSize)
    {
        changeLength1D(element, arrayLength, 2 * arrayLength);

        /*try
		{
			int a[arrayLength];
		}
		catch (bad_alloc) { return false; }*/

        //int*a = new int[arrayLength];
        //for (int i = 0; i < arrayLength; i++)
        //{
        //	a[i] = *(element + i);
        //}
        //changeLength1D_again(a, arrayLength * 2);
        arrayLength *= 2;
    }

    copy_backward(element + theIndex, element + listSize, element + listSize + 1);
    element[theIndex] = theElement;
    listSize++;
}

template <class T>
void arrayList<T>::output(ostream &out) const
{
    copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}

// overload <<
template <class T>
ostream &operator<<(ostream &out, const arrayList<T> &x)
{
    x.output(out);
    return out;
}

#endif