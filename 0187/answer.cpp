class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        vector<string> r;
        if (s.length() < 10) return r;
        for (int i = 0; i <= s.length()-10; i++) {
            string t = s.substr(i, 10);
            if (++m[t] == 2) r.push_back(t);
        }
        return r;
    }
};
