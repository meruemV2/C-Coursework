#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include "stack.h"

using namespace std;
using namespace cop4530;

bool IsInteger(const string instr);
bool IsFloat(const string instr);
bool IsIdentifier(const string instr);
bool IsOperator(const string instr);
float StringToFloat(const string instr);
int Precedence (string instr);
float EvaluationOfExpression(const string postfix);
bool BalancedParens(const string instr);
bool CanBeEvaluated(const string instr);
void GetPostFixNotation(const string test);


bool IsInteger(const string instr)
{
    if(instr.empty() || ((!isdigit(instr[0])) && (instr[0] != '-') && (instr[0] != '+'))) return false;

    char * p;
    strtol(instr.c_str(), &p, 10);

    return (*p == 0);
}
bool IsFloat(const string instr)
{
    istringstream iss(instr);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}
bool IsIdentifier(const string instr)
{
    if( (instr >= "a" && instr <= "z") ||
            (instr >= "A" && instr <= "Z"))
    {
        return true;
    }
    else return false;
}
bool IsOperator(const string instr)
{
    return ((instr == "*") || (instr == "/") || (instr == "+") || (instr == "-") || (instr == "^"));
}
float StringToFloat(const string instr)
{
    float num = std::stof(instr);
    return num;
}
int Precedence (string instr)
{
    if(instr == "^")
        return 3;
    else if(instr == "*" || instr == "/")
        return 2;
    else if(instr == "+" || instr == "-")
        return 1;
    else
        return -1;
}

bool BalancedParens(const string instr)
{

    Stack<char>  S;
    for(int i =0;i<instr.length();i++)
    {
        if(instr[i] == '(' || instr[i] == '{' || instr[i] == '[')
            S.push(instr[i]);
        else if(instr[i] == ')' || instr[i] == '}' || instr[i] == ']')
        {
            if(S.empty() || !((S.top() == '(' && instr[i] == ')') ||
            (S.top() == '{' && instr[i] == '}') || (S.top() == '[' && instr[i] == ']')))
                return false;
            else
                S.pop();
        }
    }
    return S.empty();

}
bool CanBeEvaluated(const string instr)
{
    string test = instr;

    if (!BalancedParens(test))
    {
        return false;
    }
    else {
        stringstream ss;
        string j;
        ss << test;
        while (ss >> j) {
            if (IsIdentifier(j)) {
                return false;
            }
        }

        return true;
    }
}
void GetPostFixNotation(const string instr)
{
    string test = instr;
    Stack<string> st;
    string postfix;

        stringstream ss;
        string j;
        ss << test;

        while (ss >> j)
        {
            if (IsInteger(j) || IsFloat(j) || IsIdentifier(j))
                postfix = postfix + " " + j;

            else if (j == "(")
                st.push(j);

            else if (j == ")")
            {
                while (st.top() != "(" && !(st.empty()))
                {
                    postfix = postfix + " " + st.top();
                    st.pop();
                }
                if (st.top() == "(") {
                    st.pop();
                }
            }
            else if (IsOperator(j))
            {
                while ( (!st.empty()) && (Precedence(j) <= Precedence(st.top())))
                    {
                        postfix = postfix + " " + st.top();
                        st.pop();
                    }
                st.push(j);
            }
        }

    while (!st.empty()) {
        postfix = postfix + " " + st.top();
        st.pop();
    }

    cout << "The PostFix Notation is: " << postfix << endl;
    if(CanBeEvaluated(instr))
    {
        cout << "Results are: " << EvaluationOfExpression(postfix) << endl;
    }
    else
    {
        cout << "Cannot evaluate " << endl;
    }
    return;
}
float EvaluationOfExpression(const string postfix)
{
    string exp = postfix;
    Stack<float> stack;

        stringstream ss;
        string j;
        ss << exp;

        while (ss >> j)
        {
            if (IsFloat(j) || IsInteger(j) )
            {
                stack.push(StringToFloat(j));
            }
            else if (IsOperator(j))
                {
                float x = stack.top();
                stack.pop();

                float y = stack.top();
                stack.pop();

                if (j == "+")
                    stack.push(y + x);

                else if (j == "-")
                    stack.push(y - x);

                else if (j == "*")
                    stack.push(y * x);

                else if (j == "/")
                    stack.push(y / x);

                else if (j == "^")
                    stack.push(pow(y, x));
            }
        }
    return stack.top();
}

int main()
{
    string line;

    while (getline(cin, line)) {

        GetPostFixNotation(line);

    }



    return 0;
}




