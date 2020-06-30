class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int n = s1.length();
        bool g1 = 1, g2 = 1;
        for (int i = 0; i < n; i++) {
            if (s1[i] > s2[i]) {
                g1 = 0;
            } else if (s1[i] < s2[i]) {
                g2 = 0;
            } 
        }
        return g1 || g2;
    }
};
