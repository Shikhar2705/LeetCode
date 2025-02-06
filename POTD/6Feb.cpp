#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int totalTuples = 0;

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i + 1; j--) {
                int prod = nums[i] * nums[j];
                set<int> possibleVal;

                for (int k = i + 1; k < j; k++) {
                    if (prod % nums[k] == 0) {
                        int val = prod / nums[k];

                        if (possibleVal.find(val) != possibleVal.end()) {
                            totalTuples += 8;
                        }

                        possibleVal.insert(nums[k]);
                    }
                }
            }
        }

        return totalTuples;
    }
};

int main()
{
    vector<int> nums = {2,3,4,6};

    Solution sol;

    cout << sol.tupleSameProduct(nums);
    return 0;
}