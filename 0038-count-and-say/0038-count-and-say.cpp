class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 2; i <= n; i++) {
            result = buildNext(result);
        }
        return result;
    }
    
private:
    string buildNext(const string& s) {
        string next;
        int count = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (i < s.size() && s[i] == s[i-1]) {
                count++;
            } else {
                next += to_string(count) + s[i-1];
                count = 1;
            }
        }
        return next;
    }
};
