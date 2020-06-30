class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = (int) arr.size(), mx = arr[n-1];
        arr[n-1] = -1;
        for (int i = n-2; i >= 0; i--) {
            int new_mx = max(mx, arr[i]);
            arr[i] = mx;
            mx = new_mx;
        }
        return arr;
    }
};
