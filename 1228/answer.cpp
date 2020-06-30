class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int diff1 = arr[1]-arr[0], diff2 = arr[2]-arr[1];
        vector<int> c(2, 0);
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i]-arr[i-1] != diff1)
                diff2 = arr[i]-arr[i-1];
            if (arr[i]-arr[i-1] == diff1)
                c[0]++;
            else if (arr[i]-arr[i-1] == diff2)
                c[1]++;
        }
        int search = -1;
        if (c[0] < c[1])
            search = diff1;
        else if (c[1] < c[0])
            search = diff2;
        else 
            if (abs(diff1) < abs(diff2))
                search = diff2;
            else
                search = diff1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i]-arr[i-1] == search)
                return arr[i-1] + search/2;
        }
        return -1;
    }
};
