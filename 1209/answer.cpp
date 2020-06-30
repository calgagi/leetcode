class Solution {
public:
    string removeDuplicates(string s, int k) {
        bool deleted = true;
        while (deleted) {
            int streak = 1;
            deleted = false;
            for (int i = 1; i < s.size(); i++) {
                if (s[i] == s[i-1]) streak++;
                else {
                    streak = 1;
                }
                if (streak == k) {
                    deleted = true;
                    for (int j = i; j > i-streak; j--)
                        s.erase(s.begin()+j);
                    streak = 1;
                }
            }
        }
        return s;
    }
};
