class Solution {
public:
    set<string> s;
    
    int numTilePossibilities(string tiles) {
        search(tiles, "");
        return s.size();
    }

    void search(string tiles, string t) {
        for (int j = 0; j < tiles.length(); j++) {
            t += tiles[j];
            s.insert(t);
            tiles.erase(tiles.begin()+j);
            search(tiles, t);
            tiles.insert(tiles.begin()+j, t.back());
            t.pop_back();
        }
            
    }
    
};
