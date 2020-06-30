/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> levels;
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            int l = q.front().second;
            Node* t = q.front().first;
            q.pop();
            if (!t) continue;
            if (l > levels.size()) levels.push_back(vector<Node*>());
            levels[l-1].push_back(t);
            q.push({t->left, l+1});
            q.push({t->right, l+1});
        }
        
        for (int i = 0; i < levels.size(); i++) {
            for (int j = 0; j < levels[i].size()-1; j++) {
                levels[i][j]->next = levels[i][j+1];
            }
        }
        
        return root;
    }
};
