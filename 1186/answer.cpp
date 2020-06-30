class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> maxEnd(arr.size(), 0), maxBegin(arr.size(), 0);
        int maximum = arr[0];
        maxBegin[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            maximum = max(maximum, arr[i]);
            maxBegin[i] = max(maxBegin[i-1]+arr[i], arr[i]);
        }
        maxEnd[arr.size()-1] = arr.back();
        for (int i = arr.size()-2; i >= 0; i--) {
            maxEnd[i] = max(maxEnd[i+1]+arr[i], arr[i]);
        }
        for (int i = 1; i < arr.size()-1; i++)
            maximum = max(maximum, max(maxBegin[i-1] + maxEnd[i+1], max(maxBegin[i], maxEnd[i])));
        return maximum;
    }
};
