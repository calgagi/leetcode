class Solution {
public:
    string toHex(int num) {
        string res = "";
        for (int i = sizeof(num) * 8 - 1; i > 0; i -= 4) {
            int b = 0;
            for (int j = 0; j < 4; j++) b += pow(2, 3-j) * (((1 << i-j) & num) ? 1 : 0);
            if (b == 0 && res == "") continue;
            else if (b <= 9) res += '0' + b;
            else res += 'a' + (b-10);
        }
        return (res == "" ? "0" : res);
    }
};
