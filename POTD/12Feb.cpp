#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    private:
        int sumOfDigit(int num) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }
    
    public:
        int maximumSum(vector<int>& nums) {
            unordered_map<int, pair<int, int>> sameSum; 
    
            for (int num : nums) {
                int sumOfDigitsNum = sumOfDigit(num);
    
                if (sameSum.find(sumOfDigitsNum) == sameSum.end()) {
                    sameSum[sumOfDigitsNum] = {num, -1}; 
                } else {
                    auto& p = sameSum[sumOfDigitsNum];
                    if (num > p.first) {
                        p.second = p.first;
                        p.first = num;
                    } else if (num > p.second) {
                        p.second = num;
                    }
                }
            }
    
            int maxSum = -1;
    
            for (const auto& x : sameSum) {
                if (x.second.second != -1) {  
                    maxSum = max(maxSum, x.second.first + x.second.second);
                }
            }
    
            return maxSum;
        }
    };
    

int main()
{
    vector<int> nums = {18,43,36,13,7};

    Solution sol;

    cout << sol.maximumSum(nums) << endl; // returns 54 (18 + 36)
    return 0;
}