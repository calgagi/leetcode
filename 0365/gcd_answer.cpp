class Solution {
public:
    
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    
    bool canMeasureWater(int x, int y, int z) {
        if (x == z || x+y == z || y == z || z == 0) return true;
        
        if (x+y < z) return false;
        
        int g = gcd(x, y);
        
        return z % g == 0;
    }
};
