#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
private:
    char *data; // pointer to char array data
    int length; // size of my string

public:
    // default constructor
    MyString();

    // param ctor
    MyString(const char *str);

    // copy ctor
    MyString(const MyString &other);

    // dtor
    ~MyString();

    int size() const; // const se ye hoga ki aap upar private declared ho hai length usko change nhi kar sakte

    bool empty() const;

    const char *c_str() const;

    // overlaod insertion operator << for easy output
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
};

#endif // MYSTRING_H
