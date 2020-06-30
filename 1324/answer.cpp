class Solution {
public:
    vector<string> printVertically(string s) {
        int n = s.length(), counter = 0, word_count = 0;
        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                counter = 0;
                word_count++;
            } else {
                counter++;
                if ((int) res.size() < counter) {
                    res.push_back("");
                }
                while ((int) res[counter-1].length() < word_count) {
                    res[counter-1] += ' ';
                }
                res[counter-1] += s[i];
            }
        }
        return res;

    }
};
