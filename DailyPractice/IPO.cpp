#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> project;

        int n = profits.size();

        for (int i = 0; i < n; i++) {
          project.push_back(make_pair(capital[i],profits[i]));
        }

        sort(project.begin(), project.end());

        priority_queue<int> pq;

        int i = 0;

        while (k--) {
          while (i < n && project[i].first <= w) {
            pq.push(project[i].second);
            i++;
          }
          if (pq.empty()) 
            break;

          w += pq.top();
          pq.pop();
        }

        return w;
    }
};

int main()
{
    vector<int> profits = {1,2,3};

    vector<int> capital = {0,1,1};

    int k = 2, w = 0;

    Solution s;

    cout << s.findMaximizedCapital(k,w,profits,capital) << endl;
    
    return 0;
}