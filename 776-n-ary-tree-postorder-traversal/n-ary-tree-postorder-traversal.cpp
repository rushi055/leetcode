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
    // void solve(Node* root, vector<int> &ans) {
    //     if (root == NULL) {
    //         return;
    //     }
    //     for (Node* child : root->children) {
    //         solve(child, ans);
    //     }
    //     ans.push_back(root->val);
    // }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            ans.push_back(node->val);

            for (Node* child : node->children) {
                st.push(child);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};