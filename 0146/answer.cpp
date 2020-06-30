struct Node {
    int val;
    int key;
    Node* next;
    Node* prev;
};

class LRUCache {
public:
    unordered_map<int, Node*> p;
    Node* head;
    Node* tail;
    int size;
    int capacity;
    
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->head = NULL;
        this->tail = NULL;
    }
    
    int get(int key) {
        if (this->p.find(key) == p.end()) return -1;
        put(key, this->p[key]->val);
        return this->p[key]->val;
        
    }
    
    void put(int key, int value) {
        if (this->p.find(key) != p.end()) {
            Node* n = p[key];
            if (n->prev) n->prev->next = n->next;
            else this->head = n->next;
            if (n->next) n->next->prev = n->prev;
            else this->tail = n->prev;
            this->p.erase(n->key);
            delete n;
            this->size--;
        } else if (this->size == this->capacity) {
            Node* nt = this->tail->prev;
            this->p.erase(this->tail->key);
            delete this->tail;
            if (nt) nt->next = NULL;
            this->tail = nt;
            if (!this->tail) this->head = nt;
            this->size--;
        }
        Node* oh = this->head;
        this->head = new Node;
        this->head->next = oh;
        this->head->prev = NULL;
        this->head->val = value;
        this->head->key = key;
        if (oh) oh->prev = this->head;
        if (!this->tail) this->tail = this->head;
        this->p[key] = this->head;
        this->size++;
        return; 
    }
};
