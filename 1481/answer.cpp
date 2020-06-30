class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> freq;
        for (int& x : arr) {
            freq[x]++;
        }
        vector<pair<int,int>> freqs;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            freqs.push_back({it->second, it->first});
        }
        sort(freqs.begin(), freqs.end());
        int ans = freqs.size();
        for (int i = 0; k && i < (int) freqs.size(); i++) {
            int temp = freqs[i].first;
            freqs[i].first -= min(k, freqs[i].first);
            k -= min(temp, k);
            if (freqs[i].first == 0) {
                ans--;
            }
        }
        return ans;
    }
};
