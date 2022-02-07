#include <iostream>
#include "stack.cpp"
using namespace std;

 int main(void)

    {
      cout << "Assignment #7 Test Program" << endl;
        Stack<char> Char10;         // Test Character Stack, Default constructor
        Stack<float> Float5 (5);     // Test Float Stack
        Stack<double> Double8(8);   // Test Double Stack
        Stack<bool> Bool2(2);       // Test Bool Stack
        Stack<char> Charcy(Char10); // Default copy constructor
        Bool2.Push(true);           // Test Push on Bool
        Bool2.Push(false);          // Test Push on Bool
        Bool2.Push(true);           // Test error on Push
        cout << "Size of Bool2 is:        "<< Bool2.Size()<<endl;
        cout << "Top element of Bool2 is: " << Bool2.Top() <<endl;
        cout << "Size on Double8 should be 8: "<< Double8.Size()<<endl;
        Char10.Push('A');
        Char10.Push('B');
        Char10.Push('C');
        cout << "Test Pop on Char10, should produce a 'C': ";
        Char10.Pop();
        Char10.Push('C');
        cout << "Test ostream overload on Charcy, should be Empty:  ";
        cout << Charcy<<endl;
        cout << "Test ostream overload on Char10, should be a 'C': ";
        cout <<Char10<< endl;
        cout << "Test ostream overload on Char10, should be a 'B': ";
        cout <<Char10<< endl;
        cout << "Test ostream overload on Char10, should be a 'A': ";
        cout <<Char10<< endl;
        cout << "Test ostream overload on Char10, should be an error: ";
        cout <<Char10<< endl;
        cout << "Test ostream overload on float: ";
        cout << Float5 << endl;
        Float5.Push(2.3425);
        cout << "Test ostream overload on float: ";
        cout << Float5 << endl;
        cout << "Test ostream overload on bool: ";
        cout << Bool2 << endl;
        cout << "Test ostream overload on double: ";
        cout << Double8 << endl;
        Double8.Push(23425);
        cout << "Test ostream overload on double: ";
        cout << Double8 << endl;
        return 0;
    }

