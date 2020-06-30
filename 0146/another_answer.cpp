class LRUCache {
public:
    struct Node {
        Node* next;
        Node* prev;
        int val;
        int key;
        Node(Node* n, Node* p, int v, int k) {
            next = n;
            prev = p;
            val = v;
            key = k;
        }
    };
    
    Node* head;
    Node* tail;
    int capacity;
    int size;
    unordered_map<int, Node*> x;

    LRUCache(int capacity) {
        head = NULL;
        tail = NULL;
        size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (x.find(key) == x.end())
            return -1;
        put(key, x[key]->val);
        return x[key]->val;
    }
    
    void put(int key, int value) {
        if (x.find(key) != x.end()) {
            Node* t = x[key];
            t->val = value;
            if (t->prev) t->prev->next = t->next;
            else head = t->next;
            if (t->next) t->next->prev = t->prev;
            else tail = t->prev;
            x.erase(t->key);
            delete t;
            size--;
        } else if (size == capacity) {
            Node* new_head = head->next;
            if (new_head) new_head->prev = NULL;
            if (head == tail) tail = NULL;
            x.erase(head->key);
            delete head;
            head = new_head;
            size--;
        }
        Node* t = new Node(NULL, NULL, value, key);
        x[key] = t;
        if (tail) {
            tail->next = t;
            t->prev = tail;
            tail = t;
        } else {
            tail = t;
            head = t;
        }
        size++;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
