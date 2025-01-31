#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    int solve(int row, int col, int islandId, vector<vector<int>>& grid) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1)
            return 0;
        grid[row][col] = islandId;

        return 1 + solve(row + 1, col, islandId, grid) + solve(row - 1, col, islandId, grid)
                + solve(row, col + 1, islandId, grid) + solve(row, col - 1, islandId, grid);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> islandSize;
        int islandId = 2;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    islandSize[islandId] = solve(r,c,islandId,grid);
                    islandId++;
                }
            }
        }

        if (islandSize.size() == 0)
            return 1;

        if (islandSize.size() == 1){
            islandId--;

            return (islandSize[islandId] == grid.size() * grid[0].size()) ? islandSize[islandId] : islandSize[islandId] + 1;
        }

        int maxSize = 1;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) {
                    int currSize = 1;
                    unordered_set<int> nbrIsland;

                    if (r + 1 < grid.size() && grid[r + 1][c] > 1) {
                        nbrIsland.insert(grid[r + 1][c]);
                    }

                    if (r - 1 >= 0 && grid[r - 1][c] > 1) {
                        nbrIsland.insert(grid[r - 1][c]);
                    }

                    if (c + 1 < grid[0].size() && grid[r][c + 1] > 1) {
                        nbrIsland.insert(grid[r][c + 1]);
                    }

                    if (c - 1 >= 0 && grid[r][c - 1] > 1) {
                        nbrIsland.insert(grid[r][c - 1]);
                    }

                    for (int id : nbrIsland) {
                        currSize += islandSize[id];
                    }

                    maxSize = max(maxSize, currSize);
                }
            }
        }

        return maxSize;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1,0} , {0,1}
    };

    Solution sol;

    cout << sol.largestIsland(grid);
    return 0;
}