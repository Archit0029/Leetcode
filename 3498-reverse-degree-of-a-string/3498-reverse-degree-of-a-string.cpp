class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            int revIndex = 26 - (s[i] - 'a'); // reversed alphabet index
            int pos = i + 1;                  // 1-indexed position
            result += revIndex * pos;
        }
        return result;
    }
};
