#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> seen(n*n + 1, 0);

        int missing = 0;
        int duplicate = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                seen[grid[i][j]]++;
            }
        }

        for (int i = 1; i <= n*n; i++) {
            if (seen[i] == 0) duplicate = i;
            if (seen[i] > 1) missing = i;
        }

        return {missing, duplicate};
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1,2,4},
        {4,5,6},
        {7,8,9}
    };

    vector<int> result;
    Solution sol;
    result = sol.findMissingAndRepeatedValues(grid);
    cout << "Duplicate: " << result[0] << " Missing: " << result[1];
    return 0;
}