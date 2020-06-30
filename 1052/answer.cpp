class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int c = 0, t = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (!grumpy[i]) t += customers[i];
            if (i < X && grumpy[i]) c += customers[i];
        }
        int m = c;
        for (int i = X; i < customers.size(); i++) {
            if (grumpy[i]) c += customers[i];
            if (grumpy[i-X]) c -= customers[i-X];
            m = max(m, c);
        }
        return t + m;
    }
};
