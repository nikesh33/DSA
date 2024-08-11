#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bird
{

public:
    int age, weight;
    int nol;
    string color;

    void eat()
    {
        cout << "Bird is Eating" << endl;
    }
    void fly()
    {
        cout << "Bird is Flying" << endl;
    }
};

// Inheritence
class Sparrow : public Bird
{
public:
    // sparrow constructor
    Sparrow(int age, int weight, string color, int nol)
    {
        this->age = age;
        this->weight = weight;
        this->color = color;
        this->nol = nol;
    }
    void grassing()
    {
        cout << "Sparrow is grassing" << endl;
    }
};

class Peigon : public Bird
{
public:
    void guttering()
    {
        cout << "Peigon is guttering" << endl;
    }
};

int main()
{
    Sparrow s(1, 1, "brown", 2);
    cout << s.color << endl;
    s.eat();
    s.grassing();

    Peigon p;
    p.eat();
    p.guttering();

    return 0;
}