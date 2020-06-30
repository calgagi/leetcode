class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices & 1) 
            return vector<int>();
        int sm = (2*cheeseSlices) - (tomatoSlices / 2);
        int jm = (tomatoSlices / 2) - cheeseSlices;
        if (sm < 0 || jm < 0)
            return vector<int>();
        return {jm, sm};
    }
};
