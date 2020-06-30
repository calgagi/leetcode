class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> pos;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (pos.find(val) != pos.end()) return false;
        nums.push_back(val);
        pos[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (pos.find(val) == pos.end()) return false;
        int val_pos = pos[val], swapped_val = nums[nums.size()-1];
        swap(nums[nums.size()-1], nums[val_pos]);
        pos[swapped_val] = val_pos;
        pos.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
