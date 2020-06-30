class Solution {
public:
    int r;
    
    void helper(int j, vector<int>& x) {
        if (x.size() == 0)
            this->r++;
        for (int i = 0; i < x.size(); i++) {
            if (j % x[i] == 0 || x[i] % j == 0) {
                int t = x[i];
                x.erase(x.begin()+i);
                helper(j+1, x);
                x.insert(x.begin()+i, t);
            }   
        }
    }
    
    int countArrangement(int N) {
        this->r = 0;
        vector<int> x(N);
        for (int i = 0; i < N; i++) x[i] = i+1;
        helper(1, x);
        return this->r;
    }
};
