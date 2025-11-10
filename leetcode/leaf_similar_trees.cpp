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
    void myleaves(TreeNode* root, vector<int>& leaf) {
        if (!root) return;
        if (!root->left && !root->right) {
            leaf.push_back(root->val);
        }
        myleaves(root->left, leaf);
        myleaves(root->right, leaf);

    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves_1, leaves_2;
        myleaves(root1, leaves_1);
        myleaves(root2, leaves_2);
        return leaves_1 == leaves_2;
    }
};