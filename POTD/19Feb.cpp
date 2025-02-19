#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    void generateAllStrings(vector<string>& happyStrings, string& happyString, int len) {
        if (happyString.length() == len) {
            happyStrings.push_back(happyString);
            return ;
        }

        for (char ch : {'a' , 'b' , 'c'}) {
            if (happyString.empty() || happyString.back() != ch) {
                happyString.push_back(ch);
                generateAllStrings(happyStrings, happyString, len);
                happyString.pop_back();
            }
        }
        
    }
public:
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string happyStr = "";
        generateAllStrings(happyStrings, happyStr, n);
        return (k > happyStrings.size()) ? "" : happyStrings[k - 1];
    }
};

int main()
{
    Solution sol;

    cout << sol.getHappyString(3,10);
    return 0;
}