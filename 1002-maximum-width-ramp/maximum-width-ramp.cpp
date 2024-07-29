const auto init = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    return nullptr;
}();

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                ans = max(ans, i - st.top());
                st.pop();
            }
        }
        return ans;
    }
};