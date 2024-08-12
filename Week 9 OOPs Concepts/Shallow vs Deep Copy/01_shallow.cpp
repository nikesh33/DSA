#include <iostream>

using namespace std;

class abc
{
public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // default dumb copy constructor: it does shallow copy
    abc(const abc &obj)
    {
        x = obj.x;
        // y = obj.y;
        y = new int(*obj.y);
    }

    void print() const
    {
        printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);
    }

    ~abc()
    {
        delete y;
    }
};

int main()
{
    // abc a(1, 2);
    // cout << "Print int a\n";
    // a.print();

    // // abc b(a);
    // abc b = a; // call hota hai, COPY CONSTRUCTOR
    // cout << "Printint b\n";
    // b.print();
    // *b.y = 20;
    // cout << "Printint b\n";
    // b.print();

    // cout << "Printint a\n";
    // a.print();

    abc *a = new abc(1, 2);
    abc b = *a;
    delete a;
    b.print();

    return 0;
}