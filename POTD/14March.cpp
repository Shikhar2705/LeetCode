#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& candies, long long k, int mid) {
        long long maxChildren = 0;

        for (int i = 0; i < candies.size(); i++) {
            maxChildren += candies[i] / mid;
        }

        return maxChildren >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 0;
        int maxCandies = 0;

        for (int candy : candies) {
            maxCandies = max(candy, maxCandies);
        }
        int high = maxCandies;

        while (low < high) {
            int mid = (low + high + 1) / 2;

            if (isPossible(candies,k,mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main()
{
    vector<int> candies = {5,8,6};
    int k = 3;
    
    Solution sol;
    cout << sol.maximumCandies(candies, k);
    return 0;
}