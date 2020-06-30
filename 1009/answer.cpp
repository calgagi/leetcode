class Solution {
public:
    int bitwiseComplement(int N) {
        int r = pow(2, 0);
        for (int i = 1; r < N; i++) r += pow(2, i);
        return N ^ r;
    }
};
