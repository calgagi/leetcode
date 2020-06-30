class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int res = 0, n = satisfaction.size();
        vector<int> pos, neg;
        for (int i = 0; i < n; i++) {
            if (satisfaction[i] >= 0) {
                pos.push_back(satisfaction[i]);
            } else {
                neg.push_back(satisfaction[i]);
            }
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end(), greater<int>());
        for (int i = 0; i < (int) pos.size(); i++) {
            res += pos[i]*(i+1);
        }
        int j = 0;
        while (j < (int) neg.size()) {
            int test_res = neg[j];
            for (int i = 0; i < (int) pos.size(); i++) {
                test_res += pos[i]*(i+2);
            }
            if (test_res >= res) {
                res = test_res;
                pos.insert(pos.begin(), neg[j]);
                j++;
            } else {
                break;
            }
        }
        return res;
    }
};
