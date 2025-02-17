#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:    
    void solve(unordered_map<char,int>& freqMap, int& count) {
        for (auto& entry : freqMap) {
            if (entry.second > 0) {
                entry.second--;
                count++;
                solve(freqMap, count);
                entry.second++;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> freqMap;

        for (char c : tiles) {
            freqMap[c]++;
        }

        int count = 0;

        solve(freqMap, count);

        return count;
    }
};

int main()
{
    Solution sol;

    cout << sol.numTilePossibilities("AAB");
    return 0;
}