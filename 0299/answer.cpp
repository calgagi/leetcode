class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> s;
        unordered_map<char,int> c;
        int cows = 0, bulls = 0;

        for (int i = 0; i < guess.length(); i++){
            s[secret[i]]++;
            c[guess[i]]++;
            if (secret[i] == guess[i]) bulls++;
        }
        for (auto it = c.begin(); it != c.end(); it++) {
            if (s.find(it->first) != s.end())
                cows += min(it->second, s[it->first]);
        }
        return to_string(bulls) + "A" + to_string(cows-bulls) + "B";
    }
};
