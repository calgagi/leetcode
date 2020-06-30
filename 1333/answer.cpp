class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> res;
        for (int i = 0; i < restaurants.size(); i++) {
            auto& r = restaurants[i];
            if ((veganFriendly == r[2] || !veganFriendly) && (maxPrice >= r[3]) && (maxDistance >= r[4])) {
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end(), [&](const int& a, const int& b) {
            return (restaurants[a][1] == restaurants[b][1]) ? restaurants[a][0] > restaurants[b][0] : restaurants[a][1] > restaurants[b][1]; 
        });
        for (int i = 0; i < res.size(); i++) {
            res[i] = restaurants[res[i]][0];
        }
        return res;
    }
};
