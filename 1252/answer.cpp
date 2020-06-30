class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(auto& index : indices){
            for(int i = 0; i < m; i++)
                v[index[0]][i]++;
            for(int j = 0; j < n; j++)
                v[j][index[1]]++;
        }
        int res = 0;
        for(auto& x : v)
            for(auto& i : x)
                if(i % 2) res++;
        return res;
    }
};
