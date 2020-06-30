class Solution {
    public:
    int longestOnes(vector<int>& A, int K) {
        queue<int> q;
        int r = 0, b = 0, e = 0;
        while (e < A.size()) {    
            if (A[e] == 0) {
                q.push(e);
                e++;
                if (q.size() > K) {
                    r = max(r, e-b-1);
                    b = q.front()+1;
                    q.pop();
                } 
            } else e++;
        }
        r = max(r, e-b);
        return r;
    }
};
