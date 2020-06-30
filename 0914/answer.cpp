class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> counts;
        for (auto& card : deck) {
            counts[card]++;
        }
        int MIN = counts[deck[0]];
        for (auto& c : counts) {
            MIN = gcd(c.second, MIN);
        }
        return MIN >= 2;
    }
};
