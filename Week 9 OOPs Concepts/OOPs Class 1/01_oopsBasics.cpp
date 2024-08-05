#include <iostream>
using namespace std;

class Student
{
    // Props
    int id;
    int age;
    string name;
    int nos;

    // Method
    void study()
    {
        cout << "Studying" << endl;
    }

    void sleep()
    {
        cout << "Sleeping" << endl;
    }
    void bunk()
    {
        cout << "Bunking" << endl;
    }
};

int main()
{
    // creating s1 and s2 as object
    Student s1;
    Student s2;

    return 0;
}