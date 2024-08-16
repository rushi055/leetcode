class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int minValue = arrays[0][0];
        int maxValue = arrays[0].back();
        int maxd = INT_MIN;

        for (int i = 1; i < n; i++) {
            maxd = max(maxd, abs(arrays[i].back() - minValue));
            maxd = max(maxd, abs(maxValue - arrays[i][0]));

            minValue = min(minValue, arrays[i][0]);
            maxValue = max(maxValue, arrays[i].back());
        }

        return maxd;
    }
};