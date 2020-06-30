class Solution {
public:
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        const int n = digits.length();
        queue<pair<string,int>> q;
        q.push({"", 0});
        vector<string> ret;
        if (n == 0) return ret;
        while (!q.empty()) {
            int i = q.front().second;
            string cur = q.front().first;
            q.pop();
            if (i >= n) {
                ret.push_back(cur);
                continue;
            }
            for (auto& c : mapping[digits[i] - '0']) {
                q.push({cur + c, i+1});
            }
        }
        return ret;
    }
};
