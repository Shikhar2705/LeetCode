#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int len = colors.size();
        int result = 0;

        int left = 0, right = 1;

        while (right < len) {
            if (colors[right] == colors[right - 1]) {
                left = right;
                right++;
                continue;
            }

            right++;

            if (right - left < k) continue;

            result++;
            left++;
        }

        return result;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main()
{
    vector<int> colors = {0,1,0,1,0};
    int k = 3;
    Solution sol;
    cout << sol.numberOfAlternatingGroups(colors, k);
    return 0;
}