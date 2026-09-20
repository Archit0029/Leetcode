class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        auto temoravlin = intervals;

        int n = temoravlin.size();
        sort(temoravlin.begin(), temoravlin.end());

        multiset<int> activeEnds; 
        long long count = 0;

        for (auto& interval : temoravlin) {
            int start = interval[0], end = interval[1];

            while (!activeEnds.empty() && *activeEnds.begin() < start) {
                activeEnds.erase(activeEnds.begin());
            }

            count += activeEnds.size();

            activeEnds.insert(end);
        }
        return count;
    }
};