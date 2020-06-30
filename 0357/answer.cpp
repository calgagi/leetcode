class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        
        int res = 10;
        int unique = 9;
        int availableNumber = 9;
        while (n > 1 && availableNumber > 1) {
            unique = unique * availableNumber;
            res += unique;
            availableNumber--;
            n--;
        }
        return res;
    }
};
