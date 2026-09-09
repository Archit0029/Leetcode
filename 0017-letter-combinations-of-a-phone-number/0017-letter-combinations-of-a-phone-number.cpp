class Solution {
public:
   vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> pad = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res{""};
        for (char d : digits) {
            vector<string> tmp;
            for (auto &prefix : res)
                for (char c : pad[d - '0'])
                    tmp.push_back(prefix + c);
            res.swap(tmp);
        }
        return res;
    }
};