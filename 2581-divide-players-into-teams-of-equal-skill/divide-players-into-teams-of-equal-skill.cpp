class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int constant = skill[0] + skill[n - 1];

        long long ans = 0;

        for (int i = 0; i < n / 2; i++) {
            int k = skill[i] + skill[n - i - 1];
            if (constant == k) {
                ans += ((long long)skill[i] * (long long)skill[n - i - 1]);

            } else {
                return -1;
            }
        }
        return ans;
    }
};