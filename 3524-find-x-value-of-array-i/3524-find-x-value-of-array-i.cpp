class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> freq(k, 0);

        for (int num : nums) {
            vector<long long> newFreq(k, 0);
            int rem = num % k;
            newFreq[rem]++;

            for (int r = 0; r < k; r++) {
                if (freq[r] > 0) {
                    int newRem = (r * rem) % k;
                    newFreq[newRem] += freq[r];
                }
            }

            for (int r = 0; r < k; r++) {
                freq[r] = newFreq[r];
                result[r] += freq[r];
            }
        }

        return result;
    }
};
