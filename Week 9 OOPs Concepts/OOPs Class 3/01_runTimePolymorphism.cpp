#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal Making Sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog Barking" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Cat Meowing" << endl;
    }
};

void sound(Animal *animal)
{
    animal->sound(); //polymorphic
    // animal-> sound is behaving as per required object allocated at runtime
}

int main()
{
    // Dog *dog = new Dog();
    // dog->sound();

    Animal *animal = new Dog();
    sound(animal);
    animal = new Cat();
    sound(animal);

    return 0;
}