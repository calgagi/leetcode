class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool block_com = false, line_com = false;
        string s = "";
        for (auto& line : source) {
            for (int i = 0; i < line.length(); i++) {
                if (!block_com) {
                    if (i+1<line.length()) {
                        if (line[i] == '/' && line[i+1] == '/') {
                            line_com = true;
                            break;
                        } else if (line[i] == '/' && line[i+1] == '*') {
                            block_com = true;
                            i++;
                        }
                    }
                    if (!block_com)
                        s += line[i];
                } else {
                    if (i+1<line.length() && line[i] == '*' && line[i+1] == '/') {
                        block_com = false;
                        i++;
                    }
                }
                if (line_com) break;
            }
            if (!block_com && s != "") {
                res.push_back(s);
                s = "";
            }
            line_com = false;
        }
        return res;
    }
};
