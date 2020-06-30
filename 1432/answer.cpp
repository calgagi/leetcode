class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num), b = to_string(num);
        for (int i = 0; i < (int) a.size(); i++) {
            if (a[i] != '9') {
                char x = a[i];
                for (; i < (int) a.size(); i++) {
                    if (a[i] == x) {
                        a[i] = '9';
                    }
                }
            }
        }
        if (b[0] != '1') {
            char x = b[0];
            for (int i = 0; i < (int) b.size(); i++) {
                if (x == b[i]) {
                    b[i] = '1';
                }
            }
        } else {
            for (int i = 1; i < (int) b.size(); i++) {
                if (b[i] != '0' && b[i] != '1') {
                    char x = b[i];
                    for (; i < (int) b.size(); i++) {
                        if (b[i] == x) {
                            b[i] = '0';
                        }
                    }
                }
            }
        }
        //cout << a << " " << b << endl;
        return stoll(a) - stoll(b);
    }
};
