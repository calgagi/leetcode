class Solution {
public:
    vector<string> words;
    string result;
    map<char,int> nums;
    vector<bool> used;
    
    bool assign_chars(vector<char> chars, int idx, int carry) {
        if ((int) chars.size() == 0) {
            return false;
        }
        char to_assign = chars.back();
        chars.pop_back();
        
        // Assign one char at a time
        for (int i = 0; i < 10; i++) {
            if (!used[i]) {
                nums[to_assign] = i;
                used[i] = true;
                if ((int) chars.size() == 0) {
                    // Calculate if result[idx] == (all_words[idx]+carry) % 10
                    int tot = carry;
                    for (auto& w : words) {
                        tot += nums[w[idx]];
                    }
                    if (tot % 10 == nums[result[idx]]) {
                        if (dfs(idx+1, tot / 10)) {
                            return true;
                        }
                    }
                } else {
                    if (assign_chars(chars, idx, carry)) {
                        return true;
                    }
                }
                nums.erase(to_assign);
                used[i] = false;
            }
        }
        chars.push_back(to_assign);
        return false;
    }
    
    
    bool dfs(int idx, int carry) {
        // Found solution conditions
        if (carry == 0 && idx >= (int) result.length() && nums[result.back()] != 0) {
            return true;
        } else if (idx >= (int) result.length()) {
            return false;
        }
        
        int total = carry;
        
        // Find all characters still needing to be assigned at current index
        set<char> need_assigned;
        for (auto& w : words) {
            if ((int) w.length() > idx) {
                if (nums.find(w[idx]) == nums.end()) {
                    need_assigned.insert(w[idx]);
                } else {
                    total += nums[w[idx]];
                }
            }
        }
        if (nums.find(result[idx]) == nums.end()) {
            need_assigned.insert(result[idx]);
        }
        vector<char> na(need_assigned.begin(), need_assigned.end());
        
        // If nothing needs to be assigned, check if it works
        if (na.size() == 0 && (total % 10) == nums[result[idx]]) {
            return dfs(idx+1, total / 10);
        } else {
            if (assign_chars(na, idx, carry)) {
                return true;
            }
        }
        return false;
    }
    
    bool isSolvable(vector<string>& words, string result) {
        // Reverse words so that we don't have to do annoying arithmetic
        this->words = words;
        for (auto& word : this->words) {
            reverse(word.begin(), word.end());
        }
        this->result = result;
        reverse(this->result.begin(), this->result.end());
        
        used.assign(10, false);
        
        return dfs(0, 0);
    }
};
