class Solution {
public:
    int helper(vector<string>& arr, int i, unordered_set<char>& seen) {
        int res = 0;
        for ( ; i < arr.size(); i++) {
            bool uniq = true;
            for (int j = 0; j < arr[i].length(); j++) {
                if (seen.find(arr[i][j]) != seen.end()) {
                    j--;
                    while (j >= 0) { 
                        seen.erase(arr[i][j]); 
                        j--; 
                    }
                    uniq = false;
                    break;
                }
                seen.insert(arr[i][j]);
            }
            if (uniq) {
                res = max(res, (int)arr[i].length() + helper(arr, i+1, seen));
                for (char& c : arr[i]) seen.erase(c);
            }
        }
        return res;
    }
    
    
    int maxLength(vector<string>& arr) {
        unordered_set<char> seen;
        return helper(arr, 0, seen);
    }
};
