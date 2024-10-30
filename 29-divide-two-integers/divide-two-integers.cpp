class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case for overflow when dividend is INT_MIN and divisor is
        // -1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool sign = (dividend > 0) == (divisor > 0);

        // Use absolute values to simplify the logic
        long long n = std::abs(static_cast<long long>(dividend));
        long long d = std::abs(static_cast<long long>(divisor));

        long long quotient = 0;

        // Division using bitwise shifts and subtraction
        while (n >= d) {
            long long tempDivisor = d, count = 1;

            // Keep doubling the divisor until it exceeds n
            while (n >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                count <<= 1;
            }

            n -= tempDivisor;
            quotient += count;
        }

        // Apply sign to the quotient
        quotient = sign ? quotient : -quotient;

        // Clamp the result within the 32-bit signed integer range
        if (quotient > INT_MAX)
            return INT_MAX;
        if (quotient < INT_MIN)
            return INT_MIN;

        return static_cast<int>(quotient);
    }
};