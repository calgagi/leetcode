/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        // 2D binary search using BFS
        int res = 0;
        queue<pair<vector<int>, vector<int>>> q;
        unordered_map<int,unordered_map<int,int>> seen;
        q.push({topRight, bottomLeft});
        while (!q.empty()) {
            vector<int> tr = q.front().first;
            vector<int> bl = q.front().second;
            q.pop();
            if (tr[0] == bl[0] && tr[1] == bl[1]) {
                if (!seen[tr[0]][tr[1]] && sea.hasShips(tr, bl))
                    res++;
                seen[tr[0]][tr[1]] = 1;
                continue;
            }
            vector<int> m = {(tr[0]+bl[0])/2, (tr[1]+bl[1])/2};
            vector<int> mr = {m[0]+1, m[1]+1};
            vector<int> t = {(tr[0]+bl[0])/2, tr[1]};
            vector<int> b = {(tr[0]+bl[0])/2, bl[1]};
            vector<int> r = {tr[0], (tr[1]+bl[1])/2};
            vector<int> l = {bl[0], (tr[1]+bl[1])/2};
            vector<int> lo = {l[0], l[1]+1};
            vector<int> bo = {b[0]+1, b[1]};
            if (tr[0] >= mr[0] && tr[1] >= mr[1] && sea.hasShips(tr, mr)) q.push({tr, mr});
            if (r[0] >= bo[0] && r[1] >= bo[1] && sea.hasShips(r, bo)) q.push({r, bo});
            if (t[0] >= lo[0] && t[1] >= lo[1] && sea.hasShips(t, lo)) q.push({t, lo});
            if (m[0] >= bl[0] && m[1] >= bl[1] && sea.hasShips(m, bl)) q.push({m, bl});
        }
        return res;
    }
};
