#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& nodes) {
        visited[node] = true;
        nodes.push_back(node);

        for (auto nbr : adj[node]) {
            if (!visited[nbr])
                dfs(nbr, adj, visited,nodes);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> nodes; 
                dfs(i,adj,visited,nodes);

                int size = nodes.size();
                bool isComplete = true;

                for (int node : nodes) {
                    if (adj[node].size() != size - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) components++;

            }
        }

        return components;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,2}, {3,4}};
    int n = 5;
    cout << solution.countCompleteComponents(n, edges) << endl;
    return 0;
}