#include <iostream>
using namespace std;

class Student
{
    string gf;

public:
    int id;
    int age;
    bool present;
    string name;
    int nos;
    int *v;
    // default
    Student()
    {
        cout << "Student ctor called" << endl;
    }

    // para
    Student(int id, int age, bool present, string name, int nos, string gf)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->gf = gf;
        this->v = new int(10);
        cout << "Student paremeterized ctor called" << endl;
    }

    // getter / setter
    string getGfName()
    {
        return gf;
        // return this->gf;
    }

    // setter
    void setGfName(string gf)
    {
        this->gf = gf;
    }

    // destructor
    ~Student()
    {
        cout << "Destructor called" << endl;
        delete v;
    }
};

int main()
{

    // int a = 5;
    // int b = a;
    // cout << a << endl;
    // cout << b << endl;

    Student s1(1, 12, 1, "Nikesh", 1, "Chutki");
    cout << s1.name << endl;
    cout << s1.getGfName() << endl;

    s1.setGfName("Indumati");

    cout << s1.getGfName() << endl;

    return 0;
}