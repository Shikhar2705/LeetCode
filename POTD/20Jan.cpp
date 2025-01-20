#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        int n = arr.size();
        vector<pair<int,int>> matIndex(row*col + 1);
        vector<int> rowPainted(row, 0);
        vector<int> colPainted(col, 0);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int value = mat[i][j];

                matIndex[value] = make_pair(i,j);
            }
        }

        for (int i = 0; i < n; i++) {
            auto idx = matIndex[arr[i]];
            int r = idx.first;
            int c = idx.second;

            rowPainted[r]++;
            colPainted[c]++;

            if (rowPainted[r] == col || colPainted[c] == row)
                return i;
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Solution sol;
    cout << sol.firstCompleteIndex(arr, mat) << endl;
    return 0;
}