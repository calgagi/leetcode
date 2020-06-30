class Solution {
public:
    vector<vector<int>> r;
    int n;
    int k;
    
    
    void helper(int s, vector<int>& c) {
        if (c.size() == this->k && s == this->n) {
            this->r.push_back(c);
            return;
        } else if (c.size() >= this->k || s >= this->n) {
            return;
        }
        for (int i = c.size() == 0 ? 1 : c.back()+1; i <= min(9, this->n - s); i++) {
            c.push_back(i);
            helper(s+i, c);
            c.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        this->n = n;
        this->k = k;
        vector<int> current;
        helper(0, current);
        
        return this->r;
    }
};
