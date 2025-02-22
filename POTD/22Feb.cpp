#include <iostream>
#include <vector>
#include <string>
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
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> level;
        
        for (int i = 0; i < traversal.size();) {
            int depth = 0;

            while (i < traversal.size() && traversal[i] == '-') {
                depth++;
                i++;
            }

            int val = 0;

            while(i < traversal.size() && isdigit(traversal[i])) {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            if (depth < level.size()) {
                level[depth] = node;
            }
            else {
                level.push_back(node);
            }

            if (depth > 0) {
                TreeNode* parent = level[depth - 1];
                if (!parent->left) {
                    parent->left = node;
                }
                else {
                    parent->right = node;
                }
            }
        } 
        return level[0];
    }

    void preOrder(TreeNode* root, vector<int>& preorder) {
        if (!root) return;
        preorder.push_back(root->val);
        preOrder(root->left, preorder);
        preOrder(root->right, preorder);
    }
};

int main()
{
    string traversal = "1-2--3--4-5--6--7";

    Solution sol;

    TreeNode* root = sol.recoverFromPreorder(traversal);

    vector<int> preorder;

    sol.preOrder(root, preorder);

    for (int i = 0; i < preorder.size(); i++) {
        cout << preorder[i] << " ";
    }

    return 0;
}