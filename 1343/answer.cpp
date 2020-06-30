class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int cur = 0, n = arr.size();
        for (int i = 0; i < k && i < n; i++) {
            cur += arr[i];
        }
        if (cur/k >= threshold) {
            res++;
        }
        for (int i = k; i < n; i++) {
            cur -= arr[i-k];
            cur += arr[i];
            if (cur/k >= threshold) {
                //cout << i << " ";
                res++;
            }
        }
        return res;
    }
};
