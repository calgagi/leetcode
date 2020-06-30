class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        unordered_map<int,unordered_map<int,bool>> seen;
        queue<pair<int,int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int tx = q.front().first;
            int ty = q.front().second;
            q.pop();
            if (tx == z || ty == z || tx + ty == z) return true;
            if (seen.count(tx) && seen[tx].count(ty)) continue;
            seen[tx][ty] = true;
            if (tx != 0)
                q.push({0, ty});
            if (ty != 0)
                q.push({tx, 0});
            if (tx != x)
                q.push({x, ty});
            if (ty != y)
                q.push({tx, y});
            q.push({min(ty, x-tx), ty-min(ty, x-tx)});
            q.push({tx-min(tx, y-ty), min(tx, y-ty)});
        }
        return false;
    }
};
