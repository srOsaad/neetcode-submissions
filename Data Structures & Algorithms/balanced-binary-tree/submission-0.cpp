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
    vector<int> levels;
public:
    bool isBalanced(TreeNode* root, int level = 0) {
        if(!root) {
            if(level == 0) return true;
            levels.push_back(level);
        }
        else {
            isBalanced(root->left, level + 1);
            isBalanced(root->right, level + 1);
        }

        if(level == 0) {
            int Min = INT_MAX, Max = INT_MIN;

            for(auto x : levels) {
                Min = min(Min, x);
                Max = max(Max, x);
            }

            return Max - Min < 2;
        }
        return false; // doesn't matter
    }
};
