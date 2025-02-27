#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            maxSum = max(maxSum, prefixSum);
            minSum = min(minSum, prefixSum);
        }

        return maxSum - minSum;
    }
};

int main()
{
    vector<int> nums = {1,-3,2,3,-4};
    Solution sol;
    
    cout << sol.maxAbsoluteSum(nums);
    return 0;
}