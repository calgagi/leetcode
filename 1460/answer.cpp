class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> x;
        for (int i : arr) {
            x[i]++;
        }
        for (int i : target) {
            x[i]--;
        }
        for (pair<int,int> i : x) {
            if (i.second != 0) {
                return 0;
            }
        }
        return 1;
    }
};
