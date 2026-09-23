class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = total - x;
        
        if (target < 0) return -1;  // impossible case
        
        int n = nums.size();
        long long curr = 0;
        int left = 0, maxLen = -1;
        
        for (int right = 0; right < n; ++right) {
            curr += nums[right];
            
            while (curr > target && left <= right) {
                curr -= nums[left];
                left++;
            }
            
            if (curr == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return (maxLen == -1) ? -1 : n - maxLen;
   
    }
};