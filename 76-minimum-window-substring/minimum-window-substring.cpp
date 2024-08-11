class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int> mp;

        for (auto it : t) {
            mp[it]++;
        }
        int start_i = 0;
        int requiredCount = t.length();
        int i = 0, j = 0;
        int minWindow = INT_MAX;

        while (j < n) {
            char ch = s[j];
            if (mp[ch] > 0) {
                requiredCount--;
            }
            mp[ch]--;

            while (requiredCount == 0) {
                if (minWindow > j - i + 1) {
                    minWindow = j - i + 1;
                    start_i = i;
                }
                char ch_i = s[i];
                mp[ch_i]++;

                if (mp[ch_i] > 0) {
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        return minWindow == INT_MAX ? "" : s.substr(start_i, minWindow);
    }
};