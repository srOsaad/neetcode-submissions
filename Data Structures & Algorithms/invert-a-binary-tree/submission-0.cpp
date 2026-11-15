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
public:
    TreeNode* invertTree(TreeNode* root, int depth = 0) {
        if(!root) return root;

        TreeNode* hold = root->left;
        root->left = root->right;
        root->right = hold;

        if(root->left) invertTree(root->left, depth + 1);
        
        if(root->right) invertTree(root->right, depth + 1);
        
        if(depth == 0) return root;
    }
};
