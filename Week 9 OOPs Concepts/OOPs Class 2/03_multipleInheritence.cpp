#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    void walk()
    {
        cout << "Walking..." << endl;
    }
};

// inheriting person
//using virtual (dono ka ek he walk kardo)
class Teacher : virtual public Person
// class Teacher
{
public:
    void teach()
    {
        cout << "Teaching..." << endl;
    }
};

// inheriting person
//using virtual (dono ka ek he walk kardo)
class Researcher :virtual public Person
{
public:
    void research()
    {
        cout << "Researching..." << endl;
    }
};

// multiple inheritence
class Professor : public Teacher, public Researcher
{
public:
    void bore()
    {
        cout << "Boring..." << endl;
    }
};

int main()
{
    Professor p;
    // p.bore();
    // p.walk();

    // // Diamond Problem
    // // Solution 1: Scope Resolution
    // p.Teacher::walk();
    // p.Researcher::walk();

    // Solution 2: Using Virtual
    p.walk();

    return 0;
}