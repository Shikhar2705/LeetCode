#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        int prefixSum = 0;

        long long count = 0, evenSum = 0, oddSum = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            if (prefixSum % 2 == 0) {
                evenSum++;
                count += oddSum;
            }
            else {
                oddSum++;
                count += evenSum;
            }
        }

        return (count + oddSum) % mod;
    }
};

int main()
{
    vector<int> nums = {1, 3, 5};

    Solution sol;

    cout << sol.numOfSubarrays(nums);
    return 0;
}