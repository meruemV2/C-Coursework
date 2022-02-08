
#include "List.h"

#ifndef LIST_LIST_HPP
#define LIST_LIST_HPP

/*
 * List.hpp solution to Assignment for COP4530
 * Primary Author: Jerry Laplante
 * Code Examples and references obtained from
 * data Structure & Algorithm Analysis in C++ and
 * course lecture videos by Dr. David A. Gaitros
 */


//             CONST_ITERATOR

/*
 * const_iterator default constructor
 * creates const_iterator with a nullpointer that points to current
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
List<T>::const_iterator::const_iterator()
{
    current = nullptr;
}
/*
 * const_iterator protected one parameter constructor
 * creates iterator with a pointer to current
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
List<T>::const_iterator::const_iterator(typename List<T>::Node* p)
        : current{ p }
{
}
template <typename T>
/*
 * Retrieve
 * return the data in the current pointer
 * Jerry Laplante
 * Referenced from lecture videos
 */
T& List<T>::const_iterator::retrieve() const
{
    return this->current->data;
}

/*
 * operator*
 * operator function to return the element
 * being stored in current Node
 * Jerry Laplante
 * Referenced from lecture videos
 */
template<typename T>
const T & List<T>::const_iterator::operator*() const
{
    return retrieve();
}

/*
 * various operator functions to decrement and increment
 * iterator pre and post fix
 * Jerry Laplante
 * Referenced from textbook
 */
template<typename T>
typename List<T>::const_iterator & List<T>::const_iterator:: operator++ ( )
{
    current = current->next;
    return *this;
}
template<typename T>
typename List<T>::const_iterator List<T>::const_iterator:: operator++ (int)
{
    const_iterator old = *this;
    ++( *this );
    return old;
}
template<typename T>
typename List<T>::const_iterator & List<T>::const_iterator:: operator-- ( )
{
    current = current->prev;
    return *this;
}
template<typename T>
typename List<T>::const_iterator List<T>::const_iterator:: operator-- (int)
{
    const_iterator old = *this;
    --( *this );
    return old;
}

/*
 * Comparison operator functions
 * Jerry Laplante
 * Referenced from textbook
 */
template <typename T>
bool List<T>::const_iterator::operator==(const typename List<T>::const_iterator & rhs) const
{
    return current == rhs.current;
}
template <typename T>
bool List<T>::const_iterator::operator!=(const typename List<T>::const_iterator & rhs) const
{
    return !(*this == rhs);
}


//     ITERATOR

template<typename T>
List<T>::iterator::iterator()
{
}

/*
 * iterator class protected constructor
 * with one parameter
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
List<T>::iterator::iterator(typename List<T>::Node * p):
        List<T>::const_iterator::const_iterator{p}
{
}

template<typename T>
T & List<T>::iterator::operator*()
{
    return const_iterator::retrieve( );
}

template<typename T>
const T & List<T>::iterator::operator*() const
{
    return const_iterator::operator*( );
}

template<typename T>
typename List<T>::iterator & List<T>::iterator::operator++ ( )
{
    this->current = this->current->next;
    return *this;
}
template<typename T>
typename List<T>::iterator List<T>::iterator:: operator++ ( int )
{
    iterator old = *this; ++( *this );
    return old;
}
template<typename T>
typename List<T>::iterator & List<T>::iterator::operator-- ( )
{
    this->current = this->current->prev;
    return *this;
}
template<typename T>
typename List<T>::iterator List<T>::iterator:: operator-- ( int )
{
    iterator old = *this; --( *this );
    return old;
}



//                 LIST

template <typename T>
void List<T>:: init()
{
    theSize = 0;
    head = new List::Node;
    tail = new List::Node;
    head->next = tail;
    tail->prev = head;
}

/*
 * List constructor
 * uses init to generate empty linked list
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
List<T>::List()
{
    init();
}

/*
 * List copy constructor
 * uses init to generate empty linked list then
 * copies contents of separet linked list into it
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
List<T>::List(const List & rhs)
{
    init();
    for (auto & i : rhs)
    {
        push_back(i);
    }
}

/*
 * move constructor
 */
template <typename T>
List<T>::List(List && rhs)			// Move constructor
        : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
{
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

template <typename T>
List<T>::List(int num, const T& val )
{
    init();
    for (int i = 0; i < num; i++)
    {
        push_back(val);
    }
}

template <typename T>
List<T>::List(const_iterator start, const_iterator end)
{
    init();
    for (auto i = start; i != end; ++i)
    {
        push_back(*i);
    }
}



template<typename T>
List<T>::~List()
{
    clear();
    delete head;
    delete tail;
}

template <typename T>
const List<T>& List<T>::operator=(const List<T>& L)	// Copy assignment operator
{
    auto itr = L.top();
    for (int i = 0; i < L.size; i++)
    {
        push(itr.retrieve());
        itr++;
    }

    return *this;
}
template <typename T>
List<T>& List<T>:: operator=(List<T> && L) 	// Move assignment operator
{
    *this = L;

    return *this;
}



/*
 * size
 * returns size of linked list
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
int List<T>::size() const
{
   return theSize;
}

/*
 * Empty
 * checks to see if list is empty,
 * then returns true or false
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
bool List<T>::empty() const
{
    if(theSize == 0) return true;
    else return false;
}

/*
 * erase
 * uses iterator class to delete current node
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
typename List<T>::iterator List<T>::erase(iterator itr)
{
    Node * p = itr.current;
    List<T>::iterator retval(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;
    return retval;
}
template <typename T>
List<T>::List (std::initializer_list<T> iList)
{
    init();
    for(const auto& itr: iList)
    {
        push_back(itr);
    }
}

template<typename T>
List<T>& List<T>::operator=(std::initializer_list<T> iList)
{
    if( !empty())
    {
        clear();
        init();
    }
    for (auto &i : iList)
    {
        push_back(i);
    }
    return *this;
}


//to be edited

template<typename T>
void List<T>::reverse() // to reverse the order of elements if not empty
{
    for (iterator itr =  ----end(); itr != begin();)
    {
        push_back(*itr);
        itr = --erase(itr);
    }
    push_back(front());
    pop_front();
}
template<typename T> // first element
T & List<T>::front()
{
    return *begin();  // ref. iterator to first element
}
template<typename T>
const T & List<T>::front() const // now, w/ no permission to modify 1st elem.
{
    return *begin();
}
template<typename T> //  last element
T & List<T>::back()
{
    return *(--end());
}
template<typename T> // now, w/ no permission to modify last elem.
const T & List<T>::back() const
{
    return *(--end());
}
template<typename T>
void List<T>::push_front( T && val)
{
    insert(begin(), std::move( val));
}
// insert to the beginning right after head
template<typename T>
void List<T>::push_front(const T & val)
{
    insert(begin(), val);  // insert after Node head
}
template<typename T>
void List<T>::push_back(T && val) // move version insert_back
{
    insert( end(), std::move( val));
}
template<typename T>
void List<T>::pop_front() // delete first element
{
    erase(begin());
}
template<typename T>
void List<T>::clear()
{
    while(!empty())
        pop_back(); // to delete all the elements
}
// insert to the end, alias, insert right before Node* tail
template<typename T>
void List<T>::push_back(const T & val)
{
    insert(end(), val);
}
template<typename T>
void List<T>::pop_back()
{
    erase(--end()); // erase one element, the last one.
}

template<typename T>
template<typename PREDICATE>
void List<T>::remove_if(PREDICATE pred)	// remove all elements for which Predicate pred
{
    for(auto itr = begin(); itr != end(); ++itr)
    {
        if(pred(itr.retrieve()))
        {
            erase(itr);
        }
    }
}


template<typename T>
void List<T>::remove(const T & val) // remove all elements with value val
{
    for(auto itr = begin(); itr != end(); ++itr)
    {
        if(*itr == val)		erase(itr);
    }
}
template<typename T>
typename List<T>::iterator List<T>::begin()
{
        typename List<T>::iterator itr{head->next};
        return itr; // begining node (copy)
}
template<typename T>
typename List<T>::const_iterator List<T>::begin() const
{
        typename List<T>::const_iterator const_itr{head->next};
        return const_itr;
}
template<typename T>
typename List<T>::iterator List<T>::end()
{
    typename List<T>::iterator itr{ tail };
    return itr; // return the end node (copy)
}
template<typename T>
typename List<T>::const_iterator List<T>::end() const
{
    typename List<T>::const_iterator const_itr{tail};
    return const_itr;
}
/*
 * insert
 * inserts node into linked list
 * Jerry Laplante
 * Referenced from texbook
 */
template<typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator itr, const T & val)
{
    Node* p = itr.current;
    theSize++;
    return List<T>::iterator(p-> prev = p -> prev -> next  = new Node(val, p -> prev, p));
}
/*
 * insert
 * move version of insert function
 * Jerry Laplante
 * Referenced from lecture videos
 */
template<typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator itr, T && val) {
    Node* p = itr.current;
    theSize++;
    return List<T>::iterator(p-> prev = p -> prev -> next  = new Node(std::move(val), p -> prev, p));
}


template<typename T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator start, typename List<T>::iterator end)
{
    for(auto itr = start; itr != end;) // erase from start to end
        itr = erase(itr); //  not including end. Alias, erase [start, end)

    return end;
}



// overloading comparison
template<typename T>
bool operator!=(const List<T> & lhs, const List<T> & rhs)
{
    return !(lhs == rhs);
}
template<typename T>
bool operator==(const List<T> & lhs, const List<T> & rhs)
{
    bool flag = true;
    if( lhs.size() == rhs.size())
    {
        auto rhs_itr = rhs.begin();
        for(auto lhs_itr=lhs.begin(); lhs_itr !=lhs.end(); ++lhs_itr)
        {
            if(*lhs_itr != *rhs_itr)
            {
                flag = false; break;
            }

            ++rhs_itr;
        }
        return flag;
    }
    else
        return false;
}
// overloading output
template<typename T>
std::ostream & operator<<(std::ostream & os, const List<T> & l)
{
    l.print(os);	return os;
}
// print out all elements
template<typename T>
void List<T>::print(std::ostream & os, char ofc) const
{
    for (List<T>::const_iterator itr = begin(); itr != end();)
    {
        os << *itr;
        if (++itr != end())
            os << ofc;
    }
}

#endif