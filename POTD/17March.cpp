#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto x : freq) {
            if (x.second % 2 == 1) return false;
        }

        return true;
    }
};

int main()
{
    vector<int> nums = {3,2,3,2,2,2};

    Solution sol;
    
    if (sol.divideArray(nums)) {
        cout << "Array can be divided in the desired way" << endl;
    } else {
        cout << "Array can not be divided in the desired way" << endl;
    }
    return 0;
}