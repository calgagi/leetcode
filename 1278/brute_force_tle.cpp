class Solution {
public:
    string str;
    unordered_map<int, unordered_map<int,unordered_map<int,long>>> memo;
    
    long solve(int start, int end, int k) {
        if (end-start+1 == 0) return 0;
        if (k == end-start+1) return 0;
        if (k > end-start+1) return INT_MAX;
        if (memo.find(start) != memo.end() && memo[start].find(end) != memo[start].end() && memo[start][end].find(k) != memo[start][end].end())
            return memo[start][end][k];
        long res = INT_MAX;
        for (int i = start; i <= end; i++) {
            int letters = 0;
            for (int j = 0; i-j >= start && i+j <= end; j++) {
                if (str[i+j] != str[i-j]) letters++;
                for (int x = 0; x < k; x++)
                    res = min(res, letters + solve(start, i-j-1, x) + solve(i+j+1, end, k-x-1));
            }
            letters = 0;
            for (int j = 0; i-j >= start && i+j+1 <= end; j++) {
                if (str[i+j+1] != str[i-j]) letters++;
                for (int x = 0; x < k; x++)
                    res = min(res, letters + solve(start, i-j-1, x) + solve(i+j+2, end, k-x-1));
            }
        }
        memo[start][end][k] = res;
        return res;
    }
    
    
    int palindromePartition(string str, int k) {
        this->str = str;
        return solve(0, str.length()-1, k);
    }  
};
