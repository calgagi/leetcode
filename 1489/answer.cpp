class Solution {
public:
    
    class MST {
    public:
        vector<int> link;
        vector<int> sz;
        int weight = 0;
        
        vector<int> used;
        int total_sz = 1;

        int find(int a) {
            while (a != link[a]) {
                a = link[a];
            }
            return a;
        }

        bool unite(int a, int b, int w) {
            a = find(a);
            b = find(b);

            if (a == b) {
                return 0;
            }

            if (sz[a] > sz[b]) {
                swap(a, b);
            }

            link[a] = b;
            sz[b] += sz[a];
            total_sz = max(sz[b], total_sz);
            
            weight += w;

            return 1;
        }
        
        MST(int n, vector<vector<int>>& e, int avoid, int force) {
            link.resize(n);
            sz.resize(n);
            used.assign((int) e.size(), 0);
            for (int i = 0; i < n; i++) {
                link[i] = i;
                sz[i] = 1;
            }
            
            if (force != -1) {
                unite(e[force][0], e[force][1], e[force][2]);
            }
            
            for (int i = 0; i < (int) e.size(); i++) {
                if (i != avoid && unite(e[i][0], e[i][1], e[i][2])) {
                    used[i] = 1;
                }
            }
            
            return;
        }
        
    };
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        
        for (int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }
                
        sort(edges.begin(), edges.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        vector<set<int>> ans(2);
        
        MST master_mst(n, edges, -1, -1);
        
        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v =  edges[i][1], w =  edges[i][2], j = edges[i][3];
            MST mst(n, edges, i, -1);
            if (master_mst.weight < mst.weight || mst.total_sz != n) {
                ans[0].insert(j);
            } else {
                MST mst_force(n, edges, -1, i);
                if (mst_force.weight == mst.weight) {
                    ans[1].insert(j);
                }
            }
        }
        
        return {vector<int>(ans[0].begin(), ans[0].end()), vector<int>(ans[1].begin(), ans[1].end())};
    }
};
