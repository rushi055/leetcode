// class Solution {
// public:
//     bool isUgly(int n) {
//         if (n <= 0)
//             return false;
//         while (n % 2 == 0) {
//             n /= 2;
//         }
//         while (n % 3 == 0) {
//             n /= 3;
//         }
//         while (n % 5 == 0) {
//             n /= 5;
//         }
//         return n == 1;
//     }
// };

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 2 == 0) return isUgly(n / 2);
        if (n % 3 == 0) return isUgly(n / 3);
        if (n % 5 == 0) return isUgly(n / 5);
        return false; 
    }
};
