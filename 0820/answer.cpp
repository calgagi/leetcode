class Solution {
public:
    static bool compare(string& s1, string &s2) {
        return s1.length() > s2.length();
    }
    
    
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s;
        int r = 0;
        sort(words.begin(), words.end(), compare);
        for (int i = 0; i < words.size(); i++) {
            reverse(words[i].begin(), words[i].end());
            if (s.find(words[i]) != s.end()) continue;
            for (int j = 1; j <= words[i].length(); j++) {
                s.insert(words[i].substr(0, j));
            }
            r += words[i].size() + 1;
        }
        return r;
    }
};
