class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> r;
        vector<int> a = A;
        sort(a.begin(), a.end(), greater<int>());
        int temp = 0;
        for (int i = 0; i < a.size(); i++) {
            auto index = find(A.begin(), A.end(), a[i]);
            r.push_back(index-A.begin()+1); 
            reverse(A.begin(), index+1);
            r.push_back(A.size()-temp);
            reverse(A.begin(), A.end()-temp);
            temp += 1;
        }
        return r;
    }
};
