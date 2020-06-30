class Solution {
public:
    string special(const string& a) {
        string odd = "", even = "";
        for (int i = 0; i < (int) a.length(); i++)
            if (i % 2) odd += a[i];
            else even += a[i];
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        return odd+even;
    }
    
    int numSpecialEquivGroups(vector<string>& A) {
        int res = 0, n = A.size();
        unordered_map<string,int> s;
        for (int i = 0; i < n; i++) {
            string h = special(A[i]);
            res = max(res, ++s[h]);
        }
        return (int) s.size();
    }
};
