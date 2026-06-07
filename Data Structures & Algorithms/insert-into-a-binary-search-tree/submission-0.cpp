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
    TreeNode* x = nullptr;
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) {
            TreeNode* p = new TreeNode(val);
            root = p;
        }
        if(x==nullptr) x=root;
        if(root->val<val) {
            if(!root->right) {
                TreeNode* p = new TreeNode(val);
                root->right = p;
                return x;
            }
            return insertIntoBST(root->right,val);
        }
        if(root->val>val) {
            if(!root->left) {
                TreeNode* p = new TreeNode(val);
                root->left = p;
                return x;
            }
            return insertIntoBST(root->left,val);
        }
        return x;
    }
};