#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            stack<char> st;
    
            for (int i = 0; i < s.length(); i++) {
              if (s[i] >= 97 && s[i] <= 122)
                st.push(s[i]);
              else if (s[i] >= 48 && s[i] <= 57)
                st.pop();
            }
    
            string ans = "";
    
            while (!st.empty()) {
              ans += st.top();
              st.pop();
            }
    
            reverse(ans.begin(), ans.end());
    
            return ans.size() == 0 ? "All Cleared" : ans;
    
        }
    };

int main()
{   
    string s1 = "abc";
    string s2 = "cb34";
    Solution sol;

    cout << sol.clearDigits(s1) << endl;
    cout << sol.clearDigits(s2) << endl;
    return 0;
}