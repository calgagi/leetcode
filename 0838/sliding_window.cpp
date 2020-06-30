class Solution {
public:
    string pushDominoes(string dominoes) {
        int l = 0, r = 0;
        while (r < dominoes.size()) {
            if (dominoes[r] == 'L') {
                if (dominoes[l] == '.' || dominoes[l] == 'L') {
                    for ( ; l < r; l++) dominoes[l] = 'L'; 
                }
                else if (dominoes[l] == 'R') {
                    for (int i = r, j = l; j < i; i--, j++) {
                        dominoes[i] = 'L';
                        dominoes[j] = 'R';
                    }
                    l = r;
                }
            }
            else if (dominoes[r] == 'R') {
                if (dominoes[l] == 'R') {
                    for ( ; l < r; l++) dominoes[l] = 'R';
                }
                l = r;
            }
            r++;
        }
        if (dominoes[l] == 'R')
            for ( ; l < dominoes.size(); l++)
                dominoes[l] = 'R';
        return dominoes;
    }
};
