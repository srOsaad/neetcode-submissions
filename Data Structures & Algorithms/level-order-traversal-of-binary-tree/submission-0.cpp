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
    map<int, vector<int>> ans;
    int highest_level = 0;
    void bfs(TreeNode* root, int level = 1) {
        if(root->left) {
            ans[level].push_back(root->left->val);
            highest_level = max(highest_level, level + 1);
            bfs(root->left, level + 1);
        }
        if(root->right) {
            ans[level].push_back(root->right->val);
            highest_level = max(highest_level, level + 1);
            bfs(root->right, level + 1);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        ans[0].push_back(root->val);
        highest_level = 1;
        bfs(root);

        vector<vector<int>> answer;

        for(int i = 0; i<highest_level; i++) {
            answer.push_back(ans[i]);
        }

        return answer;
    }
};
