class Solution {
public:

    //T.C : O(N*N)
    //S.C : O(N)
    string reverseParentheses(string s) {
        stack<int> skipLength;
        string ans;

        for (auto& ch : s) {
            if (ch == '(') {
                skipLength.push(ans.length());
            } else if (ch == ')') {
                int l = skipLength.top();
                skipLength.pop();
                reverse(begin(ans) + l, end(ans));
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};