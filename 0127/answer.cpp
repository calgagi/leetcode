class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Make graph, then dijkstra? No. BFS
        wordList.push_back(beginWord);
        vector<vector<bool>> graph(wordList.size(), vector<bool>(wordList.size(), false));
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < i; j++) {
                int d = 0;
                for (int k = 0; k < wordList[0].size(); k++) {
                    if (wordList[i][k] != wordList[j][k]) d++;
                    if (d == 2) break;
                }
                if (d == 1) {
                    graph[i][j] = true;
                    graph[j][i] = true;
                } 
            }
        }
        // Made graph
        // Now can use BFS
        queue<pair<int, int>> s;
        set<int> seen;
        seen.insert(wordList.size()-1);
        s.push({wordList.size()-1, 1});
        while (!s.empty()) {
            int word = s.front().first;
            int path = s.front().second;
            s.pop();
            if (wordList[word] == endWord) return path;
            for (int i = 0; i < wordList.size(); i++) {
                if (graph[word][i] && seen.find(i) == seen.end()) {
                    s.push({i, path+1});
                    seen.insert(i);
                }
            }
        }
        return 0;
    }
};
