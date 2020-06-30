class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> r;
        for (int i = 0; i < queries.size(); i++) {
            int b = 0;
            bool c = true;
            int j = 0;
            while (j < queries[i].length()) {
                if (b == pattern.length()) {
                    while (j < queries[i].length() && !isupper(queries[i][j])) j++;
                    if (isupper(queries[i][j])) c = false;
                } else if (isupper(pattern[b])) {
                    while (j < queries[i].length()-1 && !isupper(queries[i][j])) j++;
                    if (queries[i][j] != pattern[b]) {
                        c = false;
                        break;
                    }
                    b++;
                } else {
                    while (j < queries[i].length()-1 && !isupper(queries[i][j]) && queries[i][j] != pattern[b]) j++;
                    if (queries[i][j] != pattern[b]) {
                        c = false;
                        break;
                    }
                    b++;
                }
                j++;
                
            }
            r.push_back(c);
        }
        return r;
    }
};
