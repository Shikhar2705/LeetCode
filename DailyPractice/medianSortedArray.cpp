#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int n1 = nums1.size();

        int n2 = nums2.size();
        
        for (int i = 0; i < n1 ; i++)
        {
            nums.push_back(nums1[i]);
        }
        for (int i = 0; i < n2; i++)
        {
            nums.push_back(nums2[i]);
        }
        sort(nums.begin() , nums.end());
        int n = nums.size();

        double res;

        if (n % 2 == 0)
        {
            res = (nums[n/2] + nums[n/2 - 1]) / 2.0;
        }
        else {
            res = nums[n/2];
        }
        
        return res;
    }
};

int main()
{
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};

    Solution sol;

    double res = sol.findMedianSortedArrays(nums1,nums2);

    cout << res;
    
    return 0;
}