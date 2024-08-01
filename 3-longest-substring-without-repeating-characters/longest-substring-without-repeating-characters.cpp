class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxL = 0;
        int start = 0;

        for (int end = 0; end < s.length(); end++) {
            if (mp.find(s[end]) != mp.end()) {
                start = max(start, mp[s[end]] + 1);
            }
            mp[s[end]] = end;
            maxL = max(maxL, end - start + 1);
        }

        return maxL;
    }
};

---------\---------------------\------------------------------\----------------------------------\------------------\-----------------------------\---------------------\------------------------------\----------------------------------\------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxL = 0;
        int start = 0;

        for (int end = 0; end < s.length(); end++) {
            if (mp.find(s[end]) != mp.end()) {
                start = max(start, mp[s[end]] + 1);
            }
            mp[s[end]] = end;
            maxL = max(maxL, end - start + 1);
        }

        return maxL;
    }
};
