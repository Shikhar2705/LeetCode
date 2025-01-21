#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <limits.h>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long res = LONG_MAX;

        long long firstRowSum = accumulate(grid[0].begin(), grid[0].end(),0LL), secondRowSum = 0;

        for (int i = 0; i < grid[0].size(); i++) {
            firstRowSum -= grid[0][i];

            res = min(res, max(firstRowSum, secondRowSum));

            secondRowSum += grid[1][i];
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {2, 5, 4},
        {1, 5, 1}
    };

    Solution sol;

    cout << sol.gridGame(grid) << endl;

    return 0;
}