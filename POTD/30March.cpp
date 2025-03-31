#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> length;
        set<int> isUsed;

        int start = 0, end = 0;

        while (end < s.length()) {
            int currLetter = s[end] - 'a';
            isUsed.insert(currLetter);
            freq[currLetter]--;

            if (freq[currLetter] == 0) {
                isUsed.erase(currLetter);
            }

            if (isUsed.empty()) {
                length.push_back(end - start + 1);
                start = end + 1;
            }

            end++;
        }

        return length;
    }
};

int main()
{
    string s = "ababcbacadefegdehijhklij";
    Solution sol;
    vector<int> result = sol.partitionLabels(s);

    for (int len : result) {
        cout << len << " ";
    }
    return 0;
}