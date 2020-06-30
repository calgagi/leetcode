class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int>(1, 0);
        vector<int> r;
        r.push_back(0);
        r.push_back(1);
        int i = 1;
        while (i < n) {
            int s = r.size()-1;
            for (int j = s; j >= 0; j--) {
                r.push_back(r[j]);
            }
            for (int j = r.size()-1; j > s; j--) {
                r[j] |= (1 << i);
            }
            i++;
        }
        return r;
    }
};
