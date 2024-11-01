class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        set<int> st;
        int n = s.length();
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2] && s[i + 1] == s[i + 2]) {
                st.insert(i);
            }
        }
        int j = 0;
        for (int i = 0; i < n ; i++) {
            if (st.find(i) != st.end()) {
                continue;
            } else {
                ans.push_back(s[i]);
                j++;
            }
        }
        return ans;
    }
};