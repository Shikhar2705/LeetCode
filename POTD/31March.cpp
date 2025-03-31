#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        vector<int> pairWeights(n - 1);

        for (int i = 0; i < n - 1; i++) {
            pairWeights[i] = weights[i] + weights[i + 1];
        }

        sort(pairWeights.begin(), pairWeights.end());

        long long ans = 0;

        for (int i = 0; i < k - 1; i++) {
            ans += pairWeights[n - i - 2] - pairWeights[i];
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> weights = {1,3,5,1};
    int k = 2;

    cout << sol.putMarbles(weights,k);
    return 0;
}