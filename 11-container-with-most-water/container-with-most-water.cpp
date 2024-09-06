class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxA = 0;

        while (i < j) {
            int area = (min(height[i], height[j]) * (j - i ));
            cout<< area <<endl;
            maxA = max(maxA, area);
            if (height[i] >= height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return maxA;
    }
};