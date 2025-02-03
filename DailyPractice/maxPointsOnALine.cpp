#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    int maxPoints(vector<vector<int>>& pt) {
        int ans = 1;
        int n = pt.size();
        for (int i = 0; i < n - 1; i++) {
            map<double, int> mp;
            for (int j = i + 1; j < n; j++) {

                double x = (double)(pt[j][1] - pt[i][1]) /
                           (double)(pt[j][0] - pt[i][0]);
                if (pt[j][1] - pt[i][1] < 0 && (pt[j][0] - pt[i][0]) == 0)
                    mp[fabs(x)]++;
                else

                    mp[x]++;
            }

            int temp = 0;
            for (auto it : mp)
                temp = max(temp, it.second + 1);
            ans = max(temp, ans);
        }
        return ans;
    }
};


int main()
{
    vector<vector<int>> points = {
        {1,1} , {2,2} , {3,3} , {4,5}
    };

    Solution sol;

    cout << sol.maxPoints(points);
    return 0;
}