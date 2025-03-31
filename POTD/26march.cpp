#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());
        int n = nums.size(); 

        int mid = (n - 1) / 2;
        int median = nums[mid];
        int count = 0;

        for (int num : nums) {
            int diff = abs(num - median);

            if (diff % x != 0) return -1;

            count += diff / x;
        }

        return count;
    }
    };

int main()
{
    vector<vector<int>> grid = {
        {2,4}, {6,8}
    };
    int x = 2;
    Solution sol;

    cout << sol.minOperations(grid,x);
    return 0;
}