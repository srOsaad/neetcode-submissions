/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> x;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        x.clear();
        dfs(root);
        return x;
    }

    void dfs(TreeNode* root) {
        if(!root) return;
        if(root->left) dfs(root->left);
        x.push_back(root->val);
        if(root->right) dfs(root->right);
    }
};