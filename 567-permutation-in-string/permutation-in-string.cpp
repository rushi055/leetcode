class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) {
            return false;
        }
        map<char, int> mp;
        for (char c : s1) {
            mp[c]++;
        }

        for (int i = 0; i <= n2 - n1; i++) {
            map<char, int> temp = mp;
            string s = s2.substr(i, n1);
            bool perm = true;

            for (int j = 0; j < n1; j++) {
                if (temp.find(s[j]) != temp.end()) {
                    temp[s[j]]--;
                    if (temp[s[j]] == 0) {
                        temp.erase(s[j]);
                    }
                } else {
                    perm = false;
                    break;
                }
            }

            if (perm && temp.empty()) {
                return true;
            }
        }

        return false;
    }
};
