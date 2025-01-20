#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int solve(int row, int col, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
      if (row == triangle.size() - 1) 
        return triangle[row][col];

      if (dp[row][col] != -1)
        return dp[row][col];

      int total = triangle[row][col] + min(solve(row + 1, col, triangle, dp), solve(row + 1, col + 1, triangle, dp));

      return dp[row][col] = total;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      vector<vector<int>> dp(triangle.size());
      for (int i = 0; i < triangle.size(); ++i) {
        dp[i] = vector<int>(triangle[i].size(), -1);
      }
      return solve(0,0,triangle, dp);
    }
};

int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}