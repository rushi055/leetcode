class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long totalChalk = 0;

        for (int i = 0; i < n; i++) {
            totalChalk += chalk[i];
        }

        k %= totalChalk;

        for (int i = 0; i < n; i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        return -1;
    }
};
