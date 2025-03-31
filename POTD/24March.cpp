#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:  
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeDays = 0, latestEnd = 0;

        sort(meetings.begin(), meetings.end());

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            if (start > latestEnd + 1) {
                freeDays += start - latestEnd - 1;
            }
            latestEnd = max(latestEnd, end);
        }

        freeDays += days - latestEnd;

        return freeDays;
    }
};

int main()
{
    vector<vector<int>> meetings = {
        {5,7}, {1,3}, {9, 10}
    };
    int days = 10;

    Solution sol;
    cout << "The number of days where no meetings take place is : " << sol.countDays(days, meetings);
    return 0;
}