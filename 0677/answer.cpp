class MapSum {
public:
    struct Node {
        int v = 0;
        unordered_map<char, Node*> c;
    };
    
    Node* trie; 
    unordered_map<string, int> m;
    
    /** Initialize your data structure here. */
    MapSum() {
        this->trie = new Node;
        this->trie->v = 0;
    }
    
    void insert(string key, int val) {
        int old = m.find(key) != m.end() ? m[key] : 0;
        m[key] = val;
        Node* it = this->trie;
        for (int i = 0; i < key.length(); i++) {
            if (it->c.find(key[i]) == it->c.end())
                it->c[key[i]] = new Node;
            it = it->c[key[i]];
            it->v -= old;
            it->v += val;
        }
        return;
    }
    
    int sum(string prefix) {
        Node* it = this->trie;
        for (int i = 0; i < prefix.length(); i++) {
            if (it->c.find(prefix[i]) == it->c.end())
                return 0;
            it = it->c[prefix[i]];
        }
        return it->v;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
