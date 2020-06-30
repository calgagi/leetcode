class Solution {
public:
    
    struct Node {
        string v;
        unordered_map<string, Node*> c;
        Node(string x){ v = x; }
    };
    
    string get_folder(string s, int &x) {
        string r = "";
        for (x = x+1; x < s.size() && s[x] != '/'; x++)
            r += s[x];
        x--;
        return r;
    }
    
    vector<string> get_result(Node* trie) {
        queue<Node*> q;
        q.push(trie);
        vector<string> res;
        while (!q.empty()) {
            Node* t = q.front();
            q.pop();
            if (t->v != "") {
                res.push_back(t->v);
                continue;
            }
            for (auto it : t->c) {
                q.push(it.second);
            }
        }
        return res;
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        Node* trie = new Node("");
        for (int i = 0; i < folder.size(); i++) {
            Node* it = trie;
            for (int j = 0; j < folder[i].size(); j++) {
                string f = get_folder(folder[i], j);
                if (it->c.find(f) == it->c.end())
                    it->c[f] = new Node("");
                it = it->c[f];
            }
            it->v = folder[i];
        }
        return get_result(trie);
    }
};
