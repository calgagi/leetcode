class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, emptyBottles = 0;
        while (numBottles) {
            //cout << numBottles << endl;
            ans += numBottles;
            emptyBottles += numBottles;
            numBottles = emptyBottles / numExchange;
            if (numBottles != 0) {
                emptyBottles %= numExchange;
            }
        }
        return ans;
    }
};
