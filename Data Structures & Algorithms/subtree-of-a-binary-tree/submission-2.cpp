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
    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool inCheck = false) {
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr || subRoot == nullptr) return false;
        
        if(root->val == subRoot->val) {
            if(isSubtree(root->left, subRoot->left , true) && isSubtree(root->right, subRoot->right, true)) return true;
        }
        else if(inCheck) return false;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
