class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int goal = (int)arr.size()/4, streak = 0;
        for (int i = 1; i < (int) arr.size(); i++) {
            if (arr[i-1] == arr[i])
                streak++;
            else {
                if (streak >= goal)
                    return arr[i-1];
                streak = 0;
            }
        }
        return arr.back();
    }
};
