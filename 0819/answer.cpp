class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> ban;
        for (string& s : banned) {
            for (char& c : s) 
                if (c >= 'A' && c <= 'Z')
                    c += 32;
            ban.insert(s);
        }
        string current = "";
        unordered_map<string,int> seen;
        string r = "";
        seen[r] = 0;
        for (char& c : paragraph) {
            if (c >= 'A' && c <= 'Z')
                c += 32;
            if (c >= 'a' && c <= 'z') {
                current += c;
            } else if (current != "") {
                if (ban.find(current) == ban.end()) {
                    seen[current]++;
                    if (seen[r] < seen[current]) {
                        r = current;
                    }
                }
                current = "";
            } else {
                current = "";
            }
        }
        if (current != "" && ++seen[current] > seen[r]) {
            r = current;
        }
        return r;
    }
};
