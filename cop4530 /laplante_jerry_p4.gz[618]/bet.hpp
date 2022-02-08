//
// Created by Jerry Laplante on 12/10/20.
//
#include "bet.h"

#ifndef ASSIGNMENT4_BET_HPP
#define ASSIGNMENT4_BET_HPP
bool isOperand(string expression);
int checkPrecedence(string expression);

BET::BET(){ // default constructor
    st = new BinaryNode;
}

BET::BET(const string postfix){ // constructor from postfix
    st = new BinaryNode;
    buildFromPostfix(postfix);
}

BET::BET(const BET& x){ // copy constructor
    st = clone(x.st);
}

BET::~BET(){ // destructor
    makeEmpty(st);
}

bool BET::buildFromPostfix(const string& postfix){ // build tree from postfix
    string temp;
    string temp2;
    stack<BinaryNode*> myStack;
    stringstream s(postfix);

    int counter1 = 0;
    int counter2 = 0;

    if(postfix.empty() == true){
        cout << "Wrong postfix expression" << endl;
        st = nullptr;
        return false;
    }

    if(empty() == false)
        makeEmpty(st);

    bool flag = false;

    while(s >> temp){ // take input

        BinaryNode *myNode = new BinaryNode(temp); // create a node for user input

        if(isOperand(temp) == true){ // take all operands in and pushs to stack
            counter1++;
            myStack.push(myNode);	// push new node
        }
        else if(checkPrecedence(temp) != 0){
            counter2++;
            if(counter1 == counter2){
                cout << "Wrong postfix expression" << endl;
                st = nullptr;
                return false;
            }
            else{
                myNode->left = myStack.top();
                myStack.pop();
                myNode->right = myStack.top();
                myStack.pop();
                myStack.push(myNode);
            }
        }
    }

    if(counter1 != counter2)
        st = myStack.top();

    if(myStack.empty() == true){ // check if empty
        cout << "Wrong postfix expression" << endl;
        st = nullptr;
        return false;
    }

    return true;
}

const BET & BET::operator=(const BET & x){ // assignment operator
    st = clone(x.st);
    return *this;
}

void BET::printInfixExpression(){ // print infix form
    printInfixExpression(st);
    cout << endl;
}

void BET::printPostfixExpression(){ // print postfix
    printPostfixExpression(st);
    cout << endl;
}

size_t BET::size(){ // return the number of nodes
    return (size(st));
}

size_t BET::leaf_nodes(){  // return number of leaf nodes
    return (leaf_nodes(st));
}
bool BET::empty(){ // return true if empty
    if(st == nullptr)
        return true;
    return false;
}

void BET::printInfixExpression(BinaryNode *n){ // print infix
    bool closeParentheses = false;

    if(n != nullptr){
        if(n->left == nullptr && n->right == nullptr)
            cout << n->data << " ";
        else{
            if(checkPrecedence(n->data) != 0 && checkPrecedence(n->right->data) != 0){	// operator test
                if(checkPrecedence(n->data) >= checkPrecedence(n->right->data)){
                    if(checkPrecedence(n->data) == 2){
                        cout << "( ";
                        closeParentheses = true;
                    }
                }
            }

            printInfixExpression(n->right);

            if(closeParentheses == true)
                cout << ") ";
            closeParentheses = false; // sets to false

            cout << n->data << " ";
            if(checkPrecedence(n->data) != 0 && checkPrecedence(n->left->data) != 0){	// test presence of operator then print left side
                if(checkPrecedence(n->data) >= checkPrecedence(n->left->data)){
                    cout << "( ";
                    closeParentheses = true;
                }
            }

            printInfixExpression(n->left);
            if(closeParentheses == true)
                cout << ") ";
        }
    }
}

void BET::makeEmpty(BinaryNode* &t){ // deletes nodes in t
    if(t != nullptr){ // check if empty
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
}

BET::BinaryNode * BET::clone(BinaryNode *t) const{ // clones all nodes of t
    if(t == nullptr)
        return nullptr;
    else
        return new BinaryNode(t->data, clone(t->left), clone(t->right));
}

void BET::printPostfixExpression(BinaryNode *n){ // print postfix
    if(size(n) == 0) // check if empty
        return;
    else if(st->left == nullptr && st->right == nullptr)
        cout << st->data << endl;
    else{
        printPostfixExpression(n->right);
        printPostfixExpression(n->left);
        cout << n->data << " ";
    }
}

size_t BET::size(BinaryNode *t){ // returns t's number of nodes
    if(t == nullptr)
        return 0;
    else
        return(size(t->left) + size(t->right) + 1);
}

size_t BET::leaf_nodes(BinaryNode *t){ // return t's number of leaves
    if(t == nullptr)
        return 0;
    else if((t->left == nullptr) && (t->right == nullptr))
        return 1;
    else
        return (leaf_nodes(t->left) + leaf_nodes(t->right));
}

bool isOperand(const string str){
    for(int i = 0; i < int(str.size()); i++)
        if(isalnum(str[i]) == false)
            return false;
    return true;
}

int checkPrecedence(const string str){ // check precedence o
    if(str == "("|| str == ")")
        return (3);
    else if(str == "*" || str == "/")
        return (2);
    else if(str == "+" || str == "-")
        return (1);
    else
        return 0;
}
#endif //ASSIGNMENT4_BET_HPP
