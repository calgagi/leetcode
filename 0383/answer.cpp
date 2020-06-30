class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> c(26, 0);
        for (char& ch : magazine) {
            c[ch-'a']++;
        }
        for (char& ch : ransomNote) {
            c[ch-'a']--;
            if (c[ch-'a'] == -1) {
                return 0;
            }
        }
        return 1;
    }
};
