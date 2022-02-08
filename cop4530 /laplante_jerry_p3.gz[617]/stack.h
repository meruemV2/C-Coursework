#ifndef COP4530_ASSIGNMENT3_STACK_H
#define COP4530_ASSIGNMENT3_STACK_H


#include <iostream>
#include <utility>
#include <initializer_list>

namespace cop4530 {

    template<typename T>
    class Stack {
    private:
        // nested Node class
        struct Node {
            T data;
            Node *prev;
            Node *next;

            Node(const T &d = T{}, Node *p = nullptr, Node *n = nullptr)
                    : data{d}, prev{p}, next{n} {}

            Node(T &&d, Node *p = nullptr, Node *n = nullptr)
                    : data{std::move(d)}, prev{p}, next{n} {}
        };

    public:
        //nested const_iterator class
        class const_iterator {
        public:
            const_iterator();            // default zero parameter constructor
            const T &operator*() const; // operator*() to return element

            // increment/decrement operators
            const_iterator &operator++();

            const_iterator operator++(int);

            const_iterator &operator--();

            const_iterator operator--(int);

            // comparison operators
            bool operator==(const const_iterator &rhs) const;

            bool operator!=(const const_iterator &rhs) const;

        protected:
            Node *current;              // pointer to node in List
            T &retrieve() const;       // retrieve the element refers to
            const_iterator(Node *p);    // protected constructor

            friend class Stack<T>;
        };

        // nested iterator class
        class iterator : public const_iterator {
        public:
            iterator();

            T &operator*();

            const T &operator*() const;

            // increment/decrement operators
            iterator &operator++();

            iterator operator++(int);

            iterator &operator--();

            iterator operator--(int);

        protected:
            iterator(Node *p);

            friend class Stack<T>;
        };

    public:
        // constructor, desctructor, copy constructor
        Stack();                  // default zero parameter constructor
        Stack(const Stack &rhs);   // copy constructor
        Stack(Stack &&rhs);       // move constructor
        ~Stack(); // destructor

        // copy assignment operator
        const Stack &operator=(const Stack &rhs);

        // move assignment operator
        Stack &operator=(Stack &&rhs);


        // member functions
        int size() const;       // number of elements
        bool empty() const;     // check if list is empty
        void clear();           // delete all elements

        T &top();             // reference to the first element
        const T &top() const;

        void push(const T &val); // insert to the beginning
        void push(T &&val);      // move version of insert
        void pop();               // delete first element

        Stack &operator=(std::initializer_list<T> iList);

        Stack(std::initializer_list<T> iList);

        // print out all elements. ofc is deliminitor
        void print(std::ostream &os, char ofc = ' ') const;

        iterator begin();               // iterator to first element
        const_iterator begin() const;

        iterator end();                 // end marker iterator
        const_iterator end() const;

        iterator insert(iterator itr, const T &val);  // insert val ahead of itr
        iterator insert(iterator itr, T &&val);      // move version of insert
        iterator erase(iterator itr);                 // erase one element


    private:
        int theSize;           // number of elements
        Node *head;            // head node
        Node *tail;            // tail node

        void init();           // initialization
    };

    // overloading comparison operators
    template<typename T>
    bool operator==(const Stack<T> &lhs, const Stack<T> &rhs);

    template<typename T>
    bool operator!=(const Stack<T> &lhs, const Stack<T> &rhs);

    // overloading output operator
    template<typename T>
    std::ostream &operator<<(std::ostream &os, const Stack<T> &l);


#include "stack.hpp"

}

#endif //COP4530_ASSIGNMENT3_STACK_H
