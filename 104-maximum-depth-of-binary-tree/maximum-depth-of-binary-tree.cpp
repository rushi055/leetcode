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
    int solve(TreeNode* root, int count) {
        if (!root) {
            return count;
        }
        if (!root->left && !root->right) {
            ans = max(ans, count);
        }
        int l = solve(root->left, count + 1);
        int r = solve(root->right, count + 1);
        return max(l, r);
    }
    int maxDepth(TreeNode* root) { return solve(root, 0); }
};