//
// Created by Jerry on 7/22/20.
//

#include "linklist.h"
#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

LinkList::LinkList() 			// Default constructor.
{
    head = new PieCake_struct;
    tail = new PieCake_struct;
    count = 0;
    head->id = -1;
    head->lname = "              ";
    head->next = tail;
    head->prev = nullptr;
    tail->next = nullptr;
    tail->id = 999999999;
    tail->lname = "zzzzzzzzzzzzzzzzzzzzzzzzz";
    tail->prev = head;
    count = 0;
}
LinkList::~LinkList()               	// Destructor
{
    if (Empty())
    {
        delete head;
        delete tail;
        count = 0;
        return;
    }
    PieCake_struct * search;
    search = head->next;
    while(search != tail)
    {
        current = search;
        search = search->next;
        delete current;
    }
    delete head;
    delete tail;
    count = 0;
}
bool LinkList::Empty() 			// True = link list is empty, False otherwise
{
    if(head->next == tail) return true;
    else return false;
}
int  LinkList::Size() 			// Returns number of records minus head and tail
{
    return count;
}
bool LinkList::Find(const int idnumber)   	            // Looks for a record with the id, returns true if
                                                        //   found, false otherwise. Sets the current to the
                                                        //   record found. Sets current to null if not found.
{
    current = head->next;

    while (current != tail)
    {
        if (idnumber == current->id)
         return true;
        else current = current->next;
    }
    return false;
}
void LinkList::Insert( PieCake_struct * p)  // Inserts a record into the list.
{
  PieCake_struct * search = head->next;
   count++;
   current = p;
   while (current->lname > search->lname)
       search = search->next;
   current->prev = search->prev;
   current->next = search;
   search->prev->next = current;
   search->prev = current;
}
bool LinkList::Delete()			// Deletes current record. Must use Find() to locate
//   the record.
{
    PieCake_struct * search = head->next;
    while(search != tail)
    {
        if (current->id == search->id)
        {
            search->prev->next = search->next;
            search->next->prev = search->prev;
            delete search;
            count--;
            return true;
        }
        search = search->next;
    }
    return false;
}
void LinkList::Print() 			// Prints the report..see example.
{

    if (Empty())
    {
        cout << "Empty List" <<endl;
        return;
    }
    PieCake_struct *search = head->next;

    cout << setw(45)<< "****** The CheeseCake Survey  ****" << endl;
    cout << setw(3) << "Id" << setw(13) << "Last Name" << setw(4)<< "MI" << setw(15)<< "First Name" << setw(10)<< "Sex" << setw(10)<< "Pie/Cake" << endl;
    cout << "----------------------------------------------------------" << endl;
    while (search != tail)
    {
        cout << setw(3) << search->id << setw(13) << search->lname << setw(4) << search->mi << setw(15) << search->fname << setw(10) << search->sex;
        if (search->pORc == 'C')
            cout << setw(10) <<"Cake" <<endl;
        if(search->pORc == 'P')
            cout << setw(10) << "Pie" <<endl;

        search = search->next;
    }
    cout << "Total Surveyed: " << count << endl;
    cout << "People who thought Cheesecake was Pie: " << CountPie() << endl;
    cout << "People who thought Cheesecake was Cake: " << CountCake() << endl;

}
void LinkList::List() 			// Lists current record to standard output. See Example.
//   Issues an error message of current is null.
{
    if (Empty())
    {
        cout << "Empty List" <<endl;
        return;
    }
    current = current->prev;
    cout << current->id << "  " << current->lname << "  " << current->mi << "  " << current->fname << "  " << current->sex << "  ";
    if (current->pORc == 'C')
        cout << "Cake" << endl;
    if (current->pORc == 'P')
        cout << "Pie" << endl;
}
int LinkList::CountPie()			// Returns number of records that thought Cheese Cake is
//   is Pie.
{
    PieCake_struct *search = head->next;
    int pie = 0;
    if (Empty())
    {
        cout << "Error: Empty list" << endl;
        return 0;
    }
    for (int i = 0; i <count; i++ )
    {
        if (search->pORc == 'P')
            pie++;
        search = search->next;
    }
    return pie;
}
int LinkList::CountCake()           	// Returns the number of records that thought Cheese Cake is Cake.
{
PieCake_struct *search = head->next;
    int cake = 0;
    if (Empty())
    {
        cout << "Error: Empty list" << endl;
        return 0;
    }
    for (int i = 0; i <count; i++ )
    {
        if (search->pORc == 'C')
            cake++;
        search = search->next;
    }
    return cake;
}
