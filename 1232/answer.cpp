class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float l;
        if (coordinates[0][1]-coordinates[1][1] == 0) l = -1;
        else l = (abs(coordinates[0][0]-coordinates[1][0]) / abs(coordinates[0][1]-coordinates[1][1]));
        for (int i = 1; i < coordinates.size(); i++) {
            if (l != -1 && abs(coordinates[i-1][1]-coordinates[i][1]) == 0) return false;
            else if (l == -1 && abs(coordinates[i-1][1]-coordinates[i][1]) == 0) continue;
            if (l != (abs(coordinates[i-1][0]-coordinates[i][0]) / abs(coordinates[i-1][1]-coordinates[i][1]))) 
                return false;
        }
        return true;
    }
};
