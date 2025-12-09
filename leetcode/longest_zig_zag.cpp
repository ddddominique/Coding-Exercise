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
    void dfs(TreeNode* root, int indicator, int currlen) {
        if (!root) {return;}
        result = max(result, currlen);
        if (indicator) {
            dfs(root->right, 0, currlen + 1);
            dfs(root->left, 1, 1); // same reason here
        } else {
            dfs(root->left, 1, currlen + 1);
            dfs(root->right, 0, 1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        dfs(root->left, 1, 1);
        dfs(root->right, 0, 1); // start with 1 bc u already made a zigzag
        return result;
    }
};
