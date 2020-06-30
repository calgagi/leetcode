class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<string,int>> words;
        int x = 0;
        string cur = "";
        int n = text.length();
        for (int i = 0; i < n; i++) {
            if (text[i] == ' ') {
                words.push_back({cur, x});
                cur = "";
                x++;
            } else {
                cur += text[i];
            }
        }
        words.push_back({cur, x});
        words[0].first[0] = tolower(words[0].first[0]);
        sort(words.begin(), words.end(), [&](const pair<string,int>& a, const pair<string,int>& b) {
            if (a.first.length() == b.first.length()) {
                return a.second < b.second;
            } 
            return a.first.length() < b.first.length();
        });
        string ans = "";
        for (auto& w : words) {
            ans += w.first;
            ans += " ";
        }
        ans[0] = toupper(ans[0]);
        ans.erase(ans.begin()+n);
        return ans;
    }
};
