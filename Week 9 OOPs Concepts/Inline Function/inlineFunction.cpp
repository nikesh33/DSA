#include <iostream>
using namespace std;

inline void numberShow(int num)
{
    cout << num << endl;
}

int main()
{
    // //bar bar function me ja ke phir ayega stack me unwinding hoga
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);

    // inline me ase hojata hai
    // jab function chota hai to inline function use karna chahiye
    // cout << 10 << endl;
    // cout << 10 << endl;
    // cout << 10 << endl;
    // cout << 10 << endl;
    // cout << 10 << endl;
    // cout << 10 << endl;
    // cout << 10 << endl;
    // cout << 10 << endl;
    return 0;
}