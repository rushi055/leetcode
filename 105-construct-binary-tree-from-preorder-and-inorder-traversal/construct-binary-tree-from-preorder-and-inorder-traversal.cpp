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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start,
                    int end, int& idx) {
        if (start > end) {
            return NULL;
        }

        int ans = preorder[idx];

        int i;
        for (i = start; i < end; i++) {
            if (inorder[i] == ans) {
                break;
            }
        }
        idx++;

        TreeNode* node = new TreeNode(ans);

        node->left = solve(preorder, inorder, start, i - 1, idx);
        node->right = solve(preorder, inorder, i + 1, end, idx);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = 0;

        return solve(preorder, inorder, 0, n - 1, idx);
    }
};