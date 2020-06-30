class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for (int j = 1; j < n; j++) {
            int a = 0;
            for (int i = j-1; i >= 0; i--) {
                a ^= arr[i];
                int b = 0;
                for (int k = j; k < n; k++) {
                    b ^= arr[k];
                    if (b == a) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
