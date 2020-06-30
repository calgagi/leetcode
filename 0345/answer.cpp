class Solution {
public:
    string reverseVowels(string s) {
        stack<char> v;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != vowels.end())
                v.push(s[i]);
        }
        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != vowels.end()) {
                s[i] = v.top();
                v.pop();
            }
        }
        return s;
    }
};
