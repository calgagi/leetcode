class Solution {
public:
    int get_num(string s, int i) {
        string r = "";
        while (i < s.length() && s[i] != '-') {
            r += s[i];
            i++;
        }
        return stoi(r);
    }
    
    int daysBetweenDates(string date1, string date2) {
        if (date1 > date2) {
            swap(date1, date2);
        }
        int year1 = get_num(date1, 0), year2 = get_num(date2, 0);
        int month1 = get_num(date1, 5), month2 = get_num(date2, 5);
        int day1 = get_num(date1, 8), day2 = get_num(date2, 8);
        
        int res = abs(year1 - year2)*365;
        vector<int> md = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int tot1 = 0, tot2 = 0;
        for (int i = 0; i < month1-1; i++) {
            tot1 += md[i];
        }
        for (int i = 0; i < month2-1; i++) {
            tot2 += md[i];
        }
        tot1 += day1;
        tot2 += day2;
        res += tot2 - tot1;
        
        // Find leap years
        if (month1 <= 2) {
            year1--;
        }
        if (month2 <= 2) {
            year2--;
        }
        int leap1 = year1 / 4 - year1 / 100 + year1 / 400;
        int leap2 = year2 / 4 - year2 / 100 + year2 / 400;
    
        res += (leap2 - leap1);
            
        return res;
    }
};
