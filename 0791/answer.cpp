class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> seen;
        for (int i = 0; i < T.size(); i++) {
            seen[T[i]]++;
        }
        int i = 0;
        for (int j = 0; j < S.size(); j++) {
            while (seen[S[j]]) {
                T[i] = S[j];
                seen[S[j]]--;
                i++;
            }
        }
        for (auto it = seen.begin(); it != seen.end(); ++it) {
            while (it->second) {
                T[i] = it->first;
                it->second--;
                i++;
            }
        }
        return T;
    }
};
