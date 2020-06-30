class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> diff(A.size());
        if (A.size() < 3) return 0;
        diff[0] = A[0];
        for (int i = 1; i < A.size(); i++) diff[i] = A[i] - A[i-1];
        int l = 1, r = 1;
        int t = 0;
        while (r < diff.size()) {
            while (r < diff.size() && diff[l] == diff[r]) r++;
            t += max(0, (r-(l-1)-2)*(1+(r-(l-1))-2)/2);
            l = r;
        }
        return t;
    }
};
