class Solution {
public:
    int numberOfSubstrings(string s) {
        // sliding window
        map<char,int> req;
        int counter = 0, n = s.length();
        int j = 0, res = 0;
        for (int i = 0; i < n; i++) {
            req[s[i]]++;
            if (req[s[i]] == 1) {
                counter++;
            }
            while (counter == 3) {
                req[s[j]]--;
                if (req[s[j]] == 0) {
                    counter--;
                }
                res += n-i;
                j++;
            }
        }
        return res;
    }
};
