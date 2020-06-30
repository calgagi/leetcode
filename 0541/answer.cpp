class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i < s.length()) {
            int j = i+k < s.length() ? i+k-1 : s.length()-1;
            int x = j+1+k;
            for (; i < j; i++, j--)
                swap(s[i], s[j]);
            i = x;
        }
        return s;
    }
};
