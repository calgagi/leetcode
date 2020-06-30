class MyCalendar {
public:
    map<int,int> cal;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = cal.upper_bound(start);
        if (it == cal.end() || (it != cal.end() && end <= it->second)) {
            cal.insert({end, start});
            return true;
        }
        return false;
    }
};
