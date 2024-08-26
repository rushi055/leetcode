/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //     vector<int> preorder(Node* root) {
    //           vector<int> ans;
    //         if (root == nullptr)
    //             return ans;
    //         stsck<Node*> st;
    //         st.push(root);
    //         while (!st.empty()) {
    //             Node* node = st.front();
    //             st.pop();
    //             ans.push_back(node->val);

    //             for (Node* child : node->children) {
    //                 st.push(child);
    //             }
    //         }
    //         //reverse(ans.begin(), ans.end());
    //         return ans;
    //     }
    // }
    void preorderHelper(Node* root, vector<int>& result) {
        if (root == nullptr)
            return;

        result.push_back(root->val); 

        for (Node* child : root->children) {
            preorderHelper(child, result);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
};
;