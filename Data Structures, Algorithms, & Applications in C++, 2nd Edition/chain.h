#ifndef CHAIN_H
#define CHAIN_H

#include <sstream>
#include <string>
#include <algorithm>
#include "myExceptions.h"
#include "linearList.h"
#include "chainNode.h"

template <class T>
class chain : public linearList<T>
{
  public:
    chain(int inistialCapacity = 10);
    chain(const chain<T> &);
    ~chain();

    //ADT
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T &get(int theElement) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(ostream &out) const;

  protected:
    void checkIndex(int theIndex) const;
    chainNode<T> *firstNode;
    int listSize;
};

template <class T>
chain<T>::chain(int inistialCapacity)
{
    if (inistialCapacity < 1)
    {
        ostringstream s;
        s << "The inistialCapacity = " << inistialCapacity << " should be over 10";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}

template <class T>
chain<T>::chain(const chain<T> &theList)
{
    listSize = theList.listSize;
    if (listSize == 0)
    {
        firstNode = NULL;
        return;
    }
    chainNode<T> *sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element); //copy the first element of theList to chain
    sourceNode = sourceNode->next;
    chainNode<T> *targetNode = firstNode;
    while (sourceNode != NULL)
    {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL;
}

template <class T>
chain<T>::~chain()
{
    while (firstNode != NULL)
    {
        chainNode<T> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template <class T>
void chain<T>::checkIndex(int theIndex) const
{ // Verify that theIndex is between 0 and listSize - 1.
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}

template <class T>
T &chain<T>::get(int theIndex) const
{
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "The index = " << theIndex << " must be in the 1 ~ " << listSize;
        throw illegalIndex(s.str());
    }
    chainNode<T> *currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;
    return currentNode->element;
}

template <class T>
int chain<T>::indexOf(const T &theElement) const
{ // 0 points to the first element
    chainNode<T> *currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL && currentNode->element != theElement)
    {
        currentNode = currentNode->next;
        index++;
    }
    if (currentNode == NULL)
        return -1;
    else
        return index;
}

template <class T>
void chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T> *deleteNode;
    if (theIndex == 0)
    {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        chainNode<T> *p = firstNode; //use this p to point to the prior element of chain.
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;
        deleteNode = p->next;
        p->next = p->next->next;
    }
    listSize--;
    delete deleteNode;
}

template <class T>
void chain<T>::insert(int theIndex, const T &theElement)
{
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "The index = " << theIndex << " must be in the 1 ~ " << listSize;
        throw illegalIndex(s.str());
    }

    if (theIndex == 0)
    {
        firstNode = new chainNode<T>(theElement, firstNode);
    }
    else
    {
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}

template <class T>
void chain<T>::output(ostream &out) const
{
    for (chainNode<T> *currentNode = firstNode;
         currentNode != NULL;
         currentNode = currentNode->next)
        out << currentNode->element << " ";
}

template <class T>
ostream &operator<<(ostream &out, const chain<T> &x)
{
    x.output(out);
    return out;
}
#endif