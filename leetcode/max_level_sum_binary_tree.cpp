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
        int mymax = root->val;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int result = 1;
        while (!q.empty()) {
            level++;
            int size = q.size();
            int level_sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (!node) {level_sum += 0;} else {
                level_sum += node->val;
                }


                if (i == size - 1) {
                    if (level_sum > mymax) {
                        result = level;
                        mymax = level_sum;
                    }
                }
                if (node->left) {q.push(node->left);}
                if (node->right) {q.push(node->right);}

            }
        }
        return result;

    }
};