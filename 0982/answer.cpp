class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> seen;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                seen[A[i] & A[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            for (auto& it : seen) {
                if ((it.first & A[i]) == 0)
                    res += it.second;
            }
        }
        return res;
    }
};
