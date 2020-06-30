class Solution {
public:
    vector<int> size;
    vector<int> link;
    
    int find(int a) {
        while (a != link[a]) a = link[a];
        return a;
    }
    
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (size[a] > size[b]) swap(a, b);
        link[a] = b;
        size[b] += size[b];
    }    
    
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        size.resize(row.size());
        link.resize(row.size());
        for (int i = 0; i < row.size(); i++) {
            size[i] = 1;
            link[i] = i;
        }
        for (int i = 0; i < row.size(); i += 2) {
            int l = min(row[i+1], row[i]);
            int r = max(row[i+1], row[i]);
            // If already a match, continue
            if (l % 2 == 0 && r == l+1) continue;
            int matchl = l%2==0 ? l+1 : l-1;
            int matchr = r%2==0 ? r+1 : r-1;
            // Find if matches are in same set. If they are, then
            // the previous swap has already united them.
            // If they aren't, unite them with their matches with one swap.
            if (find(matchl) != find(matchr)) {
                res++;
                unite(matchl, l);
                unite(matchr, r);
            }
            unite(row[i], row[i+1]);
        }
        return res;
    }
};
