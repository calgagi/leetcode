class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> s;
        vector<int> r(T.size(), 0);
        for (int i = 0; i < T.size(); i++){
            while (!s.empty() && s.top().first < T[i]) {
                r[s.top().second] = (i-s.top().second);
                s.pop();
            }
            s.push(pair<int,int>(T[i],i));
        }
        return r;
    }
};
