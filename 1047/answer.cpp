class Solution {
public:
    string removeDuplicates(string S) {
        for (int i = 0; i < S.length()-1 && S.length() > 0; i++) {
            if (S[i] == S[i+1]) {
                S.erase(S.begin()+i);
                S.erase(S.begin()+i);
                i -= 2;
                if (i < 0) i = -1;
            }
        }
        return S;
    }
};
