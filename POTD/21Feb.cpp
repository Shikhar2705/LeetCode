#include <iostream>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
private:    
    void recover(TreeNode* root, int val) {
        if (!root) return ;

        root->val = val;
        visited.insert(val);

        recover(root->left, 2 * val + 1);
        recover(root->right, 2 * val + 2);
    }
public:
    TreeNode* root;
    set<int> visited;
    FindElements(TreeNode* tree) {
        this->root = tree;

        recover(root, 0);
    }
    
    bool find(int target) {
        return visited.find(target) != visited.end();
    }
};

int main()
{
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(-1);

    FindElements* obj = new FindElements(root);
    cout << obj->find(1) << endl; // Output: 1 (true)
    cout << obj->find(3) << endl; // Output: 1 (true)
    cout << obj->find(5) << endl; // Output: 0 (false)

    delete obj;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}