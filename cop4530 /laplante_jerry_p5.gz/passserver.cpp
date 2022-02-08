//
// Created by Jerry Laplante on 03/20/21.
//


#include "passserver.h"
#include "hashtable.h"
using namespace std;
using namespace cop4530;

// * Function Name:  constructor
// * Description: create a hash table of the specified size
// * Parameter Description: size of hashtable
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos and textbook
PassServer::PassServer(size_t size)
{
    hash_Table.size(size);
}

// * Function Name:  load
// * Description: load a password file into the HashTable object
// * Parameter Description: file name
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos and textbook

bool PassServer::load(const char* fn)
{
    return hash_Table.load(fn);
}

// * Function Name:  addUser
// * Description: add a new username and password
// * Parameter Description: username/pass pair
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos and textbook

bool PassServer::addUser(std::pair<string, string>&kv)
{
    string a = encrypt(kv.second);

    pair<string, string> dp2(kv.first,a);

    return hash_Table.insert(dp2);
}
// move version
bool PassServer::addUser(std::pair<string, string> && kv)
{
    pair<string, string> up2(std::move(kv));
    return addUser(up2);
}


// * Function Name:  removeUser
// * Description: delete an existing user with username k
// * Parameter Description: k is username
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos and textbook
bool PassServer::removeUser(const string & k)
{
    hash_Table.remove(k);
}

// * Function Name:  changePassword
// * Description: change an existing user's password.
// * Parameter Description: two pairs, old user/pass and new user/pass
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos and textbook
bool PassServer::changePassword(const pair<string, string> & p, const string & new_password)
{
    if(p.second == new_password)
    {
        return false;
    }
    else if(!hash_Table.contains(p.first))
    {
        return false;
    }
    else
    {
        string oldPassword = encrypt(p.second);
        string newPassword = encrypt(new_password);

        pair<string, string> vp(p.first, oldPassword);
        if(!hash_Table.match(vp))
        {
            return false;
        }
        else
        {
            pair<string, string> np(p.first, newPassword);
            hash_Table.insert(np); return true;
        }
    }
}

// * Function Name:  find
// * Description: check if a user exists (if user is in the hash table)
// * Parameter Description: user
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos and textbook
bool PassServer::find(const string & user) const
{
    return hash_Table.contains(user);
}

void PassServer::dump() const
{
    hash_Table.dump();
}

size_t PassServer::size() const
{
    hash_Table.size_();
}

bool PassServer::write_to_file(const char* filename) const
{
    hash_Table.write_to_file(filename);
}

PassServer::~PassServer()
{
    hash_Table.clear();
}
//Private functions

// * Function Name:  encrypt
// * Description: encrypt the parameter str and return the encrypted string
// * Parameter Description: string to be encrypted
// * Date:  03/20/21
// * Author: Jerry Laplante
// * References: Lecture videos and textbook
string PassServer::encrypt(const string & str)
{
    char arrsalt[] = "$1$########";
    string encryptedstring= crypt(str.c_str(), arrsalt);
    encryptedstring.replace(0, 12, "");
    return encryptedstring;
}