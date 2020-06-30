class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int*> seen;
        int* x;
        for (char i = 'a'; i <= 'z'; i++) {
            x = new int[2];
            x[0] = x[1] = -1;
            seen[i] = x;
        }
        for (int i = 0; i < S.length(); i++) {
            if (seen[S[i]][0] != -1)
                seen[S[i]][1] = i;
            else {
                seen[S[i]][0] = seen[S[i]][1] = i;
            }
        }
        int i = 0;
        vector<int> r;
        while (i < S.length()) {
            int x = seen[S[i]][1], b = i;
            for (; i < x; i++) {
                if (seen[S[i]][1] > x) {
                    x = seen[S[i]][1];
                }
            }
            i++;
            r.push_back(x-b+1);
        }
        return r;
    }
};
