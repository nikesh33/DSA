#include <iostream>
using namespace std;

// pass by Reference
void passByReference(int *&ptr)
{
    cout << "Pass By Reference: " << endl;
    ptr = ptr + 1;
}

// pass by value
void passByValue(int *ptr)
{
    cout << "Pass By Value: " << endl;
    ptr = ptr + 1;
}

int main()
{
    int a = 5;
    int *ptr = &a;

    cout << "ptr: " << ptr << endl;
    cout << "&ptr: " << &ptr << endl;
    cout << "*ptr: " << *ptr << endl;

    // passByValue(ptr);
    passByReference(ptr);

    cout << "ptr: " << ptr << endl;
    cout << "&ptr: " << &ptr << endl;
    cout << "*ptr: " << *ptr << endl;
}