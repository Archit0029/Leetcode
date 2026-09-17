class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int index) {
        
        // All positions are filled
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Try every remaining element
        for (int i = index; i < nums.size(); i++) {
            
            // Put nums[i] at current position
            swap(nums[index], nums[i]);

            // Solve remaining positions
            backtrack(nums, index + 1);

            // Undo the choice
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};