class Solution {
public:
    string orderlyQueue(string S, int K) {
        string res = S;
        if (K > 1) {
            sort(res.begin(), res.end());
        } else {
            for (int i = 0; i < S.length(); i++) {
                S.push_back(S[0]);
                S.erase(S.begin());
                res = min(res, S);
            }
        }
        return res;
    }
};
