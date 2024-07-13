#include <iostream>
using namespace std;

int main()
{

    ////creation of String and Taking Input
    // string name;
    // cin >> name;

    //=>=>=>=> Prebuilt Utility Functions In Strings <=<=<=//

    // // Length of String
    // cout << "Length of String: " << name.length() << endl;

    // // String is Empty or Not
    // string temp = "m";
    // cout << "String is Empty or Not: " << temp.empty();

    // // character's position at which
    // cout << "Character at 1st Position: " << name.at(1);

    // // First Character and Last Character eg=> Nikesh => Front: N => Back: H
    // cout << "Front: " << name.front()<<endl;
    // cout << "Back: " << name.back()<<endl;

    // // Append to String eg=> Str1=> "My Name is" & Str2 => "Nikesh"  =>=>=> My Name is Nikesh
    // string str1 = "My Name is ";
    // string str2 = "Nikesh";
    // cout << "After Append: " << str1.append(str2);

    // // Remove a char from given string
    // string desc = "This is a car";
    // desc.erase(4, 3);
    // cout << desc << endl;

    // // Insert string in
    // string name = "Nikesh Vishwakarma";
    // string middle = "Kumar ";
    // name.insert(7, middle);
    // cout<<"Printing name: " << name;

    // // Add/Remove (Push_back,Pop_back) Additional Character in End [N|I|K|E|S|H=>|G|<=]
    // string name = "Nikesh";
    // name.push_back('G');
    // cout << "Printing For Push_back: " << name << endl;
    // name.pop_back();
    // cout << "Printing For Pop_back: " << name << endl;

    // // To Find <Particular String> In String
    // string str1 = "yaar tera super start desi kalakar";
    // string str2 = "star";

    // if (str1.find(str1) == string::npos)
    // {
    //     // Not Found
    //     cout << "Not Found" << endl;
    // }
    // else
    // {
    //     // Found
    //     cout << "Found" << endl;
    // }

    // // Dot Compare => Exactly Same hai ki nahi
    // string str1 = "Love";
    // string str2 = "love";

    // if (str1.compare(str2) == 0)
    // {
    //     cout << "Matching" << endl;
    // }
    // else
    // {
    //     cout << "Not Matching" << endl;
    // }

    // ek string se ek sub part kaise nikalte hai
    string desc = "This is a Car, big daddy of all Suvs";
    cout << desc.substr(19, 5) << endl;
}