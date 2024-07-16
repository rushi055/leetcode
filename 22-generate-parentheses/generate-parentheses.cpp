class Solution {
public:
    void generate(string s, int i, int j, vector<string>& ans) {
        if (i == 0 && j == 0) {
            ans.push_back(s);
            return;
        }
        if (i > 0) {
            generate(s + '(', i - 1, j, ans);
        }
        if (j > i) {
            generate(s + ')', i, j - 1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generate("", n, n, ans);
        return ans;
    }
};