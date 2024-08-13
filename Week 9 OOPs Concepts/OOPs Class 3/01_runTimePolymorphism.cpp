#include <iostream>
using namespace std;

class Animal
{
public:
    void sound()
    {
        cout << "Animal Making Sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound()
    {
        cout << "Dog Barking" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound()
    {
        cout << "Cat Meowing" << endl;
    }
};

void sound(){
    
}

int main()
{
    Dog *dog = new Dog();
    dog->sound();
    return 0;
}