// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */


//TLE

// class Solution {
// public:
//     int height(TreeNode* root) {
//         if (!root) {
//             return 0;
//         }
//         int l = height(root->left);
//         int r = height(root->right);
//         return 1 + max(l, r);
//     }

//     int solve(TreeNode*& root, vector<int>& queries, int i) {
//         if (root == nullptr) {
//             return 0;
//         }

//         if (root->left && root->left->val == queries[i]) {
//             return height(root->right)+1;
//         }
//         if (root->right && root->right->val == queries[i]) {
//             return height(root->left)+1;
//         }
//         int leftHeight = solve(root->left, queries, i);
//         int rightHeight = solve(root->right, queries, i);
//         return max(leftHeight, rightHeight)+1;
//     }

//     vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
//         vector<int> ans(queries.size());

//         for (int i = 0; i < queries.size(); i++) {
//             ans[i] = solve(root, queries, i)-1;
//         }

//         return ans;
//     }
// };


//Approach - Simple Recursion and preprocessing
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int level[1000001]; //level of each node
    int height[100001]; //height of each node
    int levelMaxHt[100001];
    int levelSecondMaxHt[100001];

    int findHeight(TreeNode* root, int l) {
        if(!root) {
            return 0;
        }

        level[root->val] = l;
        height[root->val] = max(findHeight(root->left, l+1), findHeight(root->right, l+1)) + 1;

        if(levelMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = levelMaxHt[l];
            levelMaxHt[l] = height[root->val];
        } else if(levelSecondMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root, 0);

        vector<int> result;

        for(int &node : queries) {
            //node = that we have to delete
            int L = level[node]; //O(1) //node ka level hai ye

            //L + H - 1

            int tempResult = L + (levelMaxHt[L] == height[node] ? levelSecondMaxHt[L] : levelMaxHt[L]) - 1;

            result.push_back(tempResult);
        } 

        return result;
    }
};