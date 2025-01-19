#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result(n,1);
        for (int i = 1; i < n; i++)
        {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int sp = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            result[i] *= sp;
            sp *= nums[i];
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4};
    Solution s;
    vector<int> result = s.productExceptSelf(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}