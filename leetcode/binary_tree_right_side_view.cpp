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
    void helper(TreeNode* root, stack<int>& hold) {
        if (root->left) {

        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        if (!root) {return result;}
        queue<TreeNode*> hold;
        hold.push(root);
        while(!hold.empty()) {
            int size = hold.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = hold.front();
                hold.pop();

                if (i== size- 1) {result.push_back(node->val);}
                if (node->left) {hold.push(node->left);}
                if (node->right) {hold.push(node->right);}

            }
        }
        return result;
    }
};