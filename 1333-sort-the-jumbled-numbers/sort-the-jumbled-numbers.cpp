class Solution {
public:
    int getMappedNum(int num, vector<int>& mapping) {
        if (num < 10) {
            return mapping[num];
        }

        int mappedNum = 0;
        int plaveValue = 1;

        while (num) {
            int lastDigit = num % 10;
            int mappedDigit = mapping[lastDigit];
            mappedNum += plaveValue * mappedDigit;

            plaveValue *= 10;
            num /= 10;
        }

        return mappedNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++) {
            int mappedNum = getMappedNum(nums[i], mapping);

            vec.push_back({mappedNum, i});
        }

        sort(begin(vec), end(vec));
        vector<int> result;

        for (auto& p : vec) {
            int orgNumIdx = p.second;
            result.push_back(nums[orgNumIdx]);
        }
        return result;
    }
};