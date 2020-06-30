class Solution {
public:
    vector<vector<int>> hashes;
    unordered_set<string> seen;
    
    
    void rolling_hash(const string& t, int i) {
        const int p = 31, s = t.length(), start = i;
        long long p_pow = 1;
        long long MOD = 1e9 + 7;
        long long hash_val = 0;
        string cur = "";
        while (i < s) {
            cur += t[i];
            hash_val = (hash_val + (p_pow * (t[i] - 'a' + 1))) % MOD;
            hashes[start][i-start] = hash_val;
            p_pow = (p_pow * p) % MOD;
            if (start-(i-start+1) >= 0 && hashes[start-(i-start+1)][i-start] == hash_val) {
                seen.insert(cur);
            }
            i++;
        }
    }
    
    
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        hashes.resize(n);
        for (auto& v : hashes) v.resize(n);
        
        for (int i = 0; i < n; i++) {
            rolling_hash(text, i);
        }
        
        return seen.size();
    }
};
