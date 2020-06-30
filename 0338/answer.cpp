class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> r;
        for (int i = 0; i <= num; i++) {
            r.push_back(__builtin_popcount(i));
        }
        return r;
    }
};
