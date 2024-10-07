class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        int i = 0;
        stack<char> st;

        while (i != n ) {
            if (st.empty()) {
                st.push(s[i]);
            } else if (st.top() == 'A' && s[i] == 'B') {
                st.pop();

            } else if (st.top() == 'C' && s[i] == 'D') {
                st.pop();
            } else {
                st.push(s[i]);
            }

            i++;
        }

        return st.size();
    }
};