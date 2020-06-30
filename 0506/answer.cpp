class Solution {
public:
    
    struct CompareDist
    {
        bool operator()(pair<int,int> n1, pair<int,int> n2) {
            return n1.first < n2.first;
        }
    };
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, CompareDist> pq;
        for (int i = 0; i < nums.size(); i++) pq.push({nums[i], i});
        vector<string> r(nums.size(), "");
        for (int i = 0; i < nums.size(); i++) {
            pair<int,int> t = pq.top();
            pq.pop();
            if (i == 0) r[t.second] = "Gold Medal";
            else if (i == 1) r[t.second] = "Silver Medal";
            else if (i == 2) r[t.second] = "Bronze Medal";
            else r[t.second] = to_string(i+1);
        }
        return r;
    }
};
