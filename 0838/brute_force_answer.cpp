class Solution {
public:
    string pushDominoes(string dominoes) {
        string result = dominoes;
        do {
            dominoes = result;
            for (int i = 0; i < dominoes.size(); i++) {
                bool r = false, l = false;
                if (dominoes[i] == '.') {
                    if (i > 0 && dominoes[i-1] == 'R') 
                        r = true;
                    if (i < dominoes.size()-1 && dominoes[i+1] == 'L')
                        l = true;
                }
                if (l && r) 
                    result[i] = '.';
                else if (l)
                    result[i] = 'L';
                else if (r)
                    result[i] = 'R';
            }
        } while (result != dominoes);
        return result;
    }
};
