class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((c&(1<<i)) && (!(b&(1<<i)) && !(a&(1<<i)))) {
                res++;
            } else if (!(c&(1<<i))) {
                if ((b&(1<<i))) {
                    res++;
                }
                if ((a&(1<<i))) {
                    res++;
                }
            }
        }
        return res;
    }
};
