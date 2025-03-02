#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int> IdMapping(1001,0);

        for (auto nums : nums1) {
            int id = nums[0];
            int val = nums[1];

            IdMapping[id] += val;
        }

        for (auto nums : nums2) {
            int id = nums[0];
            int val = nums[1];

            IdMapping[id] += val;
        }

        vector<vector<int>> result;

        for (int i = 1; i <= 1000; i++) {
            if (IdMapping[i] > 0) {
                result.push_back({i,IdMapping[i]});
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> nums1 = {
        {1,2} , {2,3} , {4,5}
    }; 

    vector<vector<int>> nums2 = {
        {1,4} , {3,2} , {4,1}
    };

    Solution sol;

    vector<vector<int>> result = sol.mergeArrays(nums1,nums2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    
    return 0;
}