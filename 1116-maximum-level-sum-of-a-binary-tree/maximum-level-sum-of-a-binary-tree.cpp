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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }
        int ans=0;

        vector<pair<int,int>> v;

        queue<TreeNode*> q;
        q.push(root);

        int k=0;

        while (!q.empty()) {
            int size = q.size();
            int z = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                z += node->val;
            }
            k++;
            v.push_back({z,k});
        }

        sort(v.begin(), v.end());
        int n = v.size();

        for(int i=0;i<v.size();i++){
            if(v[i].first==v[n - 1].first){
                ans = v[i].second;
                break;
            }
        }

        return ans;
    }
};