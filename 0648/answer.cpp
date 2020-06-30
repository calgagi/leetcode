class Solution {
public:
    struct Node {
        int pres;
        unordered_map<char, Node*> connections; 
    };
    
    string replaceWords(vector<string>& dict, string sentence) {
        // Create trie
        Node *head = new Node;
        head->pres = 0;
        for (int i = 0; i < dict.size(); i++) {
            Node *it = head;
            for (int j = 0; j < dict[i].size(); j++) {
                if (it->connections.find(dict[i][j]) == it->connections.end()) {
                    it->connections[dict[i][j]] = new Node;
                    it->connections[dict[i][j]]->pres = 0;
                }
                it = it->connections[dict[i][j]];
            }
            it->pres = 1;
        }
        for (int i = 0; i < sentence.length(); i++) {
            Node* it = head;
            if (it->connections.count(sentence[i])) {
                it = it->connections[sentence[i]];
                i++;
                while (!it->pres && it->connections.count(sentence[i])) {
                    it = it->connections[sentence[i]];
                    i++;
                } 
                if (it->pres)
                    while (i < sentence.length() && sentence[i] != ' ')
                        sentence.erase(sentence.begin()+i);
            }
            while (i < sentence.length() && sentence[i] != ' ') i++;
        }
        return sentence;
    }
};
