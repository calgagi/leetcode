class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> r;
        int streak = 1;
        for (int i = 1; i < S.length(); i++) {
            if (S[i-1] == S[i]) streak++;
            else {
                if (streak >= 3) r.push_back({i-streak, i-1});
                streak = 1;
            }
        }
        if (streak >= 3) r.push_back({S.length()-streak, S.length()-1});
        return r;
    }
};
