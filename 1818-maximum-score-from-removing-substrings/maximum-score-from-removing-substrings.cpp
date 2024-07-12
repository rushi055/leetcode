// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        string first_pass = removeSubstring(s, maxStr);
        int removedPairs = (n - first_pass.length()) / 2;
        score += removedPairs * max(x, y);

        string second_pass = removeSubstring(first_pass, minStr);
        removedPairs = (first_pass.length() - second_pass.length()) / 2;
        score += removedPairs * min(x, y);

        return score;
    }

private:
    string removeSubstring(string& s, string& matchStr) {
        stack<char> st;

        for (char& ch : s) {
            if (ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string remainStr;
        while (!st.empty()) {
            remainStr.push_back(st.top());
            st.pop();
        }
        reverse(remainStr.begin(), remainStr.end());
        return remainStr;
    }
};
