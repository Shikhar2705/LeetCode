#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    void updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] = INT_MAX;
                } else {
                    q.push({i, j});
                }
            }
        }

        vector<int> direction = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int currRow = front.first;
            int currCol = front.second;

            for (int i = 0; i < 4; i++) {
                int newRow = currRow + direction[i];
                int newCol = currCol + direction[i + 1];

                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col &&
                    mat[newRow][newCol] > mat[currRow][currCol] + 1) {
                    mat[newRow][newCol] = mat[currRow][currCol] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        for (int i = 0; i < isWater.size(); i++) {
            for (int j = 0; j < isWater[0].size(); j++) {
                isWater[i][j] = !isWater[i][j];
            }
        }

        updateMatrix(isWater);
        
        return isWater;
    }
};

int main()
{
    vector<vector<int>> isWater = {{0,0,1},{1,0,0},{0,0,0}};

    Solution sol;

    vector<vector<int>> result = sol.highestPeak(isWater);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}