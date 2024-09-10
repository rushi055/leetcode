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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            TreeNode* newN = new TreeNode(val);
            return newN;
        }

        if (root->val > val && !root->left) {
            TreeNode* newN = new TreeNode(val);
            root->left = newN;
            return root;
        }
        if (root->val < val && !root->right) {
            TreeNode* newN = new TreeNode(val);
            root->right = newN;
            return root;
        }

        if (!root->left && !root->right) {
            TreeNode* newN = new TreeNode(val);

            if (root->val > val) {
                root->left = newN;
                return root;
            } else {
                root->right = newN;
                return root;
            }
        }
        if (root->val > val) {
            insertIntoBST(root->left,val);
        } else {
            insertIntoBST(root->right,val);
        }
        return root;
    }
};