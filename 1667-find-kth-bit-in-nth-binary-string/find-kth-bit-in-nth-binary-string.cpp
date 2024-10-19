class Solution {
public:
    char findKthBit(int n, int k) {

        vector<string> v(20);
        v[0] = "0";
        for (int i = 1; i < 20; i++) {
            string s = v[i - 1];
            reverse(s.begin(), s.end());

            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '0') {
                    s[j] = '1';
                } else {
                    s[j] = '0';
                }
            }
            v[i] = v[i - 1] + "1" + s;
        }

        return v[n-1][k - 1];
    }
};