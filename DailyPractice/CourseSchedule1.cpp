#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto nbr : adj[node]) {
                inorder[nbr]--;
                if (inorder[nbr] == 0)
                    q.push(nbr);
            }
        }

        return count == numCourses;
    }
};

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {
        {1,0},{0,1}
    }; 

    Solution sol;

    if (sol.canFinish(numCourses, prerequisites)) {
        cout << "Student can finish all courses" << endl;
    } else
    {
        cout << "Student cannot finish all courses" << endl;
    }
    
    return 0;
}