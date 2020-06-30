class Solution {
public:
    string getHappyString(int n, int k) {
        string ans = "";
        int t = 3;
        for (int i = 1; i < n; i++) {
            t *= 2;
        } 
        if (k > t) {
            return "";
        }
        if (k <= t / 3) {
            ans += 'a';
        } else if (k <= 2 * t / 3) {
            ans += 'b';
            k -= t / 3;
        } else {
            ans += 'c';
            k -= 2 * t / 3;
        }
        t /= 3;
        //cout << "HERE" << endl;
        for (int i = 1; i < n; i++) {
            t /= 2;
            if (k > t) {
                k -= t;
                if (ans[i - 1] == 'a' || ans[i - 1] == 'b') {
                    ans += 'c';
                } else {
                    ans += 'b';
                }
            } else {
                if (ans[i - 1] == 'b' || ans[i - 1] == 'c') {
                    ans += 'a';
                } else {
                    ans += 'b';
                }
            }
            //cout << k << " " << t << " " << ans << endl;
        }
        return ans;
    }
};
