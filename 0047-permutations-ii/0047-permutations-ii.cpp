class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, visited, current, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<bool>& visited,
                   vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            visited[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, visited, current, result);
            current.pop_back();
            visited[i] = false;
        }
    }
};
