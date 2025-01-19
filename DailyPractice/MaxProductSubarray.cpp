#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double max_so_far = INT_MIN;
        double max_ending_here = 1;

        for(int i=0; i<nums.size(); i++) {
            max_ending_here*= nums[i];
            max_so_far = max(max_ending_here, max_so_far);
            if(max_ending_here == 0) max_ending_here = 1;
           
        }

        max_ending_here = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            max_ending_here*= nums[i];
            max_so_far = max(max_ending_here, max_so_far);
            if(max_ending_here == 0) max_ending_here = 1;
           
        }
        return max_so_far;
    }
};

int main()
{
    vector<int> nums = {2,3,-2,4};
    Solution s;
    cout << s.maxProduct(nums);
    return 0;
}