class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> r;
        while (!deck.empty()) {
            if (!r.empty()) {
                r.push_back(r.front());
                r.erase(r.begin());
            }
            r.push_back(deck.back());
            deck.pop_back();
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
