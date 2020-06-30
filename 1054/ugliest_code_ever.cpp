class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if (barcodes.size() == 1) return barcodes;
        unordered_map<int, int> seen;
        int counter = 0;
        for (int i = 0; i < barcodes.size(); i++) {
            if (seen.find(barcodes[i]) == seen.end()) {seen[barcodes[i]] = 0; counter++;}
            seen[barcodes[i]]++;
        }
        vector<int> r;
        while (counter > 1) {
            for (auto it = seen.begin(); it != seen.end(); ++it ) {
                if (it->second == 0)
                    continue;
                r.push_back(it->first);
                it->second--;
                if (it->second == 0)
                    counter--;
            }
        }
        auto it = seen.begin();
        for (; it != seen.end(); ++it) if (it->second != 0) break;
        if (it == seen.end()) return r;
        for (int i = 0; i < r.size() && it->second > 0; i++) {
            if (i == 0) {
                if (r[i] != it->first) {
                    r.insert(r.begin(), it->first);
                    seen[it->first] -= 1;
                }
            } else if (i == r.size()-1) {
                if (r[i] != it->first) {
                    r.push_back(it->first);
                    seen[it->first] -= 1;
                }
            } else if (r[i] != it->first && r[i+1] != it->first) {
                r.insert(r.begin()+i+1, it->first);
                seen[it->first] -= 1;
            }
        }
        return r;
    }
};
