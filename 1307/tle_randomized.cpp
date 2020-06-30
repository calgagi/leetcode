class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        map<char,int> m;
        int counter = 0;
        for (auto& w : words)
            for (auto& c : w)
                if (m.find(c) == m.end())
                    m[c] = counter++;
        for (auto& c : result)
            if (m.find(c) == m.end())
                m[c] = counter++;
        counter = 0;
        unordered_set<string> seen;
        while (counter < 100) {
            vector<int> taken = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            string s = "";
            for (auto& p : m) {
                int i = rand()%((int)taken.size());
                p.second = taken[i];
                taken.erase(taken.begin()+i);
                s += (char)(p.second + '0');
            }
            if (seen.find(s) != seen.end()) {
                counter++;
                continue;
            } else {
                counter = 0;
                seen.insert(s);
            }
            long long left = 0, right = 0;
            bool zero = 0;
            for (auto& w : words) {
                string val = "";
                if (m[w[0]] == 0) {
                    zero = 1;
                    break;
                }
                for (auto& c : w) {
                    val += (char)(m[c] + '0');
                }
                left += stoi(val);
            }
            if (zero || m[result[0]] == 0) continue;
            string val = "";
            for (auto& c : result) {
                val += (char)(m[c] + '0');
            }
            right = stoi(val);
            if (right == left) return true;
        }
        return false;
    }
        
    
};
