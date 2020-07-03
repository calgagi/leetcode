class Solution {
public:
    bool isPathCrossing(string path) {
        map<int, map<int,int>> seen;
        pair<int,int> where = {0, 0};
        for (char& x : path) {
            seen[where.first][where.second] = 1;
            if (x == 'N') {
                where.first++;
            } else if (x == 'S') {
                where.first--;
            } else if (x == 'E') {
                where.second++;
            } else {
                where.second--;
            }
            if (seen[where.first][where.second] == 1) {
                return 1;
            }
        }
        return seen[where.first][where.second] == 1;
    }
};
