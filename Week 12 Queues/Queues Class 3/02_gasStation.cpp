#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;

        // index from where we are starting the movement
        int start = 0;

        // har ek index ko check karr hai k wo answer hai ya nahi
        for (int i = 0; i < gas.size(); i++) {
            balance = balance + gas[i] - cost[i];

            if (balance < 0) {
                deficit += abs(balance);

                start = i + 1;
                balance = 0;
            }
        }
        if (balance - deficit >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};

int main(){
    
}