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
    int ans = INT_MIN;
    int solve(TreeNode* root, int& ans) {
        if (!root) {
            return 0;
        }
        int l = max(0, solve(root->left, ans));

        int r = max(0, solve(root->right, ans));

        ans = max(ans, root->val + l + r);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }

        solve(root, ans);
        return ans;
    }
};