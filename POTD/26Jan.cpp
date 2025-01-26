#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        vector<int> indegree(n,0);

        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> depth(n,1);

        while(!q.empty()) {
            int currNode = q.front();
            q.pop();
            int nextNode = favorite[currNode];
            depth[nextNode] = max(depth[nextNode], depth[currNode] + 1);
            indegree[nextNode]--;

            if (indegree[nextNode] == 0)
                q.push(nextNode);
        }

        int longestCycle = 0, twoCycle = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) continue;

            int cycleLength = 0;
            int curr = i;

            while (indegree[curr] != 0) {
                indegree[curr] = 0;
                cycleLength++;
                curr = favorite[curr];
            }

            if (cycleLength == 2) {
                twoCycle += depth[i] + depth[favorite[i]];
            }
            else {
                longestCycle = max(longestCycle, cycleLength);
            }
        }

        return max(longestCycle, twoCycle);
    }
};

int main()
{
    vector<int> favorite = {3,0,1,4,1};

    Solution sol;

    cout << sol.maximumInvitations(favorite) << endl;
    
    return 0;
}