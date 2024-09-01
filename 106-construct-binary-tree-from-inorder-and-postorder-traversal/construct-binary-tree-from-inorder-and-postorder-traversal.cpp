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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int& idx) {
        if (start > end) {
            return NULL;
        }

        int ans = postorder[idx];

        int i;
        for (i = start; i <= end; i++) {
            if (inorder[i] == ans) {
                break;
            }
        }
        idx--;

        TreeNode* node = new TreeNode(ans);

        // Construct the right subtree first because in postorder, the right subtree comes before the left subtree.
        node->right = solve(inorder, postorder, i + 1, end, idx);
        node->left = solve(inorder, postorder, start, i - 1, idx);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n - 1;

        return solve(inorder, postorder, 0, n - 1, idx);
    }
};
