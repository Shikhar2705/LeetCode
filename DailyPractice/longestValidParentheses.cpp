#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> stk;
        vector<int> arr(s.length(),0);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') 
                stk.push({s[i],i});
            else {
                if (!stk.empty() && stk.top().first == '(') {
                    arr[i] = 1;
                    int idx = stk.top().second;
                    arr[idx] = 1;
                    stk.pop();
                }
            }
        }

        int currLen = 0, maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) currLen++;
            else currLen = 0;

            maxLen = max(currLen, maxLen);
        }

        return maxLen;
    }
};

int main()
{
    string str = ")()())";
    Solution sol;

    cout << sol.longestValidParentheses(str) << endl;
    return 0;
}