class Solution {
public:
    int res;
    vector<int> scores;
    vector<string> word;
    
    void dfs(unordered_map<char,int> allowed, int c, int i) {
        auto backup = allowed;
        int score = c;
        bool good = true;
        for(int j = 0; j < word[i].length(); j++) {
            allowed[word[i][j]]--;
            score += scores[word[i][j]-'a'];
            if (allowed[word[i][j]] < 0) {
                good = false;
                break;
            }
        }
        if (!good) {
            allowed = backup;
            score = c;
        }
        res = max(score, res);
        for(int j = i+1; j < word.size(); j++)
            dfs(allowed, score, j);
        return;
    }
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        word = words;
        scores = score;
        unordered_map<char,int> allowed;
        res = 0;
        for(auto& c : letters) allowed[c]++;
        
        for(int i = 0; i < words.size(); i++)
            dfs(allowed, 0, i);
        return res;
    }
};
