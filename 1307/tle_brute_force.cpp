class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        map<char,int> m;
        int counter = 0;
        for (auto& w : words)
            for (auto& c : w)
                if (m.find(c) == m.end())
                    m[c] = counter++;
        for (auto& c : result)
            if (m.find(c) == m.end())
                m[c] = counter++;
        vector<int> taken = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int a1 = 0; a1 < (int) taken.size(); a1++) {
            int a = taken[a1];
            taken.erase(taken.begin()+a1);
            for (int b1 = 0; b1 < 9; b1++) {
                int b = taken[b1];
                taken.erase(taken.begin()+b1);
                for (int c1 = 0; c1 < 8; c1++) {
                    int c = taken[c1];
                    taken.erase(taken.begin()+c1);
                    for (int d1 = 0; d1 < 7; d1++) {
                        int d = taken[d1];
                        taken.erase(taken.begin()+d1);
                        for (int e1 = 0; e1 < 6; e1++) {
                            int e = taken[e1];
                            taken.erase(taken.begin()+e1);
                            for (int f1 = 0; f1 < 5; f1++) {
                                int f = taken[f1];
                                taken.erase(taken.begin()+f1);
                                for (int g1 = 0; g1 < 4; g1++) {
                                    int g = taken[g1];
                                    taken.erase(taken.begin()+g1);
                                    for (int h1 = 0; h1 < 3; h1++) {
                                        int h = taken[h1];
                                        taken.erase(taken.begin()+h1);
                                        for (int i1 = 0; i1 < 2; i1++) {
                                            int i = taken[i1];
                                            taken.erase(taken.begin()+i1);
                                            for (int j1 = 0; j1 < 1; j1++) {
                                                int j = taken[j1];
                                                int ii = 0;
                                                for (auto& p : m) {
                                                    switch (ii) {
                                                        case 0:
                                                            p.second = a;
                                                            break;
                                                        case 1:
                                                            p.second = b;
                                                            break;
                                                        case 2:
                                                            p.second = c;
                                                            break;
                                                        case 3:
                                                            p.second = d;
                                                            break;
                                                        case 4:
                                                            p.second = e;
                                                            break;
                                                        case 5:
                                                            p.second = f;
                                                            break;
                                                        case 6:
                                                            p.second = g;
                                                            break;
                                                        case 7:
                                                            p.second = h;
                                                            break;
                                                        case 8:
                                                            p.second = i;
                                                            break;
                                                        case 9:
                                                            p.second = j;
                                                            break;
                                                    }
                                                    ii++;
                                                }
                                                long long left = 0, right = 0;
                                                bool zero = 0;
                                                for (auto& w : words) {
                                                    string val = "";
                                                    if (m[w[0]] == 0) {
                                                        zero = 1;
                                                        break;
                                                    }
                                                    for (auto& c : w) {
                                                        val += (char)(m[c] + '0');
                                                    }
                                                    left += stoi(val);
                                                }
                                                if (zero || m[result[0]] == 0) continue;
                                                string val = "";
                                                for (auto& c : result) {
                                                    val += (char)(m[c] + '0');
                                                }
                                                right = stoi(val);
                                                if (right == left) return true;
                                            }
                                            taken.insert(taken.begin()+i1, i);
                                        }
                                        taken.insert(taken.begin()+h1, h);
                                    }
                                    taken.insert(taken.begin()+g1, g);
                                }
                                taken.insert(taken.begin()+f1, f);
                            }
                            taken.insert(taken.begin()+e1, e);
                        }
                        taken.insert(taken.begin()+d1, d);
                    }
                    taken.insert(taken.begin()+c1, c);
                }            
                taken.insert(taken.begin()+b1, b);
            }
            taken.insert(taken.begin()+a1, a);
        }
        return false;
    }
        
    
};
