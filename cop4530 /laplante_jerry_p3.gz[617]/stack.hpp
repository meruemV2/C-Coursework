#include "stack.h"

#ifndef COP4530_ASSIGNMENT3_STACK_HPP
#define COP4530_ASSIGNMENT3_STACK_HPP



//             CONST_ITERATOR

/*
 * const_iterator default constructor
 * creates const_iterator with a nullpointer that points to current
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
Stack<T>::const_iterator::const_iterator()
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
Stack<T>::const_iterator::const_iterator(typename Stack<T>::Node* p)
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
T& Stack<T>::const_iterator::retrieve() const
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
const T & Stack<T>::const_iterator::operator*() const
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
typename Stack<T>::const_iterator & Stack<T>::const_iterator:: operator++ ( )
{
    current = current->next;
    return *this;
}
template<typename T>
typename Stack<T>::const_iterator Stack<T>::const_iterator:: operator++ (int)
{
    const_iterator old = *this;
    ++( *this );
    return old;
}
template<typename T>
typename Stack<T>::const_iterator & Stack<T>::const_iterator:: operator-- ( )
{
    current = current->prev;
    return *this;
}
template<typename T>
typename Stack<T>::const_iterator Stack<T>::const_iterator:: operator-- (int)
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
bool Stack<T>::const_iterator::operator==(const typename Stack<T>::const_iterator & rhs) const
{
    return current == rhs.current;
}
template <typename T>
bool Stack<T>::const_iterator::operator!=(const typename Stack<T>::const_iterator & rhs) const
{
    return !(*this == rhs);
}


//     ITERATOR

template<typename T>
Stack<T>::iterator::iterator()
{
}

/*
 * iterator class protected constructor
 * with one parameter
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
    Stack<T>::iterator::iterator(typename Stack<T>::Node * p):
            Stack<T>::const_iterator::const_iterator{p}
{
}

template<typename T>
T & Stack<T>::iterator::operator*()
{
    return const_iterator::retrieve( );
}

template<typename T>
const T & Stack<T>::iterator::operator*() const
{
    return const_iterator::operator*( );
}

template<typename T>
typename Stack<T>::iterator & Stack<T>::iterator::operator++ ( )
{
    this->current = this->current->next;
    return *this;
}
template<typename T>
typename Stack<T>::iterator Stack<T>::iterator:: operator++ ( int )
{
    iterator old = *this; ++( *this );
    return old;
}
template<typename T>
typename Stack<T>::iterator & Stack<T>::iterator::operator-- ( )
{
    this->current = this->current->prev;
    return *this;
}
template<typename T>
typename Stack<T>::iterator Stack<T>::iterator:: operator-- ( int )
{
    iterator old = *this; --( *this );
    return old;
}



//                 Stack

template <typename T>
void Stack<T>:: init()
{
    theSize = 0;
    head = new Stack::Node;
    tail = new Stack::Node;
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
Stack<T>::Stack()
{
    init();
}

/*
 * List copy constructor
 * uses init to generate empty linked list then
 * copies contents of separet linkned list into it
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
Stack<T>::Stack(const Stack & rhs)
{
    init();
    for (auto & i : rhs)
    {
        push(i);
    }
}

/*
 * move constructor
 */
template <typename T>
Stack<T>::Stack(Stack && rhs)			// Move constructor
        : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
{
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}



template<typename T>
Stack<T>::~Stack()
{
    clear();
    delete head;
    delete tail;
}

/*
 * size
 * returns size of linked list
 * Jerry Laplante
 * Referenced from lecture videos
 */
template <typename T>
int Stack<T>::size() const
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
bool Stack<T>::empty() const
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
typename Stack<T>::iterator Stack<T>::erase(iterator itr)
{
    Node * p = itr.current;
    Stack<T>::iterator retval(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;
    return retval;
}


//to be edited

template<typename T> // first element
T & Stack<T>::top()
{
    return *begin();  // ref. iterator to first element
}
template<typename T>
const T & Stack<T>::top() const // now, w/ no permission to modify 1st elem.
{
    return *begin();
}

template<typename T>
void Stack<T>::push( T && val)
{
    insert(begin(), std::move( val));
}
// insert to the beginning right after head
template<typename T>
void Stack<T>::push(const T & val)
{
    insert(begin(), val);  // insert after Node head
}

template<typename T>
void Stack<T>::pop() // delete first element
{
    erase(begin());
}
template<typename T>
void Stack<T>::clear()
{
    while(!empty())
        pop(); // to delete all the elements
}
// insert to the end, alias, insert right before Node* tail

template<typename T>
typename Stack<T>::iterator Stack<T>::begin()
{

        typename Stack<T>::iterator itr{head->next};
        return itr; // begining node (copy)

}
template<typename T>
typename Stack<T>::const_iterator Stack<T>::begin() const
{

        typename Stack<T>::const_iterator const_itr{head->next};
        return const_itr;

}
template<typename T>
typename Stack<T>::iterator Stack<T>::end()
{
    typename Stack<T>::iterator itr{ tail };
    return itr; // return the end node (copy)
}
template<typename T>
typename Stack<T>::const_iterator Stack<T>::end() const
{
    typename Stack<T>::const_iterator const_itr{tail};
    return const_itr;
}
/*
 * insert
 * inserts node into linked list
 * Jerry Laplante
 * Referenced from texbook
 */
template<typename T>
typename Stack<T>::iterator Stack<T>::insert(typename Stack<T>::iterator itr, const T & val)
{
    Node* p = itr.current;
    theSize++;
    return Stack<T>::iterator(p-> prev = p -> prev -> next  = new Node(val, p -> prev, p));
}
/*
 * insert
 * move version of insert function
 * Jerry Laplante
 * Referenced from lecture videos
 */
template<typename T>
typename Stack<T>::iterator Stack<T>::insert(typename Stack<T>::iterator itr, T && val) {
    Node* p = itr.current;
    theSize++;
    return Stack<T>::iterator(p-> prev = p -> prev -> next  = new Node(std::move(val), p -> prev, p));
}


template <typename T>
Stack<T>::Stack (std::initializer_list<T> iList)
{
    init();
    for(const auto& itr: iList)
    {
        push(itr);
    }
}

template<typename T>
Stack<T>& Stack<T>::operator=(std::initializer_list<T> iList)
{
    if( !empty())
    {
        clear();
        init();
    }
    for (auto &i : iList)
    {
        push(i);
    }
    return *this;
}

template <typename T>
const Stack<T>& Stack<T>::operator=(const Stack<T>& L)	// Copy assignment operator
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
Stack<T>& Stack<T>:: operator=(Stack<T> && L) 	// Move assignment operator
{
    *this = L;

    return *this;
}


// overloading comparison
template<typename T>
bool operator!=(const Stack<T> & lhs, const Stack<T> & rhs)
{
    return !(lhs == rhs);
}
template<typename T>
bool operator==(const Stack<T> & lhs, const Stack<T> & rhs)
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
std::ostream & operator<<(std::ostream & os, const Stack<T> & l)
{
    l.print(os);	return os;
}
// print out all elements
template<typename T>
void Stack<T>::print(std::ostream & os, char ofc) const
{
    for (Stack<T>::const_iterator itr = begin(); itr != end();)
    {
        os << *itr;
        if (++itr != end())
            os << ofc;
    }
}



#endif //COP4530_ASSIGNMENT3_STACK_HPP
