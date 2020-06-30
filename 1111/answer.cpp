class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> r;
        bool a = true;
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                a = !a;
                r.push_back((int)a);
            } else if (seq[i] == ')') {
                r.push_back((int)a);
                a = !a;
            }
        }
        return r;
    }
};
