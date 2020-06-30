class Solution {
public:
    string addStrings(string num1, string num2) {
        int i1 = num1.length()-1, i2 = num2.length()-1;
        int carry = 0;
        string r = "";
        while (i1 >= 0 || i2 >= 0) {
            int n = carry;
            if (i1 >= 0) {
                n += num1[i1] - '0';
                i1--;
            }
            if (i2 >= 0) {
                n += num2[i2] - '0';
                i2--;
            }
            string temp = to_string(n);
            r.insert(r.begin(), temp.back());
            carry = temp.length() == 2;
        }
        if (carry) r.insert(r.begin(), '1');
        return r;
    }
};
