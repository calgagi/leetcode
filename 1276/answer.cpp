class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int l = 0, r = cheeseSlices;
        while (l <= r) {
            int m = (l + r) / 2;
            int val = 2*(m) + 4*(cheeseSlices-m);
            if (val == tomatoSlices) {
                vector<int> res = {cheeseSlices-m, m};
                return res;
            }
            if (val < tomatoSlices) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return vector<int>();
    }
};
