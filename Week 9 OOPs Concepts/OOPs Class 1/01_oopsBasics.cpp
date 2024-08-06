#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string gf;

public:
    // Props
    int id;
    int age;
    bool present;
    string name;
    int nos;

    // // constructor(ctor) by default compiler bana deta hai jo ki ase dikhta hai
    //   ctor: Default ctor: assigns garbage value
    Student()
    {
        cout << "Student ctor called " << endl;
    }

    // //**** ctor khud se craete kiya hua
    // parameterized ctor
    Student(int _id, int _age, bool _present, string _name, int _nos, string _gfname)
    {
        // cout << "Student ctor called " << endl;
        id = _id;
        age = _age;
        present = _present;
        name = _name;
        nos = _nos;
        gf = _gfname;
        cout << "Student parameterized ctor called " << endl;
    }

    // parameterized ctor 2
    Student(int _id, int _age, bool _present, string _name, int _nos)
    {
        // cout << "Student ctor called " << endl;
        id = _id;
        age = _age;
        present = _present;
        name = _name;
        nos = 1;
        cout << "Student parameterized ctor without gf called " << endl;
    }

    // polymorphism
    Student(int id, int age, string name)
    {
        // this keyword is for showing current position
        cout << "this keyword" << endl;
        this->id = id;
        this->age = age;
        this->name = name;
    }

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

private:
    void gfChatting()
    {
        cout << "Chatting" << endl;
    }
};

int main()
{
    // // creating s1 and s2 as object
    // Student s1;
    // cout << s1.age << endl;
    // // Student s2;

    // by default 1byte lega class size
    // Student name;
    // cout << sizeof(name);

    // // by default private hota hai class to make them private or public or protected we have a concept called access modifiers
    // Student s1;
    // s1.name = "Nikesh";
    // s1.age = 21;
    // s1.id = 3;
    // s1.nos = 5;

    // Student s2;
    // s2.name = "Fukesh";
    // s2.age = 81;
    // s2.id = 63;
    // s2.nos = 69;

    // constructor para
    Student s0;

    Student s1(1, 21, 1, "Nikesh", 5, "Sak");
    cout << s1.name << endl;

    Student s2(1, 55, 0, "Fuckesh", 1);
    cout << s2.name << endl;

    Student s4(1, 42, "Bheem");
    cout << s4.name << endl;

    // allocating on heap
    Student *s5 = new Student(3, 21, 1, "Amit", 6);
    cout << s5->name << endl;
    cout << (*s5).name << endl;
    cout << s5->age << endl;
    delete s5;

    return 0;
}