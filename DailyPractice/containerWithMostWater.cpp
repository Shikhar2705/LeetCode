#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int n = height.size();
      int l = 0;
      int r = n - 1;
      int maxArea = 0;

      while (l < r) {
          int area = min(height[l], height[r]) * (r - l);
          maxArea = max(maxArea, area);

          if (height[l] < height[r]) {
              l++;
          } else {
              r--;
          }
      }

      return maxArea;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution s;

    cout << s.maxArea(height) << endl;  
    return 0;
}