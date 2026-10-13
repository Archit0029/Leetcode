class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        
        for (int x : nums) {
            long long v = 1LL * x * x;
            sq.push_back(v);
        }

        sort(sq.begin(), sq.end(), greater<long long>());

        int n = sq.size();
        int k = (n + 1) / 2;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (i < k) ans += sq[i];
            else ans -= sq[i];
        }

        return ans;
    }
};