struct Node {
    int val;
    Node* prev;
    Node* next;
};

class MyCircularDeque {
public:
    int capacity;
    int size;
    
    Node* head;
    Node* tail;
    
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        this->capacity = k;
        this->size = 0;
        this->head = this->tail = NULL;
    }
    
    bool start(int value) {
        this->head = new Node;
        this->head->val = value;
        this->head->prev = NULL;
        this->head->next = NULL;
        this->size++;
        this->tail = this->head;
        return true;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (this->isFull()) 
            return false;
        else if (this->isEmpty())
            return this->start(value);
        Node* old_head = this->head;
        this->head = new Node;
        this->head->val = value;
        this->head->next = old_head;
        this->head->prev = NULL;
        old_head->prev = this->head;
        this->size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (this->isFull())
            return false;
        else if (this->isEmpty())
            return this->start(value);
        Node* old = this->tail;
        this->tail->next = new Node;
        this->tail = this->tail->next;
        this->tail->prev = old;
        this->tail->next = NULL;
        this->tail->val = value;
        this->size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (this->isEmpty()) 
            return false;
        Node* old_head = this->head;
        this->head = this->head->next;
        delete old_head;
        this->size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (this->isEmpty())
            return false;
        Node* old = this->tail;
        this->tail = this->tail->prev;
        delete old;
        this->size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (this->isEmpty()) 
            return -1;
        return this->head->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
       if (this->isEmpty())
           return -1;
        return this->tail->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return !this->size;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return this->size == this->capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
