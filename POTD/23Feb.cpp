#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:    
    TreeNode* recover(int preStart, int preEnd, int postStart, vector<int>& preorder, vector<int>& postorder, vector<int> postorderIndex) {
        if (preStart > preEnd) return NULL;

        if (preStart == preEnd) return new TreeNode(preorder[preStart]);
        
        TreeNode* root = new TreeNode(preorder[preStart]);

        int leftRoot = preorder[preStart + 1];

        int nodesInLeft = postorderIndex[leftRoot] - postStart + 1;

        root->left = recover(preStart + 1, preStart + nodesInLeft, postStart, preorder, postorder, postorderIndex);

        root->right = recover(preStart + nodesInLeft + 1, preEnd, postStart + nodesInLeft, preorder, postorder, postorderIndex);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();

        vector<int> postorderIndex(n + 1);

        for (int i = 0; i < n; i++) {
            postorderIndex[postorder[i]] = i;
        }

        return recover(0,n-1,0,preorder,postorder, postorderIndex);
    }

    void dfs(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
};

int main()
{
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};

    Solution sol;

    TreeNode* root = sol.constructFromPrePost(preorder, postorder);
    sol.dfs(root);

    return 0;
}