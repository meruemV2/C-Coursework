//
// Created by Jerry Laplante on 03/20/21.
//

#ifndef COP4530ASSN5_HASHTABLE_H
#define COP4530ASSN5_HASHTABLE_H
// necessary includes
#include <sstream>
#include<iostream>
#include<stdio.h>
#include<list>
#include<fstream>
#include<functional>
#include<cctype>
#include<algorithm>
#include<vector>

using namespace std;
namespace cop4530
{
    static const unsigned int max_prime = 1301081; //max_prime is used by the helpful functions provided .
    static const unsigned int default_capacity = 11; //the default_capacity is used if the initial capacity of the underlying vector of the hash table is zero.
    template<typename K, typename V>
    class HashTable
    {
    public:

        explicit HashTable(size_t size = 101);
        ~HashTable(); // destructor. Delete all elements in hash table.
        bool contains(const K & k) const; //check if key k is in the hash table.
        bool match(const std::pair<K, V> &kv) const; //check if key-value pair is in the hash table. // CHECK FOR CONST, IS NEEDED
        bool insert(const std::pair<K, V> & kv); //add the key-value pair kv into the hash table.
        bool insert (std::pair<K, V> && kv); //move version of insert.
        bool remove(const K & k); //delete the key k and the corresponding value if it is in the hash table
        void clear(); //delete all elements in the hash table
        void size(size_t size);
        bool load(const char *filename);  //load the content of the file with name filename into the hash table
        bool write_to_file(const char *filename) const; // write all elements in hashtable into file with name filename
        void dump() const; //display all entries in the hash table. If an entry contains multipl key-value pairs, separate them by a semicolon character
        int size_() const; //return size of  hash table

    private:

        void makeEmpty(); //delete all elements in the hash table. The public interface clear() will call this function.
        void rehash(); //Rehash function. Called when the number of elements in the hash table is greater than the size of the vector.
        size_t myhash(const K &k) const; //return the index of the vector entry where k should be stored.
        //two helpful functions to determine the proper prime numbers used in setting up the vector size.
        unsigned long prime_below (unsigned long); //call prime_below to determine the new proper underlying vector size.
        void setPrimes(std::vector<unsigned long>&); // Whenever you need to set hash table to a new
        int numPairs; //num pairs
        vector<list<pair<K,V> > > myTupper;
    };

#include "hashtable.hpp"
}

#endif //COP4530ASSN5_HASHTABLE_H
