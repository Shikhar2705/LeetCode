#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        
        int count = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                count++;
            }
        }
        if(nums[n - 1] > nums[0])
        {
            count++;
        }
        return count<=1;
    }
};

int main()
{
    vector<int> nums = {3,4,5,1,2};

    Solution sol;

    if (sol.check(nums)) {
        cout << "Array was originally sorted in non-decreasing order, then rotated some number of positions (including zero).";
    } else {
        cout << "Array was not originally sorted in non-decreasing order, then rotated some number of positions (including zero).";
    }
    return 0;
}