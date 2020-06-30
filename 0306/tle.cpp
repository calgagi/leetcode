class Solution {
public:
    bool helper(string num, string prev, string prev2) {
        if (num == "" || prev == "" || prev2 == "") return false;
        // Addition
        bool carry = false;
        string add = "";
        for (int i = prev.size()-1, j = prev2.size()-1; j >= 0 || i >= 0; j--, i--) {
            char x = '0';
            if (i >= 0) x += prev[i] - '0';
            if (j >= 0) x += prev2[j] - '0';
            if (carry) {
                x += 1;
                carry = false;
            }
            if (x > '9') {
                x -= 9;
                carry = true;
            }
            add = x + add;
        }
        if (carry) {
            add = '1' + add;
        }
        if (num == add) return true;
        
        string ii = "";
        for (int i = 0; i < num.size(); i++) {
            ii += num[i];
            if (ii == "0") break;
            if (helper(num.substr(i+1), ii, prev)) return true;
        }
        return false;
    }
    
    
    bool isAdditiveNumber(string num) {
        return helper(num, "0", "0");
    }
};
