#include<iostream>
#include<utility>
#include<stdio.h>
#include "passserver.h"
#include "hashtable.h"
using namespace std;
// Created by Jerry Laplante on 03/20/21.

void Menu()
{
    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice : ";
}

void jump();
void Menu();

int main()
{
    cout << "Enter a hash table size to begin...: ";
    int inSize; cin >> inSize;

    if(inSize <= 0)
    {
        cout <<"Input too large \nSet to default capacity \n11\n";
        inSize = 11;
    }

    PassServer x(inSize);
    char inp;
    do
    {
        Menu();
        cin >> inp;

        if(inp == 'l')
        {
            string filename;
            cout <<"Enter password file name to begin load process: ";
            jump();
            getline(cin, filename);

            if(!x.load(filename.c_str()))
            {
                cout << "Cannot load file...: " << filename << endl;
            }
        }

        else if(inp == 'a')
        {
            string name, adduser;
            cout << "Enter username: ";
            jump();
            getline(cin, name);
            cout << "Enter password: \n";
            jump();
            getline(cin, adduser);
            pair<string, string> newPair(name, adduser);

            if(x.addUser(newPair))
            {
                cout << "User " << name << " was added.\n";
            }
            else
            {
                cout << "Error: User already exists. Could not duplicate user...\n";
            }
        }

        else if(inp == 'r')
        {
            string name;
            cout << "Enter a username: ";
            jump();
            getline(cin, name);
            if(x.removeUser(name))
            {
                cout << "User " << name << " deleted.\n";
            }
            else
            {
                cout << "Error: User was not found to be deleted..\n";
            }
        }

        else if(inp == 'c')
        {
            string name, old_p, new_p;
            cout << "Enter username: ";    jump();
            getline(cin, name);
            cout << "Enter password: \n";    jump();
            getline(cin, old_p);
            cout << "Enter new password: "; jump();
            getline(cin, new_p);

            pair<string, string> oldPair(name, old_p);

            if(x.changePassword(oldPair, new_p))
            {
                cout << "Password for " << name << " was changed..." << '\n';
            }
            else
            {
                cout << "Error: Unable to change user password." << endl;
            }
        }

        else if(inp == 'f')
        {
            string name;
            cout << "Enter username: "; jump();
            getline(cin, name);

            if(x.find(name))
            {
                cout << "User: " << "'" << name << "'" << " found!\n";
            }
            else
            {
                cout << "User: " << "'" << name << "'" << " was unable to be found.." << endl;
            }
        }

        else if(inp == 'd')
        {
            x.dump();
        }

        else if(inp == 's')
        {
            cout << "Size of current hashtable: " << x.size();
            cout << '\n';
        }

        else if(inp == 'w')
        {
            string secName;
            cout << "Please name password file: "; jump();

            getline(cin, secName);
            x.write_to_file(secName.c_str());
        }

        else if(inp == 'x')
        {
           cout << "Goodbye :)" << endl;
        }

        else
        {
            cout << "Error: Invalid input..." << endl;
        }
    }
    while(inp != 'x');

    return 0;
}


void jump()
{
    char j;

    while(isspace(cin.peek()) && !cin.eof())
    {
        cin.get(j);
    }
}
