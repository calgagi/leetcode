class Solution {
public:
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        for (vector<int>& p : pairs) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        
        vector<vector<int>> components;
        unordered_map<int, bool> in;
        for (int i = 0; i < s.length(); i++) {
            if (in.find(i) == in.end()) {
                stack<int> s;
                s.push(i);
                vector<int> component;
                while (!s.empty()) {
                    int t = s.top();
                    s.pop();
                    if (in.find(t) != in.end()) continue;
                    component.push_back(t);
                    in[t] = true;
                    for (int &e : graph[t])
                        s.push(e);
                }
                sort(component.begin(), component.end());
                components.push_back(component);
            }
        }
        
        vector<vector<char>> chars;
        for (vector<int>& c : components) {
            vector<char> chareq;
            for (int &i : c) {
                chareq.push_back(s[i]);
            }
            sort(chareq.begin(), chareq.end());
            chars.push_back(chareq);
        }
        
        vector<pair<int,char>> ss;
        for (int i = 0; i < components.size(); i++) {
            for (int j = 0; j < components[i].size(); j++) {
                ss.push_back({components[i][j], chars[i][j]});
            }
        }
        sort(ss.begin(), ss.end());
        string r = "";
        for (int i = 0; i < ss.size(); i++) r += ss[i].second;
        return r;
    }
};
