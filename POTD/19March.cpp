#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int l = 0;
        int r = 2;
        int count = 0;
        int n = nums.size();

        while (r < nums.size()) {
            if (nums[l] == 0) {
            for (int i = l; i <= r; i++) {
                if (nums[i] == 0)
                nums[i] = 1;
                else
                nums[i] = 0;
            }
            count++;
            }
            l++;
            r++;
        }

        return (nums[n - 1] == 0 || nums[n-2] == 0) ? -1 : count;
    }
};

int main()
{
    vector<int> nums = {0,1,1,1,0,0};
    
    Solution sol;

    cout << sol.minOperations(nums);
    return 0;
}