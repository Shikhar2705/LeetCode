#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(int node, int currColor, vector<vector<int>>& graph, vector<bool> &vis, vector<int> &color) {
        vis[node] = true;
        color[node] = currColor;

        for (int child : graph[node]) {
            if (!vis[child]) {
                if (!dfs(child, !currColor, graph, vis, color)) {
                    return false;
                }
            }
            else {
                if (color[node] == color[child])
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(), false);
        vector<int> color(graph.size());

        for (int i = 0; i < graph.size(); i++) {
            if (!vis[i] && !dfs(i,0,graph,vis,color)) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> graph = {
        {1,2,3} , {0,2} , {0,1,3} , {0,2}
    };

    Solution sol;

    if (sol.isBipartite(graph))
        cout << "Graph is Bipartite" << endl;
    else    
        cout << "Graph is not Bipartite" << endl;
    return 0;
}