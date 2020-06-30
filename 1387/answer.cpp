class Solution {
public:
    map<int,int> power;

    int p(int a) {
        if (power.find(a) != power.end()) {
            return power[a];
        }
        if ((a&1)) {
            power[a] = p(3*a+1)+1;
        } else {
            power[a] = p(a/2)+1;
        }
        return power[a];
    }
    
    int getKth(int lo, int hi, int k) {
        vector<int> s;
        power[1] = 0;
        for (int i = lo; i <= hi; i++) {
            int x = p(i);
            s.push_back(i);
        }
        sort(s.begin(), s.end(), [&](const int& a, const int& b) {
            return power[a] == power[b] ? a < b : power[a] < power[b];
        });
        return s[k-1];
    }
};
