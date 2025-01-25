#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sortedNums = nums;

        sort(sortedNums.begin(), sortedNums.end());

        int currGroup = 0;
        map<int,int> numGroup;

        numGroup[sortedNums[0]] = currGroup;
        map<int, list<int>> groupList;

        groupList[currGroup].push_back(sortedNums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (abs(sortedNums[i] - sortedNums[i - 1]) > limit) {
                currGroup++;
            }
            numGroup[sortedNums[i]] = currGroup;

            groupList[currGroup].push_back(sortedNums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = numGroup[num];
            nums[i] = *groupList[group].begin();
            groupList[group].pop_front();
        }

        return nums;
    }
};

int main()
{
    vector<int> nums = {1,7,6,18,2,1};

    int limit = 3;

    Solution sol;

    vector<int> result = sol.lexicographicallySmallestArray(nums,limit);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    } 

    return 0;
}