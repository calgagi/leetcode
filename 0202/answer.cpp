class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while (n != 1 && s.find(n) == s.end()) {
            s.insert(n);
            int x = 0;
            while (n) {
                int a = (n % 10);
                x += a*a;
                n /= 10;
            }
            n = x;
        }
        return n == 1;
    }
};
