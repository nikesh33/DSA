#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>

class Bird
{
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
    // classes that inherit this class
    // has to implement pure vitual fns.
};

class sparrow : public Bird
{
private:
    void eat()
    {
        std::cout << "Sparrow is Eating\n";
    }
    void fly()
    {
        std::cout << "Sparrow is flying\n";
    }
};

class eagle : public Bird
{
private:
    void eat()
    {
        std::cout << "Eagle is Eating\n";
    }
    void fly()
    {
        std::cout << "Eagle is flying\n";
    }
};

class pigeon : public Bird
{
private:
    void eat()
    {
        std::cout << "Pigeon is Eating\n";
    }
    void fly()
    {
        std::cout << "Pigeon is flying\n";
    }
};

#endif // BIRD_H
