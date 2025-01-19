#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) {
          return 0;
        }
        int n = height.size();
        int maxLeft = height[0], maxRight = height[n-1];
        int left = 0, right = n-1, ans = 0;

        while (left <= right) {
          if (maxLeft < maxRight) {
            if (height[left] > maxLeft) {
              maxLeft = height[left];
            }
            else {
              ans += maxLeft - height[left];
            }+
            left++;
          }
          else {
            if (height[right] > maxRight) {
              maxRight = height[right];
            }
            else {
              ans += maxRight - height[right];
            }
            right--;
          }
        }

        return ans;
    }
};

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution s;
    cout << s.trap(height) << endl;
    return 0;
}