class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        bool found = false;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string curr = q.front(); q.pop();

            if (isValid(curr)) {
                result.push_back(curr);
                found = true;
            }

            if (found) continue; // stop deeper exploration

            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;
                string next = curr.substr(0, i) + curr.substr(i + 1);
                if (!visited.count(next)) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        return result;
    }

    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }
};
