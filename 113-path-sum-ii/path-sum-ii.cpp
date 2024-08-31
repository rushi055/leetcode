/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(TreeNode* root, int targetSum, vector<int>& temp, int sum) {
        if (!root) {
            return;
        }
        sum += root->val;
        temp.push_back(root->val);

        if (sum == targetSum && !root->left && !root->right) {
            ans.push_back(temp);
        }
        solve(root->left, targetSum, temp, sum);
        solve(root->right, targetSum, temp, sum);

        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        solve(root, targetSum, temp, 0);

        return ans;
    }
};