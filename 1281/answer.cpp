class Solution {
public:
    int subtractProductAndSum(int n) {
        int sub = 0, pro = 1;
        while (n != 0) {
            sub += n % 10;
            pro *= n % 10;
            n /= 10;
        }
        return pro - sub;
    }
};
