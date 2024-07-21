#include <iostream>
using namespace std;

int main()
{
    char ch[30] = "statement";
    // pointer cptr is the pointer to the char data
    char *cptr = &ch[0];

    cout << "ch : " << ch << endl; // statement
    cout << "&ch : " << &ch << endl;
    cout << "*(ch+3) : " << *(ch + 3) << endl;
    cout << "cptr : " << cptr << endl;
    cout << "&cptr : " << &cptr << endl;
    cout << "*(cptr+3) : " << *(cptr + 3) << endl;
    cout << "cptr+2 : " << cptr + 2 << endl;
    cout << "*cptr : " << *cptr << endl;
    cout << "cptr+8 : " << cptr + 8 << endl;
}
