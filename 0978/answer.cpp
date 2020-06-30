class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        int streak = 0, best = 0;
        for (int i = 0; i < n-1; i++) {
            if ((i&1) && A[i] > A[i+1]) {
                streak++;
            } else if ((i&1) == 0 && A[i] < A[i+1]) {
                streak++;
            } else {
                streak = 0;
            }
            best = max(streak+1, best);
        }
        streak = 0;
        for (int i = 0; i < n-1; i++) {
            if ((i&1) && A[i] < A[i+1]) {
                streak++;
            } else if ((i&1) == 0 && A[i] > A[i+1]) {
                streak++;
            } else {
                streak = 0;
            }
            best = max(streak+1, best);
        }
        return max(best,1);
    }
    
};
