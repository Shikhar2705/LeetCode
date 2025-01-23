#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rowCount(grid[0].size(), 0);
        vector<int> colCount(grid.size(), 0);

        int serverCount = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    rowCount[j]++;
                    colCount[i]++;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    serverCount += rowCount[j] > 1 || colCount[i] > 1;
                }
            }
        }

        return serverCount;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1,1,0,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,1}
    };

    Solution sol;

    cout << sol.countServers(grid) << endl;
    return 0;
}