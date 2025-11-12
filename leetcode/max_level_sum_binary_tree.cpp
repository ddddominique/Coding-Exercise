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
        int result = 1; // level
        int curr_level = 0;
        int mymax = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int level_sum = 0;
            curr_level += 1;

            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;
                if (i == size - 1 && level_sum > mymax) {//last in the level
                    mymax = level_sum;
                    result = curr_level;
                }

                if (node->left) {q.push(node->left);}
                if (node->right) {q.push(node->right);}
            }
        }
        return result;

    }
};
