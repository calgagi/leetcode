class Solution {
public:
    
    int minSetSize(vector<int>& arr) {
        // Find frequencies
        int n = arr.size();
        const int MAX_N = 1e5+1;
        int freq[MAX_N] = {0};
        for (auto& i : arr)
            freq[i]++;
        vector<int> freqs;
        for (int i = 0; i < MAX_N; i++)
            if (freq[i])
                freqs.push_back(freq[i]);
        sort(freqs.begin(), freqs.end(), greater<int>());
        int s = freqs.size(), h = n/2;
        for (int i = 1; i < s; i++) {
            freqs[i] += freqs[i-1];
        }
        int l = 0, r = s-1, res = s-1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (freqs[m] < h) {
                l = m+1;
            } else {
                r = m-1;
                res = m;
            }
        }
        return res+1;
    }
};
