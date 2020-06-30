class Solution {
public:
    vector<int> fib;
    
    void calc(int k) {
        fib.push_back(1);
        fib.push_back(1);
        while (fib.back() < k) {
            fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
        }
        return;
    }
    
    int findMinFibonacciNumbers(int k) {
        calc(k);
        int ans = 0;
        for (int i = fib.size()-1; i >= 0; i--) {
            while (fib[i] <= k) {
                k -= fib[i];
                ans++;
            }
        }
        return ans;
    }
};
