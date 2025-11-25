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
    int result = 0;
    void helper(TreeNode* node, bool lr, int curr_max) {
        if (!node) {return;}
        result = max(result, curr_max);
        if (lr) {
            helper(node->right, 0, curr_max + 1);
            helper(node->left, 1, 1);
        } else {
            helper(node->left, 1, curr_max + 1);
            helper(node->right, 0, 1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        helper(root->left, 1, 1);
        helper(root->right, 0, 1);
        return result;
    }
};
