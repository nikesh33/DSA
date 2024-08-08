#include <iostream>
using namespace std;

// class abc
// {
// public:
//     int x, y;

//     // there is hidden parameter in this function ("this")
//     void print() const
//     {
//         // this
//         cout << this->x << " " << this->y << endl;
//     }
// };

// ek he  x y ko sare instance relate karenge
class abc
{
public:
    static int x, y;

    void print() const
    {
        cout << x << " " << y << endl;
    }
};

int abc::x;
int abc::y;

int main()
{
    // code 1
    // abc obj1 = {1, 2};
    // abc obj2 = {4, 5};
    // obj1.print();
    // obj2.print();

    // code 2
    abc obj1;
    obj1.x = 1;
    obj1.y = 2;
    obj1.print();
    abc obj2;
    obj2.x = 10;
    obj2.y = 20;
    obj1.print();
    obj2.print();

    return 0;
}