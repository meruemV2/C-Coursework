//
// Created by Jerry Laplante
//

#ifndef ASSIGNMENT4_BET_H
#define ASSIGNMENT4_BET_H
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

class BET
{
    struct BinaryNode{		// BinaryNode struct
        string data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const string & d = string{}, BinaryNode *l = nullptr, BinaryNode *r = nullptr) : data{d}, left{l}, right{r} {}
    };

public:
    BET();										 // default constructor
    BET(const string postfix);					 // constructor of postfix expression tree
    BET(const BET&);							 // copy constructor
    ~BET();										 // destructor
    bool buildFromPostfix(const string& postfix); // build tree from postfix expression
    const BET & operator=(const BET &);			 // assignment operator
    void printInfixExpression();				 // print infix
    void printPostfixExpression();				 // print postfix
    size_t size();								 // return nodes in the tree
    size_t leaf_nodes();						 // return the number of leafs
    bool empty();								 // return true if empty

private:
    void printInfixExpression(BinaryNode *n);	 // print infix expression
    void makeEmpty(BinaryNode* &t);				 // delete nodes in subtree t
    BinaryNode * clone(BinaryNode *t) const;	 // clone all nodes for t
    void printPostfixExpression(BinaryNode *n);  // print postfix
    size_t size(BinaryNode *t);					 // returns number of nodes in t
    size_t leaf_nodes(BinaryNode *t);			 // return number of leaf inn t
    BinaryNode *st;							 // beginning of tree
};

#include "bet.hpp"
#endif //ASSIGNMENT4_BET_H
