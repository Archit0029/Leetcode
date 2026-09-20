class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> groups;
        groups.push_back(nums);

        vector<int> ans;

        for (int b = 14; b >= 0; --b) {
            int power = 0;
            vector<vector<int>> nextGroups;
            bool finished = false;

            for (auto &group : groups) {
                if (finished) {
                    nextGroups.push_back(group);
                    continue;
                }

                vector<int> ones, zeros;

                for (int x : group) {
                    if ((x >> b) & 1)
                        ones.push_back(x);
                    else
                        zeros.push_back(x);
                }

                if (zeros.empty()) {
                    power += group.size();
                    nextGroups.push_back(group);
                } else {
                    power += ones.size();

                    if (!ones.empty())
                        nextGroups.push_back(ones);

                    if (!zeros.empty())
                        nextGroups.push_back(zeros);

                    finished = true;
                }
            }

            ans.push_back(power);
            groups = nextGroups;
        }

        return ans;
    }
};