#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() == 0)
            return 0;
        int row = heightMap.size();
        int col = heightMap[0].size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        vector<vector<int>> vis(row, vector<int>(col, 0));

        int ans = 0, Max = INT_MIN;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(!(i==0 || i==row-1 || j==0 || j==col-1)) continue;

                pq.push({heightMap[i][j], i*col+j});
                vis[i][j] = 1;
            }
        }

        vector<vector<int>> dir{{-1,0}, {0,1}, {0,-1}, {1,0}};

        while (!pq.empty()) {
            auto val = pq.top();
            pq.pop();

            int height = val.first, x = val.second / col, y = val.second % col;

            Max = max(Max, height);

            for (auto d : dir) {
                int newx = x + d[0], newy = y + d[1];

                if (newx >= row || newx < 0 || newy >= col || newy < 0 || vis[newx][newy]) continue;

                vis[newx][newy] = 1;

                if (heightMap[newx][newy] < Max) ans += Max - heightMap[newx][newy];

                pq.push({heightMap[newx][newy], newx*col+newy});
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> heightMap = {{1,4,3,1,3,2},
                                      {3,2,1,3,2,4},
                                      {2,3,3,2,3,1}};

    Solution obj;

    cout << obj.trapRainWater(heightMap) << endl;
    
    return 0;
}