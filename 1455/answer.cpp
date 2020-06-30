class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length();
        string cur = "";
        int word = 1;
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                cur = "";
                word++;
            } else {
                cur += sentence[i];
            }
            if (searchWord == cur) {
                return word;
            }
        }
        return -1;
    }
};
