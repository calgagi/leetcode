class Solution {
public:
    int bulbSwitch(int n) {
        // Super interesting problem
        // Basically the only time a bulb is on is if it has an odd amount of 
        // divisors. The only time a number has an odd amount of divisors is
        // when it is a square due to each non-square having two pairs (Ex: [1,3], [3,1]).
        // In order to count the number of squares, the square root of a number gives you
        // the number of squares in the range of [1,n]. Really interesting.
        return sqrt(n);
    }
};
