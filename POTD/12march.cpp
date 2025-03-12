#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;

        for (int num : nums) {
            pos += num > 0;
            neg += num < 0;
        }

        return max(pos,neg);
    }
};

int main()
{
    vector<int> nums = {-1,-2,-3,1,2,3};

    Solution sol;
    cout << sol.maximumCount(nums);
    return 0;
}