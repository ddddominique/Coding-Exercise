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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (!root) return result;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        while (!myqueue.empty()) {
            int currsize = myqueue.size();
            vector<int> currresult;
            for (int i = 0; i < currsize; ++i) {
                TreeNode* curr = myqueue.front();
                myqueue.pop();
                currresult.push_back(curr->val);
                if (curr->left) myqueue.push(curr->left);
                if (curr->right) myqueue.push(curr->right);
            }

            result.push_back(currresult);
        }
        return result;

    }
};