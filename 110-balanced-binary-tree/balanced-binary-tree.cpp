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
    int check(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = check(root->left);
        int r = check(root->right);
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = (abs(check(root->left) - check(root->right)) <= 1);

        if (left && right && diff) {
            return true;
        } else {
            return false;
        }
    }
};