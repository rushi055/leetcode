class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.length();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;

                bool valid = false;
                for (int f : freq) {
                    if (f >= k) {
                        valid = true;
                        break;
                    }
                }
                if (valid) {
                    result++;
                }
            }
        }

        return result;
    }
};
