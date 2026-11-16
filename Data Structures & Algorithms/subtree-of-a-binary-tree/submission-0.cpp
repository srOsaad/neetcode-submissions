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
    bool checkFromhere(TreeNode* x, TreeNode* y) {
        if((x == nullptr && y == nullptr)) return true;
        if((x == nullptr || y == nullptr) || (x->val != y->val)) return false;
        return checkFromhere(x->left, y->left) && checkFromhere(x->right, y->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr || subRoot == nullptr) return false;
        if(root->val == subRoot->val && checkFromhere(root, subRoot)) return true;
        return (root->left!=nullptr && root->left->val == subRoot->val && checkFromhere(root->left, subRoot)) || (root->right!=nullptr && root->right->val == subRoot->val && checkFromhere(root->right, subRoot));
    }
};
