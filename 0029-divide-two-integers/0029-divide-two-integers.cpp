class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Use long long for absolute values
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long res = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            res += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0)) res = -res;

        // Clamp result to 32-bit range
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;

        return (int)res;
    }
};