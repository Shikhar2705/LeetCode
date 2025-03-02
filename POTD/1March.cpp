#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        vector<int> res(n,0);
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res[idx++] = nums[i];
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {1,2,2,1,1,0};

    Solution sol;

    vector<int> result = sol.applyOperations(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}