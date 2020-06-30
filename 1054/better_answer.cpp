class Solution {
public:
    struct Compare {
        bool operator()(pair<int,int>& p1, pair<int,int>& p2) {
            return p1.second < p2.second;
        }
    };
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> s;
        for (int i = 0; i < barcodes.size(); i++) {
            s[barcodes[i]]++;
            barcodes[i] = -1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> x;
        for (auto i = s.begin(); i != s.end(); ++i) x.push({i->first, i->second});
        int i = 0;
        int counter = x.size();
        while (!x.empty()) {
            pair<int,int> t = x.top(); x.pop();
            for (int j = 0; j < t.second; j++) {
                barcodes[i] = t.first;
                i += 2;
                if (i >= barcodes.size()) i = 1;
            }
        }
        return barcodes;
    }
};
