class NumArray {
public:
    vector<int> tree;
    int size;
    
    void createTree(vector<int>& nums, int v, int tl, int tr) {
        if (tl == tr) {
            this->tree[v] = nums[tl];
        } else {
            int tm = (tl + tr) / 2;
            createTree(nums, v*2, tl, tm);
            createTree(nums, (v*2)+1, tm+1, tr);
            this->tree[v] = this->tree[v*2] + this->tree[(v*2)+1];
        }
    }
    
    NumArray(vector<int>& nums) {
        if (nums.size() == 0) return;
        this->tree.resize(4*nums.size());
        this->size = nums.size()-1;
        this->createTree(nums, 1, 0, nums.size()-1);
    }
    
    void updateRecursive(int v, int tl, int tr, int pos, int val) {
        if (tr == tl) {
            this->tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) updateRecursive(v*2, tl, tm, pos, val);
            else updateRecursive((v*2)+1, tm+1, tr, pos, val);
            this->tree[v] = this->tree[v*2] + this->tree[(v*2)+1];
        }
    }
    
    int sumRecursive(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return this->tree[v];
        int tm = (tl + tr) / 2;
        return sumRecursive(v*2, tl, tm, l, min(r, tm)) + sumRecursive((v*2)+1, tm+1, tr, max(l, tm+1), r);
    }
    
    void update(int i, int val) {
        updateRecursive(1, 0, this->size, i, val);
    }
    
    int sumRange(int i, int j) {
        return sumRecursive(1, 0, this->size, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
