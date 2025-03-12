#include <iostream>
#include <string> 
#include <climits>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCount = 0, left = 0, right = 0, minOp = INT_MAX;

        while (right < blocks.length()) {
            if (blocks[right] == 'W') whiteCount++;

            if (right - left + 1 == k) {
                minOp = min(whiteCount, minOp);
                if (blocks[left] == 'W') whiteCount--;

                left++;
            }

            right++;
        }

        return minOp;
    }
};

int main()
{
    string blocks = "BBWBWBWB";
    int k = 3;
    Solution sol;
    cout << sol.minimumRecolors(blocks, k);    
    return 0;
}