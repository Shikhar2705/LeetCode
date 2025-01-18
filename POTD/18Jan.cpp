#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
    int dir[4][2] = {
        {0, 1},   
        {0, -1},  
        {1, 0},   
        {-1, 0}   
    };

public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0}); 

        vector<vector<int>> mincost(row, vector<int>(col, INT_MAX));
        mincost[0][0] = 0;

        while (!pq.empty()) {
            auto current = pq.top(); 
            pq.pop();
            int cost = current[0];   
            int r = current[1];      
            int c = current[2];      


            if (mincost[r][c] != cost) continue;

            for (int d = 0; d < 4; d++) {
                int newRow = r + dir[d][0];
                int newCol = c + dir[d][1];

                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col) {
                    int newCost = cost + ((d != grid[r][c] - 1) ? 1 : 0);

                    if (mincost[newRow][newCol] > newCost) {
                        mincost[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        }

        return mincost[row - 1][col - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{1,1,1,1}, {2,2,2,2}, {1,1,1,1}, {2,2,2,2}};

    Solution sol;
    int result = sol.minCost(grid);
    cout << "The minimum cost is: " << result << endl;
    return 0;
}

