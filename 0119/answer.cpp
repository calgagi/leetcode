class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        vector<int> prev;
        for (int i = 1; i <= rowIndex+1; i++) {
            prev = res;
            res.clear();
            for (int j = 0; j < i-1; j++) {
                if (j-1 < 0) res.push_back(1);
                else res.push_back(prev[j] + prev[j-1]);
            }
            res.push_back(1);
        }
        return res;
    }
};
