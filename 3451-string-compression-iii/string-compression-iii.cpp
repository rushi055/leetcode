class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.length();
        if (n == 0)
            return ans;

        int k = 0;
        char c = word[0];

        for (int i = 0; i <= n; i++) {
            if (k >= 9) {
                ans += to_string(k);
                ans.push_back(c);
                k = 0;
            }
            if (i < n && word[i] == c) {
                k++;
            } else {
                if (k > 0) {
                    ans += to_string(k);
                    ans.push_back(c);
                }
                if (i < n) {
                    c = word[i];
                    k = 1;
                }
            }
        }

        return ans;
    }
};
