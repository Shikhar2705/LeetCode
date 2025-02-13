#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long>> pq;
    
            for (int num : nums) {
                pq.push(num);
            }
    
            int operations = 0;
    
            while (pq.top() < k) {
                long long firstSmallest = pq.top();
                pq.pop();
                long long secondSmallest = pq.top();
                pq.pop();
    
                long long newNum = firstSmallest * 2 + secondSmallest;
                pq.push(newNum);
    
                operations++;
            }
    
            return operations;
        }
    };

int main()
{
    vector<int> nums = {2,11,10,1,3};
    int k = 10;

    Solution sol;

    cout << sol.minOperations(nums,k) << endl;
    return 0;
}