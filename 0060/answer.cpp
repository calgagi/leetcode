class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> c(n);
        int w = 1;
        for (int i = 0; i < n; i++) {
            c[i] = to_string(i+1);
            w *= i+1;
        }
        w /= c.size();
        string res = "";
        k--;
        while (true) {
            res += c[k / w];
            c.erase(c.begin() + k / w);
            k %= w;
            if (!c.size()) break;
            w /= c.size();
            
        }
        return res;
    }
};
