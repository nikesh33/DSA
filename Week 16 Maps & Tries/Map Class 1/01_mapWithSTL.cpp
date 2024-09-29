#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> mapping;

    //   Pair Create Ways
    // way 1:
    pair<string, int> p = make_pair("Love", 25);
    // way 2:
    pair<string, int> q("Nikesh", 24);
    // way 3:
    pair<string, int> r;
    r.first = "Arjun";
    r.second = 23;
    // way 4:
    pair s("Bheem", 22);
    // way 5:
    pair g2("1", 19);
    g2 = {"Naiya", 20};

    // insertion
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping.insert(s);
    // way 2
    mapping["babbar"] = 50;

    cout << "Size of map: " << mapping.size() << endl;

    // Access
    // using "at"
    cout << "Value of String Way 1: " << mapping.at("Love") << endl;
    // Way 2:
    cout << "Value of String Way 2: " << mapping["Love"] << endl;

    // Searching
    // count wala function agar aap laagte ko kisi ke upar agar wo key map ke andar present hai to 1 print hota agar nahi hota hai to 0 print hota hai
    cout << mapping.count("Nikesh") << endl;

    // way 2:
    // find me agar key mil gaya to iterator kahi present hoga jaha key hoga
    // Lekin agar key nahi mila to iterator map ke end me khada hoga
    // eg -> 1 2 3 4
    // agar mil gya key "Nikesh" 3 pe to iterator waha khada hoga
    // lekin nahi mila to 4 ke baad khada hoga iterator

    if (mapping.find("babbar") != mapping.end())
    {
        // Condition : agar babbar key find karte karte end tak nahi pahucha to matalab key present hai ans mil gya
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    // size at this point when we are printing size it is 5
    cout << "Size: " << mapping.size() << endl;
    // But due to this agar pehle se mene banaya hota aisa to ye print hota but
    // Lekin kyuki nahi banaya iska alag se entry create hoga
    // agar square barcket ka use kar ke bana rahe hai to -> mapping["King"];
    cout << mapping["Mr_Mango"] << endl;
    cout << "Size: " << mapping.size() << endl;
    return 0;
}