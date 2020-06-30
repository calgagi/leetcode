class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> r(n, 0);
        stack<int> s;
        int c = 0;
        for (int i = 0; i < logs.size(); i++) {
            // get process ID
            string p[3];
            for (int j = 0, x = 0; j < logs[i].size(); j++) {
                if (logs[i][j] == ':') {
                    x++;
                    continue;
                }
                p[x] += logs[i][j];
            }
            int pid = stoi(p[0]);
            int l = stoi(p[2]);
            if (p[1] == "start") {
                if (!s.empty())
                    r[s.top()] += l - c;
                s.push(pid);
                c = l;
            } else if (p[1] == "end") {
                int t = s.top();
                s.pop();
                r[t] += l - c + 1;
                c = l + 1;
            }
        }
        return r;
    }
};
