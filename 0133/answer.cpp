/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        m[NULL] = NULL;
        m[node] = new Node(node->val, node->neighbors);
        stack<Node*> s;
        s.push(node);
        while (!s.empty()) {
            Node* t = s.top();
            s.pop();
            for (int i = 0; i < t->neighbors.size(); i++) {
                bool add = false;
                if (!m[t->neighbors[i]]) {
                    m[t->neighbors[i]] = new Node(t->neighbors[i]->val, t->neighbors[i]->neighbors);
                    add = true;
                }
                m[t]->neighbors[i] = m[t->neighbors[i]];
                if (add) s.push(t->neighbors[i]);
            }
        }
        return m[node];
        
    }
};
