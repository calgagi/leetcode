class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size()-1;
        char ans = letters[0];
        while (l <= r) {
            int m = l + (r-l)/2;
            if(letters[m] <= target) {
                l = m+1;
            } else {
                ans = letters[m];
                r = m-1;
            }
        }
        return ans;
    }
};
