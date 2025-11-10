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
    int helper(TreeNode* root, int curr_max) {
        int isit = 0;
        if (!root) {return 0;}
        if (root->val >= curr_max) {
            curr_max = root->val;
            isit = 1;
        }
        return isit + helper(root->left, curr_max) + helper(root->right, curr_max);

    }
public:
    int goodNodes(TreeNode* root) {
        int max = root->val;
        return helper(root, max);
    }
};