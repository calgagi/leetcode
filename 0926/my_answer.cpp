class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int zeros = 0, ones = 0;
        for (int i = 0; i < S.size(); i++)
            if (S[i] == '0') 
                zeros++;
            else if (S[i] == '1') 
                ones++;
        int r = INT_MAX, displaced_zeros = zeros, displaced_ones = 0;
        for (int i = 0; i < S.size(); i++) {
            r = min(r, displaced_zeros + displaced_ones);
            if (S[i] == '0')
                displaced_zeros--;
            else if (S[i] == '1') 
                displaced_ones++;
        }
        return min(r, displaced_zeros + displaced_ones);
    }
};
