#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int pickP = 0;
        int pickM = 0;
        int pickG = 0;

        int travelP = 0;
        int travelG = 0;
        int travelM = 0;

        // mujhe kaise pata lagega mera truck kaha tak travel karega?
        // jaha bhi last g milega pure array ke andar
        // uss index tak mera g chalega
        // so this variables we have created
        int lastP = 0;
        int lastG = 0;
        int lastM = 0;

        // calculate pick time and travel time

        for (int i = 0; i < garbage.size(); i++)
        {
            string curr = garbage[i];

            for (int j = 0; j < curr.length(); j++)
            {
                char ch = curr[j];

                if (ch == 'P')
                {
                    pickP++;
                    lastP = i;
                }
                else if (ch == 'G')
                {
                    pickG++;
                    lastG = i;
                }
                else if (ch == 'M')
                {
                    pickM++;
                    lastM = i;
                }
            }
        }

        // calculate travel time
        for (int i = 0; i < lastP; i++)
        {
            travelP += travel[i];
        }
        for (int i = 0; i < lastG; i++)
        {
            travelG += travel[i];
        }
        for (int i = 0; i < lastM; i++)
        {
            travelM += travel[i];
        }

        int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> garbage = {"G", "P", "GP", "GG"};

    // travel
    vector<int> travel = {2, 4, 3};
    int ans = sol.garbageCollection(garbage, travel);
    cout << ans;
}