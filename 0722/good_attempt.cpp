class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string start = "";
        for (auto& s : source) {
            start += s;
            start += "\n";
        }
        for (int i = 0; i < (int) start.length(); i++) {
            // BLOCK
            if (start[i] == '/' && i+1 < (int) start.length() && start[i+1] == '*') {
                int a = i;
                i += 2;
                while (i+1 < (int) start.length() && !(start[i+1] == '/' && start[i] == '*')) i++;
                if (i+1 < (int) start.length()) i++;
                start.erase(start.begin()+a, start.begin()+i+1);
                i = a;
                if (start[i] == '\n' && (i-1<0 || start[i-1] == '\n'))
                    start.erase(start.begin()+i);
            }
            // LINE
            else if (start[i] == '/' && i+1 < (int) start.length() && start[i+1] == '/') {
                int a = i;
                i += 2;
                while (i < (int) start.length() && start[i] != '\n') i++;
                start.erase(start.begin()+a, start.begin()+i);
                i = a;
                if (start[i] == '\n' && (i-1<0 || start[i-1] == '\n'))
                    start.erase(start.begin()+i);
            }
        }
        //cout << start << endl;
        vector<string> res;
        for (int i = 0; i < (int) start.length(); i++) {
            int a = i;
            while (i < (int) start.length() && start[i] != '\n') i++;
            if (i < (int) start.length())
                res.push_back(start.substr(a, i-a));
            else
                res.push_back(start.substr(a));
        }
        return res;
    }
};
