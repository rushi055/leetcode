class Solution {
public:
    int reverse(int x) {
        int sign = (x < 0) ? -1 : 1;
        x = abs(x);
        int reverse = 0;

        while (x != 0) {
            int num = x % 10;
            x /= 10;
            if ((reverse > INT_MAX / 10) || (reverse < INT_MIN / 10)) {
                return 0;
            }

            reverse = reverse * 10 + num;
        }
        reverse *= sign;
        return reverse;
    }
};