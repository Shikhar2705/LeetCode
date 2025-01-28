#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[a].push_back(b);
        }

        vector<int> inorder(numCourses,0);

        for(int i = 0; i < numCourses; i++) {
            for (int j : adj[i]) {
                inorder[j]++;
            }
        }   

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inorder[i] == 0)
                q.push(i);
        }

        vector<int> order;
        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            order.push_back(node);

            for (auto nbr : adj[node]) {
                inorder[nbr]--;
                if (inorder[nbr] == 0)
                    q.push(nbr);
            }
        }

        reverse(order.begin(), order.end());

        return count == numCourses ? order : vector<int>{};
    }
};

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {
        {1,0}
    }; 

    Solution sol;

    vector<int> order = sol.findOrder(numCourses, prerequisites);

    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << " ";
    }  
    return 0; 
}