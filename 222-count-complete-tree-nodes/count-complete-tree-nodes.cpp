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
    int k = 0;
    int solve(TreeNode* root, int& k) {
        if (!root) {
            return k;
        }
        k++;
        solve(root->left,k);
        solve(root->right,k);

        return k;
    }
    int countNodes(TreeNode* root) {
        
        return solve(root, k);
    }
};