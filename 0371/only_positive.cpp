class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, r = 0;
        for (int i = 0; i <= 31; i++) {
            cout << ((1 << i) & a) << " " << ((1 << i) & b) << endl;
            if (((1 << i) & a) && ((1 << i) & b) && carry) {
                r | 1 << i;
                carry = 1;
            } else if (((1 << i) & a) && ((1 << i) & b)) {
                carry = 1;
            } else if (((1 << i) & a) && carry) {
                carry = 1;
            } else if (((1 << i) & b) && carry) {
                carry = 1;
            } else if (((1 << i) & a) || ((1 << i) & b) || carry) {
                r |= 1 << i;
                carry = 0;
            } else {
                carry = 0;
            }
        }
        return r;
    }
};
