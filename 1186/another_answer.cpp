class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> before(arr.size()), after(arr.size());
        before[0] = arr[0];
        int m = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            before[i] = max(arr[i]+before[i-1], arr[i]);
            m = max(m, arr[i]);
        }
        after[arr.size()-1] = arr.back();
        for (int i = arr.size()-2; i >= 0; i--) {
            after[i] = max(arr[i]+after[i+1], arr[i]);
        }
        for (int i = 1; i < arr.size()-1; i++) {
            m = max(m, max(before[i], before[i-1]+after[i+1]));
        }
        return m;
    }
};
