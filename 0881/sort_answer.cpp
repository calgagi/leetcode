class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int b = 0, e = people.size()-1;
        int r = 0;
        while (b <= e) {
            if (people[b] + people[e] <= limit) {
                r++;
                e--;
                b++;
            } else {
                r++;
                e--;
            }
        }
        return r;
    }
};
