class Solution {
public:
    int minFlipsMonoIncr(string S) {
        // O(n)
        bool zero = true;
        int z = 0, o = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '1') zero = false;
            if (!zero && S[i] == '0') z++;
        }
        zero = true;
        for (int i = S.size()-1; i >= 0; i--) {
            if (S[i] == '0') zero = false;
            if (!zero && S[i] == '1') o++;
        }
        return min(z, o);
    }
};
