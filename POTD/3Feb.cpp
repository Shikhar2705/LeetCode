#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longestIncreasing = 1, longestDecreasing = 1, longestMonotonic = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                longestIncreasing++;
                longestDecreasing = 1;
            }
            else if (nums[i] < nums[i - 1]) {
                longestDecreasing++;
                longestIncreasing = 1;
            }
            else {
                longestIncreasing = 1;
                longestDecreasing = 1;
            }

            longestMonotonic = max(longestMonotonic, max(longestIncreasing, longestDecreasing));
        }

        return longestMonotonic;
    }
};

int main()
{
    vector<int> nums = {1,4,3,3,2};

    Solution sol;

    cout << sol.longestMonotonicSubarray(nums);
    return 0;
}