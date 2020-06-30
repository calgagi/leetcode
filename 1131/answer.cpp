class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int res = 0, c, closest;
        // Four corners manhattan distance?
        for (int x : {-1, 1}) {
            for (int y : {-1, 1}) {
                closest = arr1[0] * x + arr2[0] * y;
                for (int j = 1; j < arr1.size(); j++) {
                    c = arr1[j] * x + arr2[j] * y + j;
                    res = max(c-closest, res); 
                    closest = min(c, closest);
                }
            }
        }
        return res;
    }
};
