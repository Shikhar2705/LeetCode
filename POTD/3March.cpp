#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        int pivotCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                result.push_back(nums[i]);
            }

            if (nums[i] == pivot) pivotCount++;
        }

        for (int i = 0; i < pivotCount; i++) {
            result.push_back(pivot);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > pivot) result.push_back(nums[i]);
        }

        return result;
    }

    void printArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;

    Solution sol;

    vector<int> result = sol.pivotArray(nums,pivot);

    sol.printArray(result);
    return 0;
}