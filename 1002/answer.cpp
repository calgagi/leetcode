class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int** x = new int*[A.size()];
        for (int i = 0; i < A.size(); i++) {
            x[i] = new int[26];
            for (int j = 0; j < 26; j++) x[i][j] = 0;
            for (int j = 0; j < A[i].length(); j++) x[i][A[i][j]-'a']++;
        }
        vector<string> r;
        for (int i = 0; i < 26; i++) {
            string c(1, (char) i+'a');
            int m = numeric_limits<int>::max();
            for (int j = 0; j < A.size(); j++) m = min(m, x[j][i]);
            for (int j = 0; j < m; j++) {
                r.push_back(c);
            }
        }
        return r;
    }
};
