class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int r = 0;
        for (int i =- 0; i < arr1.size(); i++) {
            for (int j = 0; j < arr2.size(); j++) {
                r = max(r, abs(arr1[i]-arr1[j])+abs(arr2[i]-arr2[j])+abs(i-j));
            }
        }
        return r;
    }
};
