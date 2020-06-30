class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> seen; 
        for (int i = 0; i < numbers.size(); i++) {
            if (seen.find(target - numbers[i]) != seen.end()) {
                vector<int> r{seen[target-numbers[i]], i+1};
                return r;
            }
            seen[numbers[i]] = i+1;
        }
        vector<int> r;
        return r;
    }
};
