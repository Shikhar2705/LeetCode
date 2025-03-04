#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n) {
            int mod = n % 3;
            if (mod == 2) return false;

            n /= 3;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    if (sol.checkPowersOfThree(12)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}