#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> answer(queries.size(), false);

        if (prerequisites.size() == 0)
            return answer;

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[a].push_back(b);
        }

        vector<int> indegree(numCourses);

        for (int i = 0; i < numCourses; i++) {
            for (auto j : adj[i]) {
                indegree[j]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nbr : adj[node]) {
                isReachable[node][nbr] = true;

                for (int i = 0; i < numCourses; i++) {
                    if (isReachable[i][node]) {
                        isReachable[i][nbr] = true;
                    }
                }
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            answer[i] = isReachable[u][v];
        }

        return answer;
    }
};

int main()
{
    int numCourses = 3;

    vector<vector<int>> prerequisites = {
        {1,2} , {1,0} , {2,0}
    };

    vector<vector<int>> queries = {
        {1,0}, {1,2}
    };

    Solution sol;

    vector<bool> result = sol.checkIfPrerequisite(numCourses, prerequisites, queries);

    for (int i = 0; i < result.size(); i++) {
        if (result[i]) {
            cout << "true ";
        } else {
            cout << "false ";
        }
    }
    return 0;
}