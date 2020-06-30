class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int m = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations.size()-i <= citations[i])
                m = max(m, (int)citations.size()-i);
        }
        return m;
    }
};
