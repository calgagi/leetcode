class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> seen = {""};
        sort(words.begin(), words.end());
        string r = "";
        for (int i = 0; i < words.size(); i++) {
            if (seen.find(words[i].substr(0, words[i].size()-1)) != seen.end()) {
                seen.insert(words[i]);
                if (r.size() < words[i].size()) r = words[i];
            }
        }
        return r;
    }
};
