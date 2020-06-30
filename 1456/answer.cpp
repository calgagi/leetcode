class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, n = s.length();
        vector<int> cnt(26, 0);
        for (int i = 0; i < k; i++) {
            cnt[s[i]-'a']++;
        }
        ans = max(ans, cnt['a'-'a']+cnt['e'-'a']+cnt['i'-'a']+cnt['o'-'a']+cnt['u'-'a']);
        for (int i = 1; i+k-1 < n; i++) {
            cnt[s[i-1]-'a']--;
            cnt[s[i+k-1]-'a']++;
            ans = max(ans, cnt['a'-'a']+cnt['e'-'a']+cnt['i'-'a']+cnt['o'-'a']+cnt['u'-'a']);
        }
        return ans;
    }
};
