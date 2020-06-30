/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        // strategy: guess first word, find all words with g
        // Repeat 10 times
        int num = 0;
        vector<string> p = wordlist;
        for (int t = 0; t < 10; t++) {
            int x = rand()%(int)p.size();
            int g = master.guess(p[x]);
            vector<string> ps;
            for (auto& w : p) {
                int c = 0;
                for (int i = 0; i < 6; i++)
                    if (w[i] == p[x][i])
                        c++;
                if (c == g)
                    ps.push_back(w);
            }
            p = ps;
        }
        return;
    }
};
