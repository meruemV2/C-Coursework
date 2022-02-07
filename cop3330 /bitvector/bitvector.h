//
// Created by Jerry on 6/10/20.
//

#ifndef BITVECTOR_BITVECTOR_H
#define BITVECTOR_BITVECTOR_H

#include <iostream>
using namespace std;

class BitVector {

public:
            BitVector();               // Default constructor 256 bits
            explicit BitVector (size_t s);    // construct a BitVector with specified size BitVector
            BitVector (const BitVector & a);  // Copy constructor
            ~BitVector();              // Destructor
            BitVector & operator =(const BitVector &a); // Assignment Operator
            void Set (const size_t index);        // Make index bit=1
            void Set ();               // Make all bits=1
            void Unset(const size_t index);  // Make index bit=0
            void Unset ();             // Make all bits=0
            void Flip (const size_t index);       // Flip index bit
            void Flip ();              // Flip all bits
            bool Test (size_t index) const;  // Return index bit value
            void Print();              // Prints index value and ascii value of bits turned on.

            size_t Size() const;            // Return size of bitvectorprivate;

private:
    int size;                       // Number of words
    int* bvect;               // Bit Vector dynamically
    int bitlocations;               // Current bit


};

#endif