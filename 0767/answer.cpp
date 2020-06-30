class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char,int> f;
        for (char& c : S) {
            f[c]++;
            if (f[c] > (S.length()+1)/2) return "";
        }
        for (auto it = f.begin(); it != f.end(); it++) pq.push({it->second, it->first});
        string r = S;
        int j = 0;
        while (!pq.empty()) {
            for (int i = 0; i < pq.top().first; i++, j += 2) {
                if (j >= S.length()) j = 1;
                r[j] = pq.top().second;
            }
            pq.pop();
        }
        return r;
    }
};
