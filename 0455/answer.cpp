class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int x = 0;
        for(int j = 0, i = 0; j < g.size() && i < s.size(); i++){
            if(g[j] <= s[i]){
                x++;
                j++;
            }
        }
        return x;
    }
};
