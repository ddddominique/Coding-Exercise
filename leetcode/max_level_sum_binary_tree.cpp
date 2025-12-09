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
public:
    int maxLevelSum(TreeNode* root) {
        int result = root->val;
        int my_level = 1;
        queue<TreeNode*> q;
        q.push(root);
        int curr_level = 0;
        while (!q.empty()) {
            curr_level++;
            int n = q.size();
            int curr_sum = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                curr_sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (curr_sum > result) {my_level = curr_level; result = curr_sum;}

        }
        return my_level;
    }
};
