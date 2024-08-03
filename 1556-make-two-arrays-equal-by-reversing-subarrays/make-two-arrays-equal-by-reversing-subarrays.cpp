class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(begin(arr), end(arr));
        sort(begin(target), end(target));
        return target==arr;
    }
};