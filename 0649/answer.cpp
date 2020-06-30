struct Node {
    Node* next;
    char a;
};


class Solution {
public:
    
    string predictPartyVictory(string senate) {
        int countR = 0, countD = 0, R = 0, D = 0;
        Node* head = new Node;
        Node* it = head;
        for (int i = 0; i < senate.length(); i++) {
            it->next = new Node;
            it = it->next;
            it->a = senate[i];
            if (it->a == 'R') countR++;
            else if (it->a == 'D') countD++;
        }
        it->next = head->next;
        
        while (countR != 0 && countD != 0) {
            while ((R && it->next->a == 'R') || (D && it->next->a == 'D'))  {
                if (it->next->a == 'R') {
                    R--;
                    countR--;
                } else if (it->next->a == 'D') {
                    D--;
                    countD--;
                }
                Node* t = it->next;
                it->next = it->next->next;
                delete t;
            }
            if (it->next->a == 'R') {
                D++;
            } else if (it->next->a == 'D') {
                R++;
            }
            it = it->next;
        }
        if (countR) return "Radiant";
        if (countD) return "Dire";
        return "BAD";
    }
};
