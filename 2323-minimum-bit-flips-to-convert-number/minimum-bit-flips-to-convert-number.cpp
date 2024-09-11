class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int size = sizeof(ans) * 8;
        int count = 0;

        while (ans > 0) {
            int k = ans % 2;
            if (k == 1) {
                count++;
            }
            ans = ans / 2;
        }
        return count;
    }
};