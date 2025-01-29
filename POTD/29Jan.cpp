#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n) {
        size.resize(n+1,1);
        parent.resize(n+1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulpU = findUPar(u);
        int ulpV = findUPar(v);

        if (ulpU == ulpV) return ;

        if (size[ulpU] < size[ulpV]) {
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }
        else {
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisjointSet ds(n);

        int node1,node2;

        for (int i = 0; i < n; i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            if (ds.findUPar(a) != ds.findUPar(b)) {
                ds.unionBySize(a,b);
            }
            else {
                node1 = a;
                node2 = b;
            }
        }

        return {node1,node2};
    }
};

int main()
{
    vector<vector<int>> edges = {
        {1,2} , {3,1} , {2,3}
    };

    Solution sol;

    vector<int> redundant = sol.findRedundantConnection(edges);

    cout << redundant[0] << " " << redundant[1];
    return 0;
}