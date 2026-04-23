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
    vector<vector<int>> result;

    void dfs(TreeNode* root, int target, vector<int>& path) {
        if (!root) return;

        // add current node
        path.push_back(root->val);

        // check leaf
        if (!root->left && !root->right && target == root->val) {
            result.push_back(path);
        }

        // go deeper
        dfs(root->left, target - root->val, path);
        dfs(root->right, target - root->val, path);

        // backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }
};