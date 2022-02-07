//
// Created/Modified by Jerry on 7/1/20.
//

#ifndef SIMPLEVECTOR_SIMPLEVECTOR_H
#define SIMPLEVECTOR_SIMPLEVECTOR_H
#include <iostream>
#include <new> // Needed for bad-alloc exception
#include <cstdlib> // Needed for the exit function

using namespace std;

template <class T>
class SimpleVector{
private:
    T *aptr; // To point to the allocated array
    int arraysize; // Number of elements in the array
    void memError(); // Handles memory allocation errors
    void subError(); // Handles subscripts out of range
public:
// Default constructor
    SimpleVector()
    {
     aptr = 0; arraysize = 0;
    }

// Constructor declaration
    SimpleVector(int);

// Copy Constructor declaration
    SimpleVector(const SimpleVector &a);

// Destructor - check to see if the size > zero.
    ~SimpleVector();

// Accessor to return the array size
   const int size() const;

// Accessor to return a specific element
   const T GetElementAt(int sub);

// Overload [] operator declaration
    T &operator[](const int &);
};

#endif //SIMPLEVECTOR_H

//Class SimpleVector implementation

//Constructor for SimpleVector

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    if(s<1) arraysize = 1;
    else arraysize = s;
    try {
        aptr = new T [arraysize];
        }
        catch (bad_alloc)
        {memError(); }

    for (int index = 0; index < arraysize; index++)
        aptr[index] = 0; //initiates values all to 0
}
// Copy Constructor declaration - allocate space first

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &a)
{
    arraysize = a.arraysize;
    aptr = new T[arraysize];

    for (int index = 0; index < arraysize; index++)
    {
        aptr[index] = a.aptr[index]; //copies contents of original values in to new vector
    }

}

// Destructor - check to see if the size > zero.

template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraysize < 1) //If size is not greater than zero, an error message will display
    {
        cout << "Error: No memory allocated for SimpleVector. Cannot delete." << endl;
    }
    else if (arraysize > 0)
    {
        delete []aptr; //frees up memory allocated for array
    }
}

// Accessor to return the array size
// * Function Name:  size
// * Description: return array size
// * Parameter Description: N/A
// * Date:  7/1/2020
// * Author: Jerry Laplante
// * References: Simple Vector Assignment & Video

template <class T>
const int SimpleVector<T>::size() const
{
    return arraysize; //returns array size
}

// Accessor to return a specific element
// * Function Name:  GetElementAt
// * Description: accesses the array subscript to display the value
// * Parameter Description: subscript is the index into the array
// * Date:  7/1/2020
// * Author: Jerry Laplante
// * References: Simple Vector Assignment & Video

template <class T>
const T SimpleVector<T>::GetElementAt(int sub)
{
    if (sub < 0 || (sub > (arraysize - 1)))
    {
        subError();
    }
    return aptr[sub]; //returns the actual element of any type by accessing subscript
}

// Overload [] operator declaration
// * Function Name: operator
// * Description: modifies the contents of the array using operator overloading
// * Parameter Description: index is how the function accesses the array subscript
// * Date:  7/1/2020
// * Author: Jerry Laplante
// * References: Simple Vector Assignment & Video
template <class T>
T& SimpleVector<T>::operator[](const int &index)
{
    if ((index < 0) || (index > (arraysize-1)))
    {
        subError();
    }
        return aptr[index];
}

//memError for SimpleVector
// * Function Name: memError
// * Description: displays error message when memory cannot be properly allocated
// * Parameter Description: N/A
// * Date:  7/1/2020
// * Author: Jerry Laplante
// * References: Simple Vector Assignment & Video
template <class T>
void SimpleVector<T>::memError()
{
    cout << "Error: cannot allocate memory." << endl;
    exit (EXIT_FAILURE);
}

//subError for SimpleVector
// * Function Name:  subError
// * Description: Displays error message when out of subscript bounds
// * Parameter Description: N/A
// * Date:  7/1/2020
// * Author: Jerry Laplante
// * References: Simple Vector Assignment & Video
template <class T>
void SimpleVector<T>::subError()
{
    cout << "Error: cannot allocate memory." << endl;
    exit (EXIT_FAILURE);
}