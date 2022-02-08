//
// Created by Jerry Laplante on 03/20/21.
//

#ifndef COP4530ASSN5_PASSSERVER_H
#define COP4530ASSN5_PASSSERVER_H
#include "hashtable.h"
#include<unistd.h>
#include<stdlib.h>
#include<utility>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;
using namespace cop4530;

class PassServer  //implemented as an adaptor class, with the HashTable as the adaptee class.
{
public: //Public interfaces:

    PassServer(size_t size = 101); //constructor, create a hash table of the specified size.
    ~PassServer(); //destructor.
    bool load(const char* fn); //load a password file into the HashTable object
    bool addUser(std::pair<string, string> & kv); //add a new username and password
    bool addUser(std::pair<string, string> && kv); //move version of addUser.
    bool removeUser(const string & k); //delete an existing user with username k.
    bool changePassword(const pair<string, string> &p, const string & new_password); //an existing user's password.
    //return false if the new password and the old password are the same (i.e., we cannot update the password).
    bool find(const string & user) const; //check if a user exists (if user is in the hash table).
    void dump()  const; //show the structure and contents of the HashTable object to the screen.
    size_t size() const; //return the size of the HashTable (the number of username/password pairs in the table).
    bool write_to_file(const char* filename)  const; //save the username and password combination into a file

private: //Private interfaces:

    string encrypt(const string & str); //encrypt the parameter str and return the encrypted string.
    HashTable<string, string> hash_Table; //HashTable adaptor class
};

#endif //COP4530ASSN5_PASSSERVER_H
