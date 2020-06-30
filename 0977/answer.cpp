class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int i;
        if (A.size() <= 1) {
            for (int i = 0; i < A.size(); i++) {
                A[i] *= A[i];
            }
            return A;
        }
        for (i = 0; i < A.size(); i++) {
            if (A[i] >= 0) {
                break;
            }
        }
        int l = i-1, r = i;
        for (int j = 0; j < A.size(); j++) {
            if (l >= 0 && r < A.size()) {
                if (abs(A[l]) <= A[r]) {
                    res.push_back(A[l]*A[l]);
                    l--;
                } else {
                    res.push_back(A[r]*A[r]);
                    r++;
                }
            } else if (l >= 0) {
                res.push_back(A[l]*A[l]);
                l--;
            } else if (r < A.size()) {
                res.push_back(A[r]*A[r]);
                r++;
            }
        }
        return res;
    }
};
