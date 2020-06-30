class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
        for (int i = 0; i < S.length(); i++) {
            if (!s.empty() && S[i] == '#') s.pop();
            else if (s.empty() && S[i] == '#') continue;
            else s.push(S[i]);
        }
        for (int i = 0; i < T.length(); i++) {
            if (!t.empty() && T[i] == '#') t.pop();
            else if (t.empty() && T[i] == '#') continue;
            else t.push(T[i]);
        }
        while (!s.empty() && !t.empty()) {
            if (s.top() != t.top()) return false;
            s.pop();
            t.pop();
        }
        if (!s.empty() || !t.empty()) return false;
        return true;
    }
};
