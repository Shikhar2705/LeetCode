#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
private:
    int dfs(int root, int src, vector<bool>& visited, vector<int>& component, vector<vector<pair<int,int>>>& adj) {
        int cost = INT_MAX;
        visited[src] = true;
        component[src] = root;

        for (auto nbr : adj[src]) {
            cost &= nbr.second;
            if (!visited[nbr.first])
                cost &= dfs(root,nbr.first,visited,component,adj);
        }

        return cost;
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<bool> visited(n,false);
        vector<int> component(n);
        vector<int> componentCost(n,INT_MAX);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                componentCost[i] = dfs(i,i,visited,component,adj);
            }
        }

        vector<int> ans;

        for (auto q : query) {
            int s = q[0];
            int t = q[1];

            if (component[s] != component[t])
                ans.push_back(-1);
            else 
                ans.push_back(componentCost[component[s]]);
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> edges = {
        {0,1,7} , {1,3,7} , {1,2,1}
    };

    vector<vector<int>> queries = {
        {0,3} , {3,4}
    };

    int n = 5;

    Solution sol;

    vector<int> result = sol.minimumCost(n,edges, queries);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}