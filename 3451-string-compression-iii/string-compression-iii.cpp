class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.length();
        int i = 0;

        while (i < n) {
            char c = word[i];
            int k = 0;
            while (i < n && word[i] == c && k < 9) {
                k++;
                i++;
            }
            ans += to_string(k);
            ans.push_back(c);
        }

        return ans;
    }
};
