const auto init = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    return nullptr;
}();
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++;
            } else {
                st.push({c, 1});
            }
            if (st.top().second == k) {
                st.pop();
            }
        }

        string result;
        while (!st.empty()) {
            auto [ch, count] = st.top();
            st.pop();
            result.append(count, ch);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};