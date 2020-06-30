class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> seen;
        int r = 0;
        int odd = 0;
        for (int i = 0; i < s.size(); i++) {
            if (seen.find(s[i]) == seen.end()) seen[s[i]] = 0;
            seen[s[i]] += 1;
            if (seen[s[i]] % 2 == 1) odd += 1;
            else { odd -= 1; r += 2; }         
        }
        return odd ? r+1 : r;
    }
};
