class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        vector<int> right_min(n);
        vector<int> left_max(n);
        right_min[n-1] = arr[n-1];
        left_max[0] = arr[0];
        
        for (int i = n-2; i >= 0; i--) {
            right_min[i] = min(right_min[i+1], arr[i]);
        }
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i-1], arr[i]);
        }
        int res = 0;
        for (int i = 0; i < n-1; i++) {
            if (left_max[i] <= right_min[i+1]) res++;
        }
        return res+1;
    }
};
