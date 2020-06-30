class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int posA = a.find("+");
        int posB = b.find("+");
        string rNumA = a.substr(0, posA);
        string rNumB = b.substr(0, posB);
        string cNumA = a.substr(posA+1, a.length()-posA-2);
        string cNumB = b.substr(posB+1, b.length()-posB-2);
        int ra = stoi(rNumA);
        int rb = stoi(rNumB);
        int ca = stoi(cNumA);
        int cb = stoi(cNumB);
        int ii = ca * cb * -1;
        int jia = ca * rb;
        int jib = cb * ra;
        int real = ra * rb;
        return to_string(ii + real) + "+" + to_string(jia + jib) + "i";
    }
};
