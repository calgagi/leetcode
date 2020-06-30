class Solution {
public:
    bool evaluate(string& b) {
        return b[0] == '1' &&
               b[1] == '2' &&
               b[2] == '3' &&
               b[3] == '4' &&
               b[4] == '5' &&
               b[5] == '0';
    }
    
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (auto& v : board) for (auto& x : v) start += (x + '0');
        queue<pair<string,int>> q;
        q.push({start, 0});
        unordered_set<string> seen;
        while (!q.empty()) {
            string state = q.front().first;
            int moves = q.front().second;
            q.pop();
            if (seen.count(state)) continue;
            seen.insert(state);
            if (evaluate(state)) return moves;
            
            // Move
            int pos;
            for (int i = 0; i < state.length(); i++) if (state[i] == '0') { pos = i; break; }
            if (pos < 3) {
                swap(state[pos], state[pos+3]);
                if (!seen.count(state)) q.push({state, moves+1});
                swap(state[pos], state[pos+3]);
            } else {
                swap(state[pos], state[pos-3]);
                if (!seen.count(state)) q.push({state, moves+1});
                swap(state[pos], state[pos-3]);
            }
            if (pos % 3 != 0) {
                swap(state[pos], state[pos-1]);
                if (!seen.count(state)) q.push({state, moves+1});
                swap(state[pos], state[pos-1]);
            }
            if (pos % 3 != 2) {
                swap(state[pos], state[pos+1]);
                if (!seen.count(state)) q.push({state, moves+1});
                swap(state[pos], state[pos+1]);
            }
        }
        return -1;
    }
};
