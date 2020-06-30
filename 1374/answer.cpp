class Solution {
public:
    string generateTheString(int n) {
        string res = "";
        for (int i = 0; i < n-(!(n%2)); i++) {
            res.push_back('a');
        }
        if (n%2 == 0) {
            res.push_back('b');
        }
        return res;
    }
};
