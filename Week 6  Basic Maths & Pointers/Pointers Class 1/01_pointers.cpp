#include <iostream>
using namespace std;

int main()
{
    // int a = 5;
    // cout << "Normal : " << a << endl;
    // cout << "Address of a : " << &a << endl;

    // // pointer creation
    // int *ptr = &a;
    // // acessing value stored at address stored in ptr
    // cout << "Accessing: " << *ptr << endl;      // value print hoga address pe jo hai
    // cout << "Without * : " << ptr << endl;      // without * it will give address b'cuz &a pada h
    // cout << "Address of ptr: " << &ptr << endl; // ptr ka jo address ban gya hai wo print hoga

    // phase 2
    int b = 5;
    int *ptr = &b;

    cout << sizeof(b) << endl;
    cout << sizeof(ptr) << endl;

    // char
    char ch = 'k';
    char *cptr = &ch;
    cout << sizeof(cptr) << endl;

    // long
    long laachi = 10;
    long *lptr = &laachi;
    cout << sizeof(lptr) << endl;
}