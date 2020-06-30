class Solution {
public:
    vector<int> res;
    unordered_set<string> seen;
    
    void helper(vector<int>& nums, vector<char>& symb) {
        int n = symb.size();
        if (n == 0) {
            res.push_back(nums[0]);
            return;
        }
        string check = "";
        for (int i = 0; i < n; i++) {
            check += to_string(nums[i]) + symb[i];
        }
        check += to_string(nums.back());
        if (seen.find(check) != seen.end()) return;
        seen.insert(check);

        for (int i = 0; i < n; i++) {
            char c = symb[i];
            symb.erase(symb.begin()+i);
            int b, n1 = nums[i], n2 = nums[i+1];
            if (c == '+')
                b = nums[i] + nums[i+1];
            if (c == '-')
                b = nums[i] - nums[i+1];
            if (c == '*')
                b = nums[i] * nums[i+1];
            nums.erase(nums.begin()+i);
            nums[i] = b;
            helper(nums, symb);
            nums[i] = n2;
            nums.insert(nums.begin()+i, n1);
            symb.insert(symb.begin()+i, c);
        }
        return;
    }
    
    vector<int> diffWaysToCompute(string input) {
        const int n = input.length();
        vector<int> nums;
        vector<char> symb;
        for (int i = 0; i < n; i++) {
            int start = i;
            while (i < n && input[i] != '+' && input[i] != '-' && input[i] != '*')
                i++;
            nums.push_back(stoi(input.substr(start, i-start)));
            if (i < n)
                symb.push_back(input[i]);
        }
        helper(nums, symb);
        return res;
    }
};
