#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int maxOcc = 0;
        int dominant = -1;

        for (auto x : freq) {
            if (x.second > maxOcc) {
                dominant = x.first;
                maxOcc = x.second;
            }
        }
        int f = 0;
        for (int i = 0; i < n; i++) {
            int firstHalfLen = i + 1;
            int secondHalfLen = n - firstHalfLen;

            if (nums[i] == dominant) {
                f++;

                if (f > firstHalfLen / 2 && maxOcc - f > secondHalfLen / 2) {
                    return i;
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = {1,2,2,2};

    Solution sol;

    cout << sol.minimumIndex(nums);
    return 0;
}