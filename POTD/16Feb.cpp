#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        bool findSequence(int currIndex, vector<int>& seq, vector<bool>& isUsed, int n) {
            if (currIndex == seq.size())
                return true;
            
            if (seq[currIndex] != 0) return findSequence(currIndex + 1, seq, isUsed, n);
    
            for (int i = n; i >= 1; i--) {
                if (isUsed[i]) continue;
    
                isUsed[i] = true;
                seq[currIndex] = i;
    
                if (i == 1) {
                    if (findSequence(currIndex + 1, seq, isUsed, n))
                        return true;
                }
                else if (currIndex + i < seq.size() && seq[currIndex + i] == 0) {
                    seq[currIndex + i] = i;
    
                    if (findSequence(currIndex + 1, seq, isUsed, n))
                        return true;
    
                    seq[currIndex + i] = 0;
                }
    
                isUsed[i] = false;
                seq[currIndex] = 0;
            }
    
            return false;
        }
    public:
        vector<int> constructDistancedSequence(int n) {
            vector<int> sequence(n * 2 - 1, 0);
            vector<bool> isUsed(n + 1, false);
    
            findSequence(0,sequence,isUsed,n);
    
            return sequence;
        }
    };

int main()
{
    Solution sol;

    vector<int> sequence1 = sol.constructDistancedSequence(18);
    vector<int> sequence2 = sol.constructDistancedSequence(12);
    vector<int> sequence3 = sol.constructDistancedSequence(8);

    cout << "First Sequence -->" << endl; 
    for (int i = 0; i < sequence1.size(); i++) {
        cout << sequence1[i] << " ";
    }
    cout << endl;
    cout << "Second Sequence -->" << endl;
    for (int i = 0; i < sequence2.size(); i++) {
        cout << sequence2[i] << " ";
    }
    cout << endl;
    cout << "Third Sequence -->" << endl;
    for (int i = 0; i < sequence3.size(); i++) {
        cout << sequence3[i] << " ";
    }
    cout << endl;
    return 0;
}