class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        long long shift = 0;
        for (int i = S.length()-1; i >= 0; i--) {
            S[i] -= 'a';
            shift = (shifts[i] + shift) % 26;
            S[i] = 'a' + ((shift + S[i]) % 26);
        }
        return S;
    }
};
