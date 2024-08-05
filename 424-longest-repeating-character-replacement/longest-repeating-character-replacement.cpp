class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> countMap;
        int maxCount = 0;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            countMap[s[right]]++;
            maxCount = max(maxCount, countMap[s[right]]);

            if ((right - left + 1) - maxCount > k) {
                countMap[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};