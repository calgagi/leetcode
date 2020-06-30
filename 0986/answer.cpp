class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> r;
        int a = 0, b = 0;
        while (a < A.size() && b < B.size()) {
            if (A[a][1] < B[b][0]) a++;
            else if (B[b][1] < A[a][0]) b++;
            else {
                r.push_back({max(A[a][0], B[b][0]), min(A[a][1], B[b][1])});
                if (A[a][1] < B[b][1]) a++;
                else b++;
            }
        }
        return r;
    }
};
