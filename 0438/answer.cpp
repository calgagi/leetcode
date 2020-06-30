class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cp(26, 0);
        int counter = 0;
        for (auto& c : p) {
            cp[c-'a']++;
            if (cp[c-'a'] == 1) {
                counter++;
            }
        }
        int n = p.length();
        vector<int> ans;
        for (int b = 0, e = 0; e < s.length(); e++) {
            cp[s[e]-'a']--;
            if (cp[s[e]-'a'] == 0) {
                counter--;
            }
            while (counter == 0) {
                if (e-b+1 == p.length()) {
                    ans.push_back(b);
                }
                cp[s[b]-'a']++;
                if (cp[s[b]-'a'] == 1) {
                    counter++;
                }
                b++;
            }
        }
        return ans;
    }
};
