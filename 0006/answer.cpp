class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char> > rows(numRows);
        int i = 0;
        while (i < s.length()) {
            for (int j = 0; j < numRows && i < s.length(); j++, i++)
                rows[j].push_back(s[i]);
            for (int j = numRows-2; j >= 1 && i < s.length(); i++, j--)
                rows[j].push_back(s[i]);
        }
        string r = "";
        for (int j = 0; j < numRows; j++)
            for (int k = 0; k < rows[j].size(); k++)
                r += rows[j][k];
        return r;
    }
};
