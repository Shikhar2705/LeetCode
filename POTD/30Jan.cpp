#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
private:
    bool isBipartite(unordered_map<int, vector<int>> adj, int node, vector<int> &colors) {
        for (int nbr : adj[node]) {
            if (colors[nbr] == colors[node]) return false;

            if (colors[nbr] != -1) continue;

            colors[nbr] = (colors[node] + 1) % 2;

            if (!isBipartite(adj, nbr, colors)) return false;
        }

        return true;
    } 

    int getLongestShortestPath(unordered_map<int, vector<int>> adjList, int srcNode, int n) {
        queue<int> nodes;
        vector<bool> visited(n+1,false);

        nodes.push(srcNode);
        visited[srcNode] = true;
        int distance = 0;

        while (!nodes.empty()) {
            int numOfNodesInLayer = nodes.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodes.front();
                nodes.pop();
                for (int neighbor : adjList[currentNode]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    nodes.push(neighbor);
                }
            }

            distance++;
        }

        return distance;
    }
    
    int getNumberOfGroups(unordered_map<int, vector<int>> adjList, int node, vector<int> &distances, vector<bool> &visited) {
        int maxNumberOfGroups = distances[node];
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (visited[neighbor]) continue;
            maxNumberOfGroups = max(maxNumberOfGroups,
                                    getNumberOfGroups(
                                        adjList, neighbor, distances, visited));
        }
        return maxNumberOfGroups;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] != -1) continue;

            color[i] = 0;

            if (!isBipartite(adj, i, color)) return -1;
        }

        vector<int> distance(n + 1);

        for (int i = 1; i <= n; i++) {
            distance[i] = getLongestShortestPath(adj,i,n);
        }

        int maxGroups = 0;

        vector<bool> vis(n + 1, false);

        for (int i = 0; i <= n; i++) {
            if (vis[i]) continue;

            maxGroups += getNumberOfGroups(adj,i,distance, vis);
        }

        return maxGroups;
    }
};

int main()
{
    vector<vector<int>> edges = {
        {1,2} , {1,4} , {1,5} , {2,6} , {2,3} , {4,6}
    };

    int n = 6;

    Solution sol;

    cout << sol.magnificentSets(n,edges);
    return 0;
}