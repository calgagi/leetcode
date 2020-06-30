class Solution {
public:
    
    int MOD = pow(10, 9) + 7;
    
    int add(int a, int b) {
        return (a + b) % MOD;
    }
    
    int mul(int a, int b) {
        return (a * 1LL * b) % MOD;
    }
    
    int sumSubarrayMins(vector<int>& A) {
        int r = 0;
        stack<pair<int,int>> sn, sp;
        vector<int> left(A.size()), right(A.size());
        for (int i = 0; i < A.size(); i++) {
            int count = 1;
            while (!sn.empty() && sn.top().first >= A[A.size()-i-1]) {
                count += sn.top().second;
                sn.pop();
            }
            right[A.size()-i-1] = count;
            sn.push({A[A.size()-i-1], count});
            
            count = 1;
            while (!sp.empty() && sp.top().first > A[i]) {
                count += sp.top().second;
                sp.pop();
            }
            left[i] = count;
            sp.push({A[i], count});
        }
        for (int i = 0; i < A.size(); i++) {
            r = add(r, mul(mul(left[i], right[i]), A[i]));
        }
        return r;
    }
};
