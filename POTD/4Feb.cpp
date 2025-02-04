#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
            }
            else {
                sum = nums[i];
            }
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};

int main()
{
    vector<int> nums = {10,20,30,5,10,50};

    Solution sol;

    cout << sol.maxAscendingSum(nums);
    return 0;
}