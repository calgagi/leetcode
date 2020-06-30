class Solution {
public:
    int getSum(int a, int b) {
        int r = 0;
        b = (unsigned int) b;
        a = (unsigned int) a;
        int c = 0;
        for (int i = 0; i < 31; i++) {
            r |= (((1 << i) & a) ^ ((1 << i) & b)) | c;
            c = (((1 << i) & a) & ((1 << i) & b)) << 1;
        }
        return r;
    }
};
