/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* it = head;
        while (it) {
            if (it->child) {
                Node* t = it->next;
                it->next = flatten(it->child);
                it->child = NULL;
                it->next->prev = it;
                while (it->next) it = it->next;
                it->next = t;
                if (t) t->prev = it;
            }
            it = it->next;
        }
        return head;
    }
};
