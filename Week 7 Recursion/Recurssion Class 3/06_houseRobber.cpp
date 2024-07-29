#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int size, int index) {
        // base case
        if (index >= size) {
            return 0;
        }

        // chori karlo
        int option1 = nums[index] + solve(nums, size, index + 2);

        // chori mat karo
        int option2 = 0 + solve(nums, size, index + 1);

        int finalAns = max(option1, option2);
        return finalAns;
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        int ans = solve(nums, size, index);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>ans = {1,2,3,1};
    cout<<sol.rob(ans);
}
