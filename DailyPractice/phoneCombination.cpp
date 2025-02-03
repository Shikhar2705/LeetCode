#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void solve(string digits, string output, int idx, vector<string>& ans, string pad[])
    {
        if (idx >= digits.length())
        {
            ans.push_back(output);
            return ;
        }
        int number = digits[idx] - '0';
        string str = pad[number];
        for(int i = 0; i < str.length(); i++)
        {
            output.push_back(str[i]);
            solve(digits,output,idx+1,ans,pad);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0)
        {
            return ans;
        }
        string output="";
        string pad[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int idx = 0;
        solve(digits,output,idx,ans,pad);
        return ans;
    }
};

int main()
{
    string digit = "42";

    Solution sol;

    vector<string> combinations = sol.letterCombinations(digit);

    for (int i = 0; i < combinations.size(); i++) {
        cout << combinations[i] << " ";
    }
    return 0;
}