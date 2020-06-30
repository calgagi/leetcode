// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int total = 40;
        while (total > 39) {
            total = (rand7()-1)*7 + (rand7()-1);
        }
        return total % 10 + 1;
    }
};
