#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> freq(26,0);

        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        for (int i = 0; i < s2.length(); i++) {
            freq[s2[i] - 'a']--;
            if (freq[s2[i] - 'a'] < 0)
                return false;
        }
        
        int count = 0;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                count++;
            }
        }

        return (count == 0) || (count == 2);
    }
};

int main()
{
    string s1 = "bank";
    string s2 = "kanb";

    Solution sol;

    if (sol.areAlmostEqual(s1,s2))
        cout << "True";
    else
        cout << "False";
    return 0;
}