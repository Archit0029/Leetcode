class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        
        // Step 1: Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Step 2: Count length of last word
        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};
