class Solution {
public:
    string sortString(string s) {
        vector<int> freq(26, 0);
        int n = s.length();
        for (auto& c : s) {
            freq[c-'a']++;
        }
        string res = "";
        while (n) {
            for (int i = 0; i < 26; i++) {
                if (freq[i]) {
                    res += 'a'+i;
                    n--;
                    freq[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (freq[i]) {
                    res += 'a'+i;
                    n--;
                    freq[i]--;
                }
            }            
        }
        return res;
    }
};
