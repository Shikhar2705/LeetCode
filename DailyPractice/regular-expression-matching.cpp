#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool solveTab(string& str, string& pattern) {
        vector<int> prev(pattern.length() + 1, 0);
        vector<int> curr(pattern.length() + 1, 0);

        prev[0] = true; 

        for (int j = 1; j <= pattern.length(); j++) {
            if (pattern[j - 1] == '*') {
                prev[j] = prev[j - 2];
            } else {
                prev[j] = false;
            }
        }

        for (int i = 1; i <= str.length(); i++) {
            curr[0] = false; 
            for (int j = 1; j <= pattern.length(); j++) {
                if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.') {
                    curr[j] = prev[j - 1];
                } else if (pattern[j - 1] == '*') {
                    curr[j] = curr[j - 2] || ((str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') && prev[j]);
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[pattern.length()];
    }
    bool isMatch(string s, string p) {
        return solveTab(s,p);
    }
};

int main()
{
    string s = "mississippi";
    string p = "mis*is*p*.";

    Solution sol;
    bool result = sol.isMatch(s, p);

    if (result) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}