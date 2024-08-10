class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1, -1, -1};
        int result = 0;
        int n = s.length();

        for (int j = 0; j < n; j++) {
            lastSeen[s[j] - 'a'] = j;

            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                result += (min(lastSeen[0], min(lastSeen[1], lastSeen[2])) + 1);
            }
        }

        return result;
    }
};
