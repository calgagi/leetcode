class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1.length() != s2.length()) return -1;
        int swapX = 0, swapY = 0;
        int o = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i] && s1[i] == 'x') swapX++;
            if (s1[i] != s2[i] && s1[i] == 'y') swapY++;
            if (s1[i] == 'x') o++;
            if (s2[i] == 'x') o++;
        }
        if (o % 2 == 1) return -1;
        int swap = (swapX / 2) + (swapY / 2);
        if (swapX % 2 == 1 && swapY % 2 == 1) swap += 2;
        return swap;
    }
};
