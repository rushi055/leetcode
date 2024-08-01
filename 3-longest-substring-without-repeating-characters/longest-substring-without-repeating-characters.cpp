class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxL = 0;

        for (int i = 0; i < s.length(); i++) {
            unordered_map<char, int> mp;

            for (int j = i; j < s.length(); j++) {
                if (mp.find(s[j]) != mp.end()) {
                    break;
                } else {
                    mp[s[j]] = 1;
                    maxL = max(maxL, j - i + 1);
                }
            }
        }
        return maxL;
    }
};