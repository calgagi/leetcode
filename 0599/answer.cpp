class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> s;
        for (int i = 0; i < list1.size(); i++) s[list1[i]] = i;
        int x = INFINITY;
        vector<string> r;
        for (int i = 0; i < list2.size(); i++) 
            if (s.count(list2[i]) && s[list2[i]]+i < x)
                x = s[list2[i]]+i;
        for (int i = 0; i < list2.size(); i++)
            if (s.count(list2[i]) && s[list2[i]]+i == x)
                r.push_back(list2[i]);
        return r;
    }
};
