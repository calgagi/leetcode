class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // BFS?
        queue<int> q;
        vector<int> res;
        for (int i = 1; i < 10; i++)
            q.push(i);
        while (!q.empty()) {
            long s = q.front(); q.pop();
            if (s > high) continue;
            if (s >= low && s <= high)
                res.push_back(s);
            int last = s % 10;
            if (last == 9) continue;
            s *= 10;
            s += last+1;
            if (s <= (long)high)
                q.push(s);
        }
        return res;
    }
};
