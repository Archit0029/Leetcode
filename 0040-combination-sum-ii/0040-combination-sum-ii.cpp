class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort to handle duplicates
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;
        
        for (int i = start; i < candidates.size(); i++) {
            // skip duplicates at the same recursion depth
            if (i > start && candidates[i] == candidates[i-1]) continue;
            
            current.push_back(candidates[i]);
            // move to next index (i+1) since each number can be used once
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back(); // undo choice
        }
    }
};
