#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> index;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int j = target - nums[i];
            if(index.count(j))
            {
                return {index[j],i};
            }
            index[nums[i]] = i;
        }
        return {-1,-1};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};

    Solution s;
    vector<int> result = s.twoSum(nums, 9);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}