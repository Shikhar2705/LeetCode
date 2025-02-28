#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1 + 1,vector<int>(n2 + 1,0));

        for (int i = 0; i <= n1; i++) {
            dp[i][0] = i;
        }

        for (int i = 0; i <= n2; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
        }

        string result = "";

        int row = n1, col = n2;

        while (row > 0 && col > 0) {
            if (text1[row - 1] == text2[col - 1]) {
                result += text1[row-1];
                row--;
                col--;
            }
            else if (dp[row - 1][col] < dp[row][col - 1]) {
                result += text1[row-1];
                row--;
            }
            else {
                result += text2[col-1];
                col--;
            }
        }

        while (row > 0) {
            result += text1[row-1];
            row--;
        }

        while (col > 0) {
            result += text2[col-1];
            col--;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    string text1 = "abac", text2 = "cab";

    Solution sol;

    cout << sol.shortestCommonSupersequence(text1, text2);
    return 0;
}