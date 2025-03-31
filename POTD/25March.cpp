#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool check(vector<vector<int>>& rectangles, int cut) {
        int gapCount = 0;

        sort(rectangles.begin(), rectangles.end(),
            [cut](const vector<int>& a, const vector<int>& b) {
                return a[cut] < b[cut]; 
            }
        );

        int furthestEnd = rectangles[0][cut + 2];

        for (int i = 0; i < rectangles.size(); i++) {
            vector<int> rect = rectangles[i];

            if (furthestEnd <= rect[cut]) {
                gapCount++;
            }

            furthestEnd = max(furthestEnd, rect[cut + 2]);
        }

        return gapCount >= 2;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return check(rectangles,0) || check(rectangles,1);
    }
};

int main()
{
    vector<vector<int>> rect = {
        {1,0,5,2}, {0,2,2,4}, {3,2,5,3}, {0,4,4,5}
    };
    int n = 5;

    Solution sol;

    cout << sol.checkValidCuts(n,rect);
    return 0;
}