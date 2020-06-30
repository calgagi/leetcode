class Solution {
public:
    
    int MOD = 1e9 + 7;

    int mult(long long a, long long b) {
        return (a * 1LL * b) % MOD;
    }
    
    int numPrimeArrangements(int n) {
        vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;
        int nums = 0;
        for (int i = 2; i < n+1; i++)
            if (primes[i]) {
                for (int j = i+i; j < n+1; j += i) 
                    primes[j] = false;
                nums++;
            }
        // total = non-primes! * primes!
        vector<int> fact(n+1);
        fact[0] = 1;
        for (int i = 1; i < n+1; i++)
            fact[i] = mult(fact[i-1], i);
        return mult(fact[nums], fact[n-nums]);
    }
};
