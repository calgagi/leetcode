class Solution {
public:
    int h, w;
    using ii = pair<int,int>;
    using P = pair<ii,ii>;

    struct pos {
        ii box;
        ii person;
        bool operator<(const pos& other) const {
            return make_pair(box, person) < make_pair(other.box, other.person); 
        };
        pos(ii b, ii p) : box(b), person(p) {};
    };

    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    set<pos> visited;
    
    bool valid(const vector<vector<char>>& grid, int r, int c) {
        return r >= 0 && c >= 0 && r < h && c < w && grid[r][c] != '#';
    }
    
    int minPushBox(vector<vector<char>>& grid) {
        h = grid.size(), w = grid[0].size();
        
        ii start_box, start_me, target;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (grid[y][x] == 'B') start_box = {y, x};
                if (grid[y][x] == 'S') start_me = {y, x};
                if (grid[y][x] == 'T') target = {y, x};
            }
        }
        
        priority_queue<pair<int,pos>, vector<pair<int,pos>>, greater<pair<int,pos>>> q;
        q.push({0, {start_box, start_me}});
        while (!q.empty()) {
            pos cur = q.top().second;
            int L = q.top().first;
            q.pop();
            ii box = cur.box, per = cur.person;
            if (visited.count(cur)) continue;
            visited.insert(cur);
            if (box == target) return L;
            for (auto& [r, c] : dir) {
                ii new_pers = {per.first+r, per.second+c}, new_box = box;
                if (!valid(grid, new_pers.first, new_pers.second)) continue;
                int added_l = 0;
                if (new_pers == new_box) {
                    new_box.first += r;
                    new_box.second += c;
                    if (!valid(grid, new_box.first, new_box.second)) continue;
                    added_l++;
                }
                q.push({added_l + L, {new_box, new_pers}});
            }
        }
        return -1;
    }
};
