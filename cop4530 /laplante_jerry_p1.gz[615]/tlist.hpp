

#ifndef TLIST_TLIST_HPP
#define TLIST_TLIST_HPP

#include <iostream>
#include <utility>
#include "tlist.h"

using namespace std;

template <typename T>
TList<T>::TList()				// Create empty linked list
{
   Init();

}

template <typename T>
void TList<T>::Init()   // used by constructors
{
    size = 0;
    first = last = nullptr;
}

template <typename T>
TList<T>::TList(T val, int num)		// Create list with num copies of val
{
    Init();

    for(int i = 0; i < num; i++)
    {
        InsertBack(val);
    }
}

template <typename T>
TList<T>::~TList()				// Destructor
{
    cout << "Destructor called..." << endl;
    if(IsEmpty())
    {
        return;
    }
    Clear();
    delete first;
    delete last;

}

template <typename T>
TList<T>::TList(const TList& L)		// Copy constructor
{
    Init();
    *this = L;
}

template <typename T>
TList<T>& TList<T>::operator=(const TList& L)	// Copy assignment operator
{
        TListIterator<T> itr = L.GetIterator();
        for (int i = 0; i < L.size; i++)
        {
            InsertBack(itr.GetData());
            itr.Next();
        }

   return *this;
}

template <typename T>
TList<T>::TList(TList && L)			// Move constructor
    : size{L.size}, first{L.first}, last{L.last}
{
    L.size = 0;
    L.first = nullptr;
    L.last = nullptr;
}

template <typename T>
TList<T>& TList<T>:: operator=(TList && L) 	// Move assignment operator
{
   *this = L;

   return *this;
}

template <typename T>
bool TList<T>::IsEmpty() const		// Checks to see whether list is empty
{
    return (first->next == last);
}

template <typename T>
void TList<T>::Clear()			    // Clear out list, reset to empty
{
    while (!IsEmpty())
    {
        RemoveFront();
    }
}

template <typename T>
int TList<T>::GetSize() const			// Return the size of the list
{
    return this->size;
}

template <typename T>
void TList<T>::InsertFront(const T& d)	// Insert data d as first element
{
    Node<T>* newNode = new Node<T>(d);
    if (last == nullptr)
    {
       first = last = newNode;
    }
    else
    {
        first->prev = newNode;
        newNode->next = first;
        first = newNode;
    }

    size++;
}

template <typename T>
void TList<T>::InsertBack(const T& d)		// Insert data d as last element
{
    Node<T>* newNode = new Node<T>(d);
    if (first == nullptr)
    {
        first = last = newNode;
    }
    else
    {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }

    size++; // Increase size of list
}

template <typename T>
void TList<T>::RemoveFront()			// Remove first element of list
{
    if(IsEmpty())
    {
        cout << "Error: List is empty" << endl;
    }

    Node<T>* oldNode = first->next;

    oldNode->prev->next = oldNode->next;
    oldNode->next->prev = oldNode->prev;

    delete oldNode;
    size--;
}

template <typename T>
void TList<T>::RemoveBack()			// Remove last element of list
{
    if(IsEmpty())
    {
        cout << "Error: list is empty" << endl;
    }

    else
    {
        Node<T>* oldNode = last;
        last = oldNode->prev;

        delete oldNode;

        size--;
    }

}

template <typename T>
T& TList<T>::GetFirst() const			// Return first element of list
{
    return first->data;
}

template <typename T>
T& TList<T>::GetLast() const			// Return last element of list
{
    return last->data;
}

template <typename T>
TListIterator<T> TList<T>::GetIterator() const    // Return iterator to first item
{
    TListIterator<T> itr;
    if(IsEmpty())
    {
        cout << "Error: empty list..." << endl;
    }
    else
    itr.ptr = this->first;

    return itr;
}

template <typename T>
TListIterator<T> TList<T>::GetIteratorEnd() const // Return iterator to last item
{
    TListIterator<T> itr;
    itr.ptr = this->last;
    return itr;
}
// **********************************************************
// * Insert data element d just before item at pos position *
// **********************************************************

template <typename T>
void TList<T>::Insert(TListIterator<T> pos, const T& d)
{
    Node<T>* newNode = new Node<T>(d);
    Node<T>* temp = new Node<T>(d);
    temp = pos.ptr->prev;
   if(IsEmpty())
   {
       first = last = newNode;
   }
   else if (pos.ptr->prev == nullptr)
   {
       first->prev = newNode;
       newNode->next = first;
       first = newNode;
   }
   else
   {
       newNode->next = pos.ptr;
       pos.ptr->prev = newNode;
       newNode->prev = temp;
       temp->next = newNode;
   }
   size++;
}
// **********************************************************
// * Remove data item at position pos. Return iterator      *
// *  to the item.                                          *
// *  that comes after the one being deleted.               *
// **********************************************************

template <typename T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos)
{
    Node<T> * p = pos.ptr;
    TListIterator<T> rv;
    rv.ptr = p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    size--;

    return rv;

}
// **********************************************************
// * Print list contents in order, separated by given       *
// * delimiter.                                             *
// **********************************************************

template <typename T>
void TList<T>::Print(std::ostream& os, char delim) const
{
    if(IsEmpty())
    {
        cout << "Error: List empty" <<endl;
    }
    Node<T>* p = first;
    for(int i = 0; i < size; i++)
   {
       cout << p->data << delim;
       p = p->next;
   }

}

template <typename T>
TListIterator<T>::TListIterator()			// default constructor
{
    ptr = nullptr;

}

template <typename T>
TList<T> operator+(const TList<T>& t1, const TList<T>& t2)
{
    TList<T>  newLink = TList<T>();

    TListIterator<T> d = t1.GetIterator();
    for (int i = 0; i < (t1.GetSize()); i++)
    {
        newLink.InsertBack(d.GetData());
        d.Next();
    }
    d = t2.GetIterator();
    for (int i = 0; i < (t2.GetSize()); i++)
    {
        newLink.InsertBack(d.GetData());
        d.Next();
    }
   return newLink;
}

template <typename T>
bool TListIterator<T>::HasNext() const	// next item available?
{
    if(ptr == nullptr)
        return false;
    else if (ptr->next == nullptr)
        return false;
    else
        return true;
}

template <typename T>
bool TListIterator<T>::HasPrevious() const		// previous item available?
{
    if(ptr == nullptr)
        return false;
    else if (ptr->prev == nullptr)
        return false;
    else
        return true;
}

template <typename T>
TListIterator<T> TListIterator<T>::Next()		// advance to next item
{
    if (HasNext())
    {
        ptr = ptr->next;
    }
    return *this;
}

template <typename T>
TListIterator<T> TListIterator<T>::Previous()		// move to previous item
{
    if(HasPrevious())
    {
        ptr = ptr->prev;
    }
    return *this;
}

template <typename T>
T& TListIterator<T>::GetData() const			// return data element of current node
{
    return ptr->data;
}








#endif //TLIST_TLIST_HPP
