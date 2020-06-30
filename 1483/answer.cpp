class TreeAncestor {
public:
    vector<vector<int>> lift;
    
    TreeAncestor(int n, vector<int>& parent) {
        lift.assign(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            lift[0][i] = i;
            lift[1][i] = parent[i];
        }
        
        int sz = 2;
        bool go = 1;
        while (go) {
            go = 0;
            lift.push_back(vector<int>(n));
            for (int i = 0; i < n; i++) {
                lift[sz][i] = (lift[sz-1][i] == -1 ? -1 : lift[sz-1][lift[sz-1][i]]);
                if (lift[sz][i] != -1) {
                    go = 1;
                }
            }
            sz++;
        }
        
        return;
    }
    
    int getKthAncestor(int node, int k) {
        if ((1LL << ((int) lift.size() - 1)) <= k) {
            return -1;
        }
        int i = 1;
        while (node != -1 && k && i < lift.size()) {
            if ((k & 1)) {
                node = lift[i][node];
            }
            k >>= 1;
            i++;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
