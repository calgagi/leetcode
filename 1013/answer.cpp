class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0, n = A.size();
        vector<int> suffix(n+2, 0);
        for (auto& i : A) {
            sum += i;
        }
        if (sum % 3 != 0) 
            return false;
        int s = sum / 3;
        for (int i = n-1; i >= 0; i--) {
            suffix[i] = A[i] + suffix[i+1];
        }
        for (int i = n-1; i >= 0; i--) {
            if (suffix[i] == s) {
                suffix[i] = suffix[i+1] + 1;
            } else {
                suffix[i] = suffix[i+1];
            }
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            c += A[i];
            if (c == s && suffix[i+2] >= 1) return true;
        }
        return false;
    }
};
