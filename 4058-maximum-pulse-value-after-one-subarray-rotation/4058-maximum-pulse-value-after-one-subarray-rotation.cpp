class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        long long base = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                base += nums[i];
            else
                base -= nums[i];
        }

        long long prefix = 0;
        long long maxPrefix[2] = {0, LLONG_MIN};
        long long minEvenSum = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            long long x = (i % 2 == 0) ? nums[i] : -1LL * nums[i];
            prefix += x;

            int p = (i + 1) & 1;

            if (maxPrefix[p] != LLONG_MIN)
                minEvenSum = min(minEvenSum, prefix - maxPrefix[p]);

            maxPrefix[p] = max(maxPrefix[p], prefix);
        }

        if (minEvenSum == LLONG_MAX)
            return base;

        return max(base, base - 2LL * minEvenSum);
    }
};