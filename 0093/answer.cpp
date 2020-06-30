class Solution {
public:
    
    vector<string> res;
    
    void restoreIpAddresses(string& s, int i, string c, int num_dots) {
        if (num_dots > 4) return;
        if (num_dots == 4 && i == s.length())
            res.push_back(c);
        if (s[i] == '0') {
            restoreIpAddresses(s, i+1, c + "." + "0", num_dots+1);  
            return;
        }
        string x = "";
        for (int j = i; j < s.length() && j < i+3; j++) {
            x += s[j];
            if (stoi(x) <= 255)
                restoreIpAddresses(s, j+1, c + "." + x, num_dots+1);
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        restoreIpAddresses(s, 0, "", 0);
        for (auto& r : res) r.erase(r.begin());
        return res;
    }
};
