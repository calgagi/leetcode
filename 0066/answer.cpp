class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i >= 0; i--) {
            digits[i]++;
            if (digits[i] % 10 != 0) break;
            digits[i] = 0;
        }
        if (digits[0] == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};
