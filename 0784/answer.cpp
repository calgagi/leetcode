class Solution {
public:
    vector<string> r;
    vector<string> letterCasePermutation(string S) {
        backtrack(S, 0);
        return r;
        
    }
    
    void backtrack(string S, int i) {
        if (i == S.length()) { r.push_back(S); return; }
        if (isalpha(S[i])) {
            S[i] = toupper(S[i]);
            backtrack(S, i+1);
            S[i] = tolower(S[i]);
            backtrack(S, i+1);
        } else {
            backtrack(S, i+1);
        }
    }
    
};
