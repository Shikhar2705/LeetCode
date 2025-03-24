#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;

        vector<int> diff(n + 1);

        for (int i = 0; i < n; i++) {
            while (sum + diff[i] < nums[i]) {
                k++;
                if (k > queries.size()) return -1;

                int left = queries[k-1][0], right = queries[k-1][1], val = queries[k-1][2];

                if (right >= i) {
                    diff[max(left,i)] += val;
                    diff[right+1] -= val;
                }
            }
            sum += diff[i];
        }

        return k;
    }
};

int main()
{
    vector<int> nums = {2,0,2};
    vector<vector<int>> queries = {
        {0,2,1} , {0,2,1} , {1,1,3}
    };

    Solution sol;

    cout << sol.minZeroArray(nums, queries);
    return 0;
}