//
// Created by Jerry on 6/10/20.
//

#include "bitvector.h"
#include <iostream>
#include <vector>

using namespace std;

BitVector::BitVector()   : BitVector(256)
{
}              // Default constructor 256 bits
BitVector:: BitVector (size_t numbits)
{
    size = ((numbits + 31) / 32);

    bvect = new int (size);

    if (bvect == 0)
    {
        cout << "** BitVector memory allocation failure... Retry Program" << endl;
        exit (EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++)
    {
        bvect[i] = 0;
    }

}// construct a BitVector with specified size BitVector
BitVector::BitVector (const BitVector& a)
{
    size = a.size;
    bvect = new int (size);

    for (size_t i = 0; i < size; i++)
    {
        bvect[i] = a.bvect[i];
    }
}  // Copy constructor
BitVector::~BitVector()
{
    delete []bvect;

}// Destructor
BitVector& BitVector:: operator =(const BitVector &a)
{
    if (this != &a)
    {
        delete [] bvect;
        size = a.size;
        bvect = new int (size);
    }

    for (size_t i = 0; i < size; i++)
    {
        bvect[i] = a.bvect[i];
    }
    return *this;

}// Assignment Operator
void BitVector:: Set (const size_t index)
// * Function Name:  Set
// * Description: changes index bit to 1 value
// * Parameter Description: index holds the position of the bit to be changed
// * Date:  06/12/2020
// * Author: Jerry Laplante
// * References: BitVector Lecture & Notes
{
    size_t word;
    size_t offset;
    size_t mask = 1;

    word = (index / 32);
    offset = (index % 32);
    offset = (31 - offset);
    mask = mask << offset;

    if (word > size)
    { cout << "Error: Selected bit is out of range" << endl;
        return;
    }
    else
        bvect[word] = (bvect[word] | mask);
}// Make index bit=1
void BitVector:: Set ()
// * Function Name:  Set
// * Description: changes all bit to 1 value
// * Parameter Description: N/A
// * Date:  06/12/2020
// * Author: Jerry Laplante
// * References: BitVector Lecture & Notes
{
    for (size_t i = 0; i < size*32; i++)
    {
        size_t word;
        size_t offset;
        size_t mask = 1;

        word = (i / 32);
        offset = (i % 32);
        offset = (31 - offset);
        mask = mask << offset;

        bvect[word] = (bvect[word] | mask);
    }
}// Make all bits=1
void BitVector:: Unset(const size_t index)
// * Function Name:  Unset
// * Description: changes index bit to 0 value
// * Parameter Description: index holds the position of the bit to be changed
// * Date:  06/12/2020
// * Author: Jerry Laplante
// * References: BitVector Lecture & Notes
{
    if (Test(index))
    {
        Flip(index);
    }
    else return;

}// Make index bit=0
void BitVector::Unset ()
// * Function Name:  Unset
// * Description: changes index bit to 0 value
// * Parameter Description: index holds the position of the bit to be changed
// * Date:  06/12/2020
// * Author: Jerry Laplante
// * References: BitVector Lecture & Notes
{
    for (size_t i = 0; i < size*32; i++)
    {
        if (Test(i))
        {
            Flip(i);
        }
    }

}// Make all bits=0
void BitVector::Flip (const size_t index)
// * Function Name:  Flip
// * Description: flips index bit to opposite position
// * Parameter Description: index holds the position of the bit to be changed
// * Date:  06/12/2020
// * Author: Jerry Laplante
// * References: BitVector Lecture & Notes
{
    size_t word;
    size_t offset;
    size_t mask = 1;

    word = (index / 32);
    offset = (index % 32);
    offset = (31 - offset);
    mask = mask << offset;

    if (word > size)
    { cout << "Error: Selected bit is out of range" << endl;
        return;
    }
else
    bvect[word] = (bvect[word] ^ mask);

}// Flip index bit
void BitVector::Flip ()
// * Function Name:  Flip
// * Description: switches the value of all bits
// * Parameter Description: N/A
// * Date:  06/12/2020
// * Author: Jerry Laplante
// * References: BitVector Lecture & Notes
{
    for (size_t i = 0; i < size*32; i++)
    {
        size_t word;
        size_t offset;
        size_t mask = 1;

        word = (i / 32);
        offset = (i % 32);
        offset = (31 - offset);
        mask = mask << offset;

        bvect[word] = (bvect[word] ^ mask);
    }

}// Flip all bits
bool BitVector::Test (size_t index) const
// * Function Name:  Test
// * Description: boolean function that checks value of bits and returns true or false
// * Parameter Description: index holds the position of the bit to be checked
// * Date:  06/12/2020
// * Author: Jerry Laplante
// * References: BitVector Lecture & Notes
{
    size_t word;
    size_t offset;
    size_t mask = 1;

    word = (index / 32);
    offset = (index % 32);
    offset = (31 - offset);

    mask = mask << offset;

    mask = (bvect[word] & mask);

    if (mask !=0)return true;
        else return false;
}// Return index bit value
void BitVector::Print()
// * Function Name:  Print
// * Description: prints value (set or unset) of all bits in class
// * Parameter Description: N/A
// * Date:  06/12/2020
// * Author: Jerry Laplante
// * References: BitVector Lecture & Notes
{
    for (size_t index = 0; index < size*32; index++)
    {
        cout << index << " value is: ";
        if (Test(index)) cout << "set";
        else cout << "not set";
        cout << endl;
    }
}// Prints index value and ascii value of bits turned on.

size_t BitVector::Size() const
// * Function Name:  Size
// * Description: returns amount of bits being allocated for current class of bitvector
// * Parameter Description: N/A
// * Date:  06/12/2020
// * Author: Jerry Laplante
// * References: BitVector Lecture & Notes
{
    size_t bits = size*32;
    cout << bits << endl;

    return bits;
}// Return size of bitvectorprivate;


