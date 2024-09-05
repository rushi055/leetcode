class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int size = rolls.size();

        int accumSum = accumulate(rolls.begin(), rolls.end(), 0);

        int x = (mean * (size + n)) - accumSum;

        if (x < n || x > 6 * n) {
            return ans;
        }

        int rem = x % n;
        int que = x / n;

        ans.assign(n, que);

        for (int i = 0; i < rem; i++) {
            ans[i] += 1;
        }

        return ans;
    }
};