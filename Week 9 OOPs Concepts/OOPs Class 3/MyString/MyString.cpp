#include "MyString.h"
#include <iostream>
#include <cstring> // strcpy

// Default constructor
MyString::MyString()
{
    data = new char[1];
    length = 0;
    data[0] = '\0';
}

// Parameterized constructor
MyString::MyString(const char *str)
{
    length = strlen(str);
    data = new char[length + 1];
    strcpy(data, str);
}

// Copy constructor
MyString::MyString(const MyString &other)
{
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);
}

// Destructor
MyString::~MyString()
{
    delete[] data;
}

// Return the size of the string
int MyString::size() const
{
    return length;
}

// Check if the string is empty
bool MyString::empty() const
{
    return length == 0;
}

// Return the C-string
const char *MyString::c_str() const
{
    return data;
}

// Overloaded output stream operator
std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    os << str.c_str();
    return os;
}
