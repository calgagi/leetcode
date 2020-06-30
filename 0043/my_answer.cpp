class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string> n;
        if (num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string x = "";
        for (int i = 0; i < num1.length(); i++) {
            string y = "";
            for (int j = 0; j < num2.length(); j++) {
                int b = (num1[i] - '0') * (num2[j] - '0');
                string z = "";
                while (b) {
                    z += (char) ((b % 10) + '0');
                    b /= 10;
                }
                n.push_back(y + x + z);
                y += "0";
            }
            x += "0";
        }
        string r = "";
        int carry = 0;
        for (int i = 0; i < n.size(); i++) {
            carry = 0;
            while (r.length() < n[i].length()) r += "0";
            for (int j = 0; j < n[i].length(); j++) {
                int t = (r[j] - '0') + (n[i][j] - '0') + carry;
                carry = t / 10;
                r[j] = (t % 10) + '0';
            }
            if (carry) {
                if (r.length() == n[i].length()) r += "1";
                else {
                    int j = n[i].length();
                    while (carry && j < r.length()) {
                        int t = (r[j] - '0') + carry;
                        r[j] = (t % 10) + '0';
                        carry = t / 10;
                        j++;
                    }
                    if (carry) r += "1";
                }
            }
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
