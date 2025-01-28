#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> direction = {
        {0,1} , {0,-1} , {1,0} , {-1,0}
    };
private:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 || vis[r][c])
            return 0;

        vis[r][c] = true;
        int fishCount = grid[r][c];

        for (auto dir : direction) {
            int newRow = r + dir[0];
            int newCol = c + dir[1];

            fishCount = max(fishCount , fishCount + dfs(newRow, newCol, grid, vis));
        }

        return fishCount;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        int maxFish = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    int fish = dfs(i,j,grid, vis);

                    maxFish = max(fish, maxFish);
                }
            }
        }

        return maxFish;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0,2,1,0}, {4,0,0,3}, {1,0,0,4}, {0,3,2,0}
    };

    Solution sol;

    cout << sol.findMaxFish(grid);
    return 0;
}