class Solution {
public:
    
    struct Node {
        bool v;
        unordered_map<string, Node*> c;
        Node(bool x){ v = x; }
    };
    
    string get_folder(string s, int &x) {
        string r = "";
        for (x = x+1; x < s.size() && s[x] != '/'; x++)
            r += s[x];
        return r;
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        Node* trie = new Node(false);
        for (int i = 0; i < folder.size(); i++) {
            Node* it = trie;
            for (int j = 0; j < folder[i].size(); j++) {
                if (it->v) {
                    folder.erase(folder.begin()+i);
                    i--;
                    break;
                }
                string f = get_folder(folder[i], j);
                if (it->c.find(f) == it->c.end())
                    it->c[f] = new Node(false);
                it = it->c[f];
            }
            it->v = true;
        }
        return folder;
    }
};
