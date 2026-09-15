class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();
        if (s.size() < totalLen) return result;

        unordered_map<string, int> wordCount;
        for (auto &w : words) wordCount[w]++;

        // Try each offset
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> window;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (wordCount.find(word) != wordCount.end()) {
                    window[word]++;
                    count++;

                    // If word appears too many times, shrink window
                    while (window[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If valid window
                    if (count == words.size()) {
                        result.push_back(left);
                    }
                } else {
                    // Reset window
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return result;
    }
};