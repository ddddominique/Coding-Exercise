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
    bool dfs(TreeNode* root, long long mymax, long long mymin) {
        if (root == nullptr) return true;
        if (root->val < mymax && root->val > mymin) {
            return dfs(root->left, root->val, mymin) && dfs(root->right, mymax, root->val);
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MAX, LLONG_MIN);
    }
};
