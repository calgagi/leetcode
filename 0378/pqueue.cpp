struct MyCompare {
    bool operator() (const pair<int,int>& lhs, const pair<int,int> &rhs) const {
        return lhs.first > rhs.first;
    }
};


class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, MyCompare> q;
        vector<int> i(matrix.size(), 0); 
        for (int i = 0; i < matrix.size(); i++) {
            q.push({matrix[i][0], i}); 
        }
        int r = -1;
        while (k) {
            k--;
            int j = q.top().second;
            r = q.top().first;
            q.pop();
            i[j]++;
            if (i[j] < matrix.size())
                q.push({matrix[j][i[j]], j});
        }
        return r;
    }
};
