#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int minReward = 1, maxReward = *max_element(nums.begin(), nums.end()),
            totalHouses = nums.size();

        while (minReward < maxReward) {
            int mid = (minReward + maxReward) / 2;
            int possibleTheft = 0;

            for (int i = 0; i < totalHouses; i++) {
                if (nums[i] <= mid) {
                    possibleTheft++;
                    i++;
                }
            }

            if (possibleTheft >= k) {
                maxReward = mid;
            } else {
                minReward = mid + 1;
            }
        }

        return minReward;
    }
};

int main()
{
    vector<int> nums = {2,3,5,9};
    int k = 2;

    Solution sol;

    cout << sol.minCapability(nums,k);
    return 0;
}