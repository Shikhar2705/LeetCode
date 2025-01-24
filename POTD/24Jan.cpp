#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (auto node : graph[i]) {
                adj[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<bool> isSafe(n);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            isSafe[node] = true;

            for (auto &nbr : adj[node]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        vector<int> safeNode;

        for (int i = 0; i < n; i++) {
            if (isSafe[i])
                safeNode.push_back(i);
        }

        return safeNode;
    }
};

int main()
{
    vector<vector<int>> graph = {
        {1,2}, {2,3}, {5}, {0}, {5}, {}, {}
    };

    Solution sol;

    vector<int> safeNodes = sol.eventualSafeNodes(graph);

    for (int i = 0; i < safeNodes.size(); i++) {
        cout << safeNodes[i] << " ";
    }
    
    return 0;
}