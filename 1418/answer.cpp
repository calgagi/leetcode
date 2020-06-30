class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string,int>> count;
        set<int> tables;
        set<string> foods;
        for (auto& order : orders) {
            tables.insert(stoi(order[1]));
            foods.insert(order[2]);
            count[stoi(order[1])][order[2]]++;
        }
        vector<vector<string>> ans(tables.size()+1, vector<string>(foods.size()+1, ""));
        ans[0][0] = "Table";
        int i = 1;
        for (auto& f : foods) {
            ans[0][i] = f;
            i++;
        }
        i = 1;
        for (auto& table : tables) {
            string s = to_string(table);
            ans[i][0] = s;
            int j = 1;
            for (auto& f : foods) {
                ans[i][j] = to_string(count[table][f]);
                j++;
            }
            i++;
        }
        return ans;
    }
};
