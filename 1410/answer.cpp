class Solution {
public:
    string entityParser(string text) {
        int n = text.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (text[i] == '&') {
                string cur = "";
                int f = 0;
                for (int j = i; j-i < 8 && j < n; j++) {
                    cur += text[j];
                    if (cur == "&quot;") {
                        f = 6;
                        ans += "\"";
                    } else if (cur == "&apos;") {
                        f = 6;
                        ans += "\'";
                    } else if (cur == "&amp;") {
                        f = 5;
                        ans += "&";
                    } else if (cur == "&gt;") {
                        f = 4;
                        ans += ">";
                    } else if (cur == "&lt;") {
                        f = 4;
                        ans += "<";
                    } else if (cur == "&frasl;") {
                        f = 7;
                        ans += "/";
                    }
                }
                if (f == 0) {
                    ans += text[i];
                } else {
                    i += f-1;
                }
            } else {
                ans += text[i];
            }
        }
        return ans;
    }
};
