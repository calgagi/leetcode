struct Node {
    bool present;
    unordered_map<char, Node*> edges;
};


class Trie {
public:
    Node* head;
    
    /** Initialize your data structure here. */
    Trie() {
        this->head = new Node; 
        this->head->present = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* it = this->head;
        for (char &i : word) {
            if (!it->edges.count(i)) {
                it->edges[i] = new Node;
                it->edges[i]->present = false;
            }
            it = it->edges[i];
        }
        it->present = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* it = this->head;
        for (char &i : word) {
            if (!it->edges.count(i)) return false;
            it = it->edges[i];
        }
        return it->present;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* it = this->head;
        for (char &i : prefix) {
            if (!it->edges.count(i)) return false;
            it = it->edges[i];
        }
        return true;       
    }
};
