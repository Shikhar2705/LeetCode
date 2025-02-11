#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.length()>s.find(part)){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};

int main()
{
    string s = "daabcbaabcbc";
    string t = "abc";

    Solution sol;

    cout << sol.removeOccurrences(s,t) << endl;
    return 0;
}