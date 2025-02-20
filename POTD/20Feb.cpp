#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";

        for (int i = 0; i < n; i++) {
            res += (nums[i][i] == '0') ? '1' : '0';
        }

        return res;
    }
};

int main()
{
    vector<string> nums = {"11", "10"};

    Solution sol;

    cout << sol.findDifferentBinaryString(nums);
    return 0;
}