class Solution {
public:
    struct Node {
        char v;
        bool p;
        unordered_map<char, Node*> c;
        vector<string> here;
        Node(char x, bool y) {
            v = x;
            p = y;
        }
    };
    
    Node* head;
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Trie?
        head = new Node(' ', false);
        for (string& s : products) {
            Node* it = head;
            for (int i = 0; i < s.length(); i++) {
                if (!it->c.count(s[i])) it->c[s[i]] = new Node(s[i], false);
                it = it->c[s[i]];
                it->here.push_back(s);
            }
            it->p = true;
        }
        
        vector<vector<string>> res;
        Node* it = head;
        for (int i = 0; i < searchWord.length(); i++) {
            if (!it->c.count(searchWord[i])) it->c[searchWord[i]] = new Node(searchWord[i], false);
            it = it->c[searchWord[i]];
            sort(it->here.begin(), it->here.end());
            vector<string> x;
            for (int j = 0; j < 3 && j < it->here.size(); j++) x.push_back(it->here[j]);
            res.push_back(x);
        }
        return res;
    }
};
