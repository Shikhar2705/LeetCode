#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if ((nums[i] % 2) == (nums[i - 1] % 2))
                return false;
        }
        return true;
    }
};

int main()
{
    vector<int> nums = {4,3,1,6};

    Solution sol;

    if (sol.isArraySpecial(nums))
        cout << "Array is special";
    else    
        cout << "Array is not special";
    return 0;
}