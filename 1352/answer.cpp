class ProductOfNumbers {
public:
    vector<int> p;
    
    ProductOfNumbers() {
        p.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            p = {1};
        } else {
            p.push_back(p.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (p.size()-1 < k) {
            return 0;
        }
        return p.back() / p[p.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
