//
// Created by Jerry Laplante on 03/20/21.
//

#ifndef COP4530ASSN5_HASHTABLE_HPP
#define COP4530ASSN5_HASHTABLE_HPP
#include "hashtable.h"

// * Function Name:  Constructors
// * Description: hashtable constructors
// * Parameter Description: template parameters (generic data
//types) which represent the key and value types for a table entry
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos

template<typename K, typename V>
HashTable<K,V>::HashTable(size_t size)
{
    myTupper.resize(prime_below(size)); 	numPairs = 0;
}
// * Function Name:  Destructor
// * Description: hashtable destructor
// * Parameter Description: NN/A
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos
template<typename K, typename V>
HashTable<K,V>::~HashTable()
{
    clear();
}

template<typename K, typename V>
void HashTable<K,V>::size(size_t size)
{
    if(size_() != size)
    {
        myTupper.resize(prime_below(size));	 numPairs = 0;
    }
}

// * Function Name:  size_
// * Description: return number of pairs in the HashTable
// * Parameter Description: template parameters
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos
template<typename K, typename V>
int HashTable<K,V>::size_() const
{
    return numPairs;
}

// * Function Name:  contains
// * Description: checks if key k is in the hash table
// * Parameter Description: template parameters
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos and textbook
template<typename K, typename V>
bool HashTable<K,V>::contains(const K & k) const
{
    for(auto i= myTupper[myhash(k)].begin(); i!=myTupper[myhash(k)].end(); ++i)
    {
        if(i->first == k)
        {
            return true;
        }
    } return false;
}
// * Function Name: match
// * Description: check if key-value pair is in the hashtable
// * Parameter Description: template parameters
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos and textbook
template<typename K, typename V>
bool HashTable<K,V>::match(const std::pair<K,V> & kv) const
{
    auto &checkKeys = myTupper[myhash(kv.first)];

    return std::find(checkKeys.begin(),checkKeys.end(),kv)!=checkKeys.end();
}

// * Function Name: insert
// * Description: add the key-value pair kv into the hash table
// * Parameter Description: template parameters
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos, textbook, previous assignments
template<typename K, typename V>
bool HashTable<K,V>::insert(const std::pair<K,V> & kv_pair)
{
    if(contains(kv_pair.first))
    {
        auto &check = myTupper[myhash(kv_pair.first)];
        for(auto i=check.begin(); i != check.end(); ++i)
        {
            if(i->first == kv_pair.first)
            {
                auto replace = check.erase(i);
                check.insert(replace, kv_pair);
            }
        }return true;
    }
    else if(match(kv_pair))
    {
        return false;
    }
    else
    {
        myTupper[myhash(kv_pair.first)].push_back(kv_pair); //dynamic allocation of space
        if(++numPairs > myTupper.size())
        {
            rehash();
        }
        return true;
    }
}
// move function for above insert

template<typename K, typename V>
bool HashTable<K,V>::insert(std::pair<K,V> && kv)
{
    const std::pair<K,V> Pair = std::move(kv);	return insert(Pair);
}


// * Function Name: remove
// * Description: delete the key k and the corresponding value if it is in the hash table
// * Parameter Description: template parameters
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos, textbook, previous assignments
template<typename K, typename V>
bool HashTable<K,V>::remove(const K&k)
{
    auto &checkKeys=myTupper[myhash(k)];	bool r = false;
    for(auto i=checkKeys.begin(); i !=checkKeys.end(); ++i)
    {
        if(i->first == k)
        {
            i = checkKeys.erase(i);	--numPairs; //to update size
            r = true;
        }
    } return r;
}

// * Function Name: makeEmpty
// * Description: delete all elements in the hash table
// * Parameter Description: template parameters
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos, textbook, previous assignments
template<typename K, typename V>
void HashTable<K,V>::makeEmpty()
{
    for(auto &elements:myTupper)
    {
        myTupper.clear();
    }
    numPairs = 0;
}

template<typename K, typename V>
bool HashTable<K,V>::load(const char* filename)
{
    char c;
    std::pair<K,V> Pair;
    std::ifstream inFile;

    inFile.open(filename, std::ifstream::in);
    if(!inFile)
    {
        cout << filename << " is not valid..." << endl;
        return false;
    }

    while(inFile)
    {
        std::getline(inFile, Pair.first, ' ');

        while(isspace(inFile.peek()))  inFile.get(c); std::getline(inFile, Pair.second,'\n');
        while(isspace(inFile.peek()))  inFile.get(c);

        insert(Pair);
    }
    inFile.close();	return true;
}

template<typename K, typename V>
void HashTable<K,V>::dump() const
{
    for(int in = 0; in < myTupper.size(); in++)
    {
        cout << "v[" << in << "]:";

        if(!myTupper[in].empty())
            for(auto i = myTupper[in].begin(); i != myTupper[in].end(); ++i)
            {
                if(i != myTupper[in].begin())
                    cout << ':';
                cout << i->first << ' ' << i->second;
            }
        cout << endl;
    }
}

template<typename K, typename V>
bool HashTable<K,V>::write_to_file(const char* filename) const
{
    std::ofstream os;
    os.open(filename);

    if(!os)
    {
        return false;
    }

    for(int in=0; in<myTupper.size();in++)
    {
        for(auto i = myTupper[in].begin();i!=myTupper[in].end();++i)
        {
            os << i->first << ' ' << i->second << '\n';
        }
    }
    os.close();
    return true;
}

template<typename K, typename V>
void HashTable<K,V>::clear()
{
    makeEmpty();
}

template<typename K, typename V>
void HashTable<K,V>::rehash()
{
    auto tempOld=myTupper;
    myTupper.resize(prime_below(2 * myTupper.size()));

    for(auto & elements: myTupper) 	elements.clear();
    numPairs = 0;

    for(auto & elements: tempOld)
    {
        for(auto & Pair:elements) insert(move(Pair));
    }
}
template<typename K, typename V>
size_t HashTable<K,V>::myhash(const K & k) const
{
    static std::hash<K> tempHs;
    return tempHs(k) % myTupper.size();
}
// * Function Name: prime_below
// * Description: returns largest prime number <= n or zero if input is too large
// * Parameter Description: template parameters
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos
template <typename K, typename V>
unsigned long HashTable<K,V>::prime_below(unsigned long n)
{
    if(n > max_prime)
    {
        std::cerr << "input is too large for prime_below()\n";
        return 0;
    }
    if(n == max_prime)
    {
        return max_prime;
    }
    if(n <= 1)
    {
        std::cerr << "input is too small \n";
        return 0;
    }
    std::vector <unsigned long> v(n+1);
    setPrimes(v);
    while(n > 2)
    {
        if(v[n] == 1)
            return n;
        --n;
    }

    return 2;
}

template <typename K, typename V>
void HashTable<K,V>::setPrimes(std::vector<unsigned long>& vprimes)
{
    int i = 0;
    int j = 0;

    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();

    for(i = 2; i < n; ++i)
        vprimes[i] = 1;

    for(i = 2; i*i < n; ++i)
    {
        if(vprimes[i] == 1)
            for(j = i + i ; j < n; j += i)
                vprimes[j] = 0;
    }
}

#endif //COP4530ASSN5_HASHTABLE_HPP
