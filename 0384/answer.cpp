class Solution {
public:
    vector<int> original;
    vector<int> shufflea;
    
    Solution(vector<int>& nums) {
        srand(time(NULL));
        this->original = nums;
        this->shufflea = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        this->shufflea = this->original;
        return this->original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < this->shufflea.size(); i++) {
            int r = rand()%(this->shufflea.size()-i);
            int temp = shufflea[r];
            shufflea[r] = shufflea[shufflea.size()-i-1];
            shufflea[shufflea.size()-i-1] = temp;
        } 
        return shufflea;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
