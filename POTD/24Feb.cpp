#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
    private:    
        int dfs(int src, int parent, int time, int bob, vector<int>&amount, unordered_map<int, vector<int>>& adjList, vector<int>& bobPath, int n) {
            int maxAmount = 0, maxChild = INT_MIN;
    
            if (src == bob) {
                bobPath[src] = 0;
            }
            else {
                bobPath[src] = n;
            }
    
            for (int nbr : adjList[src]) {
                if (nbr != parent) {
                    maxChild = max(maxChild, dfs(nbr, src, time + 1, bob, amount, adjList, bobPath, n));
    
                    bobPath[src] = min(bobPath[src], bobPath[nbr] + 1);
                }
            }
    
            if (bobPath[src] > time) maxAmount += amount[src];
            else if (bobPath[src] == time) maxAmount += amount[src] / 2;
            
    
            return (maxChild == INT_MIN) ? maxAmount : maxAmount + maxChild;
        }
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();
            unordered_map<int, vector<int>> adjList;
    
            for (auto edge : edges) {
                adjList[edge[0]].push_back(edge[1]);
                adjList[edge[1]].push_back(edge[0]);
            }
            vector<int> bobPath(n);
    
            return dfs(0, 0, 0, bob, amount, adjList, bobPath, n);
        }
    };

int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}};
    int bob = 3;
    vector<int> amount = {0, 2, 4, 6};
    
    int result = sol.mostProfitablePath(edges, bob, amount);
    cout << "The most profitable path amount is: " << result << endl;
    return 0;
}