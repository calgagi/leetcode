class Solution {
public:
    vector<int> link;
    vector<int> sz;
    int num_bouquets = 0;
    int flowers_per_bouquet;
    
    int find(int a) {
        while (a != link[a]) {
            a = link[a];
        }
        return a;
    }
    
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a == b) {
            return;
        }
        
        if (sz[b] < sz[a]) {
            swap(a, b);
        }
        
        num_bouquets -= (sz[a] / flowers_per_bouquet) + (sz[b] / flowers_per_bouquet);
        
        link[a] = b;
        sz[b] += sz[a];
        
        num_bouquets += sz[b] / flowers_per_bouquet;
        
        return;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        flowers_per_bouquet = k;
        vector<pair<int,int>> flowers(n);
        link.resize(n), sz.resize(n);
        
        if (n / flowers_per_bouquet < m) {
            return -1;
        }
        
        for (int i = 0; i < n; i++) {
            flowers[i] = {bloomDay[i], i};
            sz[i] = 1;
            link[i] = i;
        }
        
        sort(flowers.begin(), flowers.end());
        
        if (k == 1) {
            return flowers[m-1].first;
        }
        
        int ans = 0;
        for (int i = 0; i < n && num_bouquets < m; i++) {
            ans = flowers[i].first;
            int index = flowers[i].second;
            unite(index, index);
            if (index > 0 && bloomDay[index-1] <= ans) {
                unite(index, index-1);
            }
            if (index < n-1 && bloomDay[index+1] <= ans) {
                unite(index, index+1);
            }
        }
        return ans;
    }
};
