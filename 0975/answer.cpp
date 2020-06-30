class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        const int n = A.size();
        // Problem: Organizing the data
        // After data is organized into a graph, easy to do with DFS and hashmap
        // Need to:
        //  ODD: Find minimum for AFTER each node that's greater than the node
        //  EVEN: Find maximum for AFTER each node that's smaller than the node
        // Solution ideas:
        //  * Mono stack - BAD because have to update nodes that already have candidate
        //  * Get min/max, iterating backwards - BAD because has to be close to node
        //  * Insertion sort with Binary Search - GOOD and easy to implement with map<int,int>
        vector<pair<int,int>> jump(n); // where first == odd jump, second == even jump
        map<int,int> seen;
        seen[A[n-1]] = n-1;
        jump[n-1] = {n-1, n-1};
        for (int i = n-2; i >= 0; i--) {
            auto it = seen.upper_bound(A[i]-1);
            jump[i].first = it == seen.end() ? -1 : it->second;
            if (seen.size() >= 1 && it != seen.begin() && it->first != A[i]) it--;
            jump[i].second = it == seen.end() || it->first > A[i] ? -1 : it->second;
            seen[A[i]] = i;
        }
        /*for (auto& item : jump) {
            cout << "(" << item.first << ", " << item.second << ")" << " ";
        }
        cout << endl; */
        vector<vector<int>> visited(n, vector<int>(2, 0));
        visited[n-1] = {1, 1};
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i][0] == 0) {
                int it = i;
                bool oddOReven = false;
                stack<pair<int,bool>> s;
                //cout << "START: " << endl;
                while (it != -1 && visited[it][(int)oddOReven] == 0) {
                    s.push({it, oddOReven});
                    //cout << it << " " << oddOReven << endl;
                    it = oddOReven ? jump[it].second : jump[it].first;
                    oddOReven = !oddOReven;
                }
                if (it != -1) it = visited[it][(int)oddOReven];
                while (!s.empty()) {
                    visited[s.top().first][(int)s.top().second] = it != -1 ? 1 : -1;
                    s.pop();
                }
                if (it != -1 && visited[i][0] != -1) {
                    res++;
                }
            } else if (visited[i][0] == 1) res++;
        }
        
        return res;
    }
};
