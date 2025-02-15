#include <iostream>
using namespace std;

class Solution {
    private:
        bool doesSatisfy(int num, int target) {
            if (target < 0 || num < target)
                return false;
    
            if (num == target) return true;
    
            return doesSatisfy(num / 10, target - num % 10) || doesSatisfy(num / 100, target - num % 100)
                    || doesSatisfy(num / 1000, target - num % 1000);
        }
    public:
        int punishmentNumber(int n) {
            if (n == 1) return 1;
            int ans = 1;
    
            for (int i = 2; i <= n; i++) {
                if (doesSatisfy(i*i, i)) {
                    ans += i*i;
                }
            }
    
            return ans;
        }
    };

int main()
{
    Solution sol;

    cout << sol.punishmentNumber(90) << endl;
    cout << sol.punishmentNumber(973) << endl;
    cout << sol.punishmentNumber(264) << endl;
    cout << sol.punishmentNumber(183) << endl;
    
    return 0;
}