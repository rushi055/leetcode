class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp;
        vector<string> ans;

        int idx1 = 0;
        for (int i = 0; i <= s1.length(); i++) {
            if (i == s1.length() || s1[i] == ' ') {
                string s = s1.substr(idx1, i - idx1);
                mp[s]++;
                idx1 = i + 1;
            }
        }

        int idx2 = 0;
        for (int i = 0; i <= s2.length(); i++) {
            if (i == s2.length() || s2[i] == ' ') {
                string s = s2.substr(idx2, i - idx2);
                mp[s]++;
                idx2 = i + 1;
            }
        }

        for (auto it : mp) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
