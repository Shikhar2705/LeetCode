#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int bitsUsed = 0;

        int start = 0, maxlength = 0;

        for (int end = 0; end < nums.size(); end++) {
            while ((bitsUsed & nums[end]) != 0) {
                bitsUsed ^= nums[start];
                start++;
            }
            bitsUsed |= nums[end];

            maxlength = max(maxlength, end - start + 1);
        }

        return maxlength;
    }
};

int main()
{
    vector<int> nums = {1,3,8,48,10};
    Solution sol;
    
    cout << sol.longestNiceSubarray(nums);
    return 0;
}