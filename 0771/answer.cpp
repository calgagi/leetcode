class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> j;
        for (auto& i : J) {
            j.insert(i);
        }
        int ans = 0;
        for (auto& x : S) {
            if (j.count(x)) {
                ans++;
            }
        }
        return ans;
    }
};
