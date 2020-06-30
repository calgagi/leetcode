class Solution {
public:    
    
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        unordered_set<int> seen;
        stack<int> s;
        s.push(start);
        while (!s.empty()) {
            int t = s.top(); s.pop();
            if (seen.find(t) != seen.end()) continue;
            seen.insert(t);
            res.push_back(t);
            for (int i = 0; i < n; i++) {
                if (seen.find(t | (1 << i)) == seen.end())
                    s.push(t | (1 << i));
                if (seen.find(t ^ (1 << i)) == seen.end())
                    s.push(t ^ (1 << i));
            }
        }
        return res;
    }
};
