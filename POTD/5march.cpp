#include <iostream>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        return 1 + 1LL * 2 * (n - 1) * n;
    }
};

int main()
{
    Solution sol;
    long long result = sol.coloredCells(34);
    cout << result;
    return 0;
}