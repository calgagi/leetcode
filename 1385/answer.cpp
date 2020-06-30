class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        int n = arr1.size(), m = arr2.size();
        for (int i = 0; i < n; i++) {
            bool good = 0;
            for (int j = 0; j < m; j++) {
                if (abs(arr1[i]-arr2[j]) <= d) {
                    good = 1;
                    break;
                }
            }
            if (!good) {
                res++;
            }
        }
        return res;
    }
};
