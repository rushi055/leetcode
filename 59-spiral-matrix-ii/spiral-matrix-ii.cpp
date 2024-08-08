class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> final(n, vector<int>(n, 0));

        int dir = 0;
        int top = 0;
        int bottom = n - 1;
        int right = n - 1;
        int left = 0;
        int k = 1;

        while (top <= bottom && right >= left) {
            if (dir == 0) {
                for (int i = left; i <= right; i++) {
                    final[top][i] = k;
                    k++;
                }
                top++;
            }
            if (dir == 1) {
                for (int i = top; i <= bottom; i++) {

                    final[i][right] = k;
                    k++;
                }
                right--;
            }
            if (dir == 2) {
                for (int i = right; i >= left; i--) {

                    final[bottom][i] = k;
                    k++;
                }
                bottom--;
            }
            if (dir == 3) {
                for (int i = bottom; i >= top; i--) {

                    final[i][left] = k;
                    k++;
                }
                left++;
            }
            dir++;
            if (dir == 4) {
                dir = 0;
            }
        }
        return final;
    }
};