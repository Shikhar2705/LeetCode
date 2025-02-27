#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        int len = 0;

        vector<vector<int>> dp(n,vector<int>(n,0));

        for (int curr = 2; curr < n; curr++) {
            int start = 0;
            int end = curr - 1;

            while (start < end) {
                int pairSum = arr[start] + arr[end];

                if (pairSum > arr[curr]) {
                    end--;
                } else if (pairSum < arr[curr]) {
                    start++;
                } else {
                    dp[end][curr] = dp[start][end] + 1;
                    len = max(dp[end][curr], len);
                    end--;
                    start++;
                }
            }
        }

        return len == 0 ? 0 : len + 2;
    } 
};

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8};

    Solution sol;

    cout << sol.lenLongestFibSubseq(arr);
    return 0;
}