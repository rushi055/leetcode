class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for (int num : nums) {
            st.insert(num);
        }
        nums.clear();
        for (int num : st) {
            nums.push_back(num);
        }
        return nums.size();
    }
};