class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        int ans = INT_MIN;

        for (int j = 0; j < n; j++) {
            long long nxt = (long long)nums[j] * (long long)nums[j];
            int i = 1;
            while (st.find(nxt) != st.end()) {
                if (nxt > pow(10, 5)) {
                    break;
                }
                nxt = nxt * nxt;
                i++;
            }
            if (i >= 2) {
                ans = max(ans, i);
            }
        }
        return ans != INT_MIN ? ans : -1;
    }
};