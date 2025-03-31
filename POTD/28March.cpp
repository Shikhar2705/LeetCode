#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int row = grid.size();
        int col = grid[0].size();
        int k = queries.size();
        
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < k; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        visited[0][0] = true;

        vector<int> ans(k, 0);
        int currPoints = 0;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto query : sortedQueries) {
            int queryValue = query.first;
            int queryIndex = query.second;
            while (!pq.empty() && pq.top().first < queryValue) {
                auto top = pq.top();
                int val = top.first;
                pair<int,int> pos = top.second;
                pq.pop();

                int r = pos.first, c = pos.second;
                currPoints++;

                for (auto dir : directions) {
                    int newR = r + dir.first;
                    int newC = c + dir.second;
                    if (newR >= 0 && newR < row && newC >= 0 && newC < col && !visited[newR][newC]) {
                        visited[newR][newC] = true;  
                        pq.push({grid[newR][newC], {newR, newC}});
                    }
                }
            }
            ans[queryIndex] = currPoints;
        }

        return ans;
    }
};    

int main()
{
    Solution solution;
    vector<vector<int>> grid = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
    vector<int> queries = {5, 6, 2};
    vector<int> result = solution.maxPoints(grid, queries);
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}