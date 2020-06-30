/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        unordered_map<Node*, Node*> m;
        m[NULL] = NULL;
        queue<Node*> q;
        q.push(head);
        unordered_map<Node*, bool> s;
        s[NULL] = true;
        while (!q.empty()) {
            Node* t = q.front();
            q.pop();
            if (s.find(t) != s.end()) continue;
            s[t] = true;
            if (m.find(t) == m.end())
                m[t] = new Node(t->val, NULL, NULL);
            if (m.find(t->next) == m.end())
                m[t->next] = new Node(t->next->val, NULL, NULL);
            m[t]->next = m[t->next];
            if (m.find(t->random) == m.end())
                m[t->random] = new Node(t->random->val, NULL, NULL);
            m[t]->random = m[t->random];
            q.push(t->next);
            q.push(t->random);
        }
        return m[head];
    }
};
