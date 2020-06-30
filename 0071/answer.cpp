class Solution {
public:
    string simplifyPath(string path) {
        string r = "";
        stack<string> s;
        vector<string> folders;
        string c = "";
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/' && c != "") {
                folders.push_back(c);
                c = "";
            } else if (path[i] == '/') continue;
            else c = c + path[i];
        }
        if (c != "") folders.push_back(c);
        
        for (int i = 0; i < folders.size(); i++) {
            if (folders[i] == ".") continue;
            else if (folders[i] == ".." && !s.empty()) s.pop();
            else if (folders[i] != "..") s.push(folders[i]);
        }
        
        while (!s.empty()) {
            if (r != "")
                r = s.top() + "/" + r;
            else
                r = s.top();
            s.pop();
        }
        return "/" + r;
    }
};
