// Created by David A Gaitros on 10/15/19.
// Modified by Jerry Laplante on 07/16/20
// ******************************************************************** 
// * Name: Stack Class                                                * 
// * Description:  A template Stack class designed to be used with    * 
// *   any simple C++ type to include floating point, double          * 
// *   floating point, character, and boolan.                         * 
// *   The stack pointer, as is the convention, points to the last    * 
// *   or highest element in the array. So if you allocate 100        * 
// *   elements of type "T" then the first empty element will be 99.  * 
// * Author: Dr. David A. Gaitros                                     * 
// * Date: January 19, 2019                                           * 
// ******************************************************************** 
#include <iostream>
#include <new>
using namespace std;

const int DEFAULTSIZE = 100;

template <class T>
class Stack{

private:
    T *_stack;                 // The "stack"
    int _size;                  // The number of elements the stack can hold
    int _top;                   // Points to the first empty node

public:
    Stack()                  // Default Constructor, stack is size 100.
    {
        _size = DEFAULTSIZE;
        _stack = new T [_size];
        _top = _stack[_size - 1];
    };
    Stack(const int);      // Constructor, creates stack of size "size"

    Stack(const Stack<T> & item);// Copy constructor

    ~Stack();                // Destructor
    bool Full();                // Return true if the stack is full
    bool Empty();               // Return true if the stack is empty
    int Size();                 // Return the size of the stack
    T Top();                    // Returns the top element, does not pop it.
    bool Push (const T item);   // Put an item on the stack.
    bool Pop();                 // Pop an item off and display to std out

    // * Function Name:  ostream operator
// * Description: checks to see if stack is empty and if not
// * it brings that item to the ostream and displays it then decrements the stack by one
// * Parameter Description: << operator and the Stack of type T
// * Date:  7/16/2020
// * Author: Jerry Laplante
// * References: Simple Stack Video
   friend ostream &operator <<(ostream & os, Stack<T> &s)
   {
       if (s.Empty())
           cout << "Error: " << endl;

       else
       {
           T item;
           item = s._stack[--s._top];
          os << item;

       }
       return os;
      // Place the code to test to see if the stack is empty and
      // if so send an error message out to the os ;
     //  If the stack is not empty, return the top item to the os and
     //  have it function the same way as the Pop() member function.
   };

};

template <class T>
Stack<T>::Stack(const int s)
{
    if(s<1) _size = 1;
    else _size = s;

    try {
        _stack = new T [_size];
        }
        catch (bad_alloc)
        {
            cout << "Error " << endl;
        }

}

template <class T>
Stack<T>::Stack(const Stack<T> &item)
{
    _size = item._size;
    _stack = new T [_size];
    _top = _stack[_size - 1];
}
template <class T>
Stack<T>::~Stack()
{
    if (Empty())
    {
        cout << "Error: Stack is empty..." << endl;
    }
    else
    {
        delete []_stack;
    }
}
// * Function Name:  Full
// * Description: boolean function to determin if stack is full
// * Parameter Description: N/A
// * Date:  7/16/2020
// * Author: Jerry Laplante
// * References: Simple Stack Video
template <class T>
bool Stack<T>::Full()
{
    if (_top == _size) return true;
    else return false;

}
// * Function Name:  Empty
// * Description: boolean function to determin if stack is empty
// * Parameter Description: N/A
// * Date:  7/16/2020
// * Author: Jerry Laplante
// * References: Simple Stack Video
template <class T>
bool Stack<T>::Empty()
{
    if (_top == 0) return true;
    else return false;
}
// * Function Name:  Size
// * Description: returns private data member size
// * Parameter Description: N/A
// * Date:  7/16/2020
// * Author: Jerry Laplante
// * References: Simple Stack Video
template <class T>
int Stack<T>::Size()
{
    return _size;
}
// * Function Name:  Top
// * Description: returns private data member Top
// * Parameter Description: N/A
// * Date:  7/16/2020
// * Author: Jerry Laplante
// * References: Simple Stack Video
template <class T>
T Stack<T>::Top()
{
    return _top;
}
// * Function Name:  Push
// * Description: boolean function that determines if stack is full
// * and if not full it will input parameter onto top of stack
// * Parameter Description: item is of type T because this is a template class
// * Date:  7/16/2020
// * Author: Jerry Laplante
// * References: Simple Stack Video
template <class T>
bool Stack<T>::Push(const T item)
{
    if(!Full())
    {
        _stack[_top++] = item; return true;
    }
    else return false;
}
// * Function Name:  Pop
// * Description: boolean function that determines if stack is empty and if not
// * it will decrement the stack by one and display the value that was freed up in memory
// * Parameter Description: N/A
// * Date:  7/16/2020
// * Author: Jerry Laplante
// * References: Simple Stack Video
template <class T>
bool Stack<T>::Pop()
{
    T value;
    if(Empty()) return false;

    else
    {
        value = _stack[--_top];
        cout << value << endl;
        return true;
    }

}