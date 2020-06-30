class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> s;
        int counter = rooms.size();
        s.push(0);
        set<int> visited;
        while (!s.empty()) {
            int c = s.top(); s.pop();
            if (visited.find(c) != visited.end()) continue;
            visited.insert(c);
            counter--;
            for (int i = 0; i < rooms[c].size(); i++) {
                if (visited.find(rooms[c][i]) == visited.end()) {
                    s.push(rooms[c][i]);
                }
            }
        }
        return counter == 0;
    }
};
