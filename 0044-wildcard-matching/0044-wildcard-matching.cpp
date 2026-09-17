class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;              // pointer for s
        int j = 0;              // pointer for p

        int star = -1;          // last position of '*'
        int match = 0;          // position in s matched by '*'

        while (i < s.size()) {

            // Case 1: Characters match or '?' matches any character
            if (j < p.size() &&
                (p[j] == s[i] || p[j] == '?')) {
                
                i++;
                j++;
            }

            // Case 2: '*' found
            else if (j < p.size() && p[j] == '*') {
                
                star = j;
                match = i;
                j++;
            }

            // Case 3: Mismatch
            else if (star != -1) {
                
                // Let '*' match one more character
                j = star + 1;
                match++;
                i = match;
            }

            // No '*' available to handle mismatch
            else {
                return false;
            }
        }

        // Remaining pattern characters must all be '*'
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};