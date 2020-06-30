class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, n = name.length(), t = typed.length();
        while (i < n && j < t) {
            int starti = i, startj = j;
            while (i < n && name[i] == name[starti]) i++;
            while (j < t && typed[j] == typed[startj]) j++;
            if (i-starti > j-startj) return false;
        }
        return i == n && j == t;
    }
};
